/*
** EPITECH PROJECT, 2018
** option_rmaj.c
** File description:
** R flag
*/

#include "my_ls.h"

char *str_to_path(char *path, char *str)
{
	char *dest = malloc(sizeof(char) *
			    (my_strlen(path) + my_strlen(str)) + 2);
	int i = 0;
	int j = 0;
	int save = 0;

	for (; i < my_strlen(path); i++)
		dest[i] = path[i];
	if (dest[i - 1] != '/') {
		dest[i] = '/';
		i++;
	}
	save = i;
	while (j < my_strlen(str)) {
		dest[i] = str[j];
		j++;
		i++;
	}
	dest[j + save] = '\0';
	return (dest);
}

void setup_rec(files_t *list)
{
	char *str;

	for (inside_t *it = list->inside->prev;
	     it != list->inside; it= it->prev)
		if ((it->info->d_type & DT_DIR) &&
		    it->info->d_name[0] != '.') {
			str = str_to_path(list->file, it->info->d_name);
			insert_rec(list, str);
		}
}
