/*
** EPITECH PROJECT, 2018
** display_flag.c
** File description:
** display flag function
*/

#include "my_ls.h"

int select_flag(files_t *list, char *flag_list, int counter)
{
	int i = 0;

	if (flag_list == NULL) {
		display_inside(list, counter);
		return (0);
	}
	run_r(list, flag_list);
	i = run_rm(list, flag_list);
	run_l(list, flag_list, counter + i);
	return (i);
}

void display_flag(files_t *list, int counter)
{
	if (list->next == list) {
		list->inside = create_root_inside();
		my_readding(list);
		select_flag(list, list->flags, counter);
	}
}

void display_flag_file(files_t *list, int counter)
{
	if (list->next != list)
		for (files_t *it = list->next;
		     it != list; it = it->next) {
			it->inside = create_root_inside();
			my_readding(it);
			select_flag(it, list->flags, counter);
		}
}

void watch_flag(char *flag_list)
{
	char flag[5] = "Rdtlr";
	int count = 0;

	for (int i = 0; flag_list[i] != '\0'; i++) {
		count = 0;
		for (int j = 0; flag[j] != '\0'; j++)
			count += (flag_list[i] != flag[j]) ? 1 : 0;
		if (count != 5)
			exit(84);
	}
}
