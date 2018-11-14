/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing function
*/
#include "my_ls.h"

int find_letter(char *str, char c)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return (1);
	return (0);
}

char *add_flag(char *total, char *flags)
{
	int i = 0;
	int j = 1;

	if (total == NULL) {
		total = malloc(sizeof(char) * 500);
		total[0] = '\0';
	}
	while (total[i] != '\0')
		i++;
	while (flags[j] != '\0') {
		total[i] = flags[j];
		i++;
		j++;
	}
	return (total);
}

void insert(files_t *list, char *file_name)
{
	files_t *new = malloc(sizeof(files_t));

	if (new != NULL) {
		new->file = file_name;
		new->prev = list->prev;
		new->next = list;
		list->prev->next = new;
		list->prev = new;
	}
}

void analyse_arg(int ac, char **argv)
{
	files_t *file_av = create_root(".");
	int counter = 0;

	for (int i = 1; i < ac; i++) {
		if (argv[i][0] == '-')
			file_av->flags = add_flag(file_av->flags, argv[i]);
		else {
			insert(file_av, argv[i]);
			counter++;
		}
	}
	if (file_av->flags != NULL) {
		inverse_file(file_av, file_av->flags);
		run_d(file_av, file_av->flags);
		watch_flag(file_av->flags);
	}
	display_flag(file_av, counter);
	display_flag_file(file_av, counter);
}
