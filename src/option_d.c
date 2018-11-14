/*
** EPITECH PROJECT, 2018
** option_d.c
** File description:
** option d functions
*/

#include "my_ls.h"

inside_t *find_inside(inside_t *root)
{
	for (inside_t *it = root->next; it != root; it = it->next)
		if (it->info->d_name[0] == '.' &&
		    it->info->d_name[1] == '\0')
			return (it);
	return (root);
}

void read_d(files_t *file, int mode)
{
	my_readding(file);
	if (file->dir != NULL){
		if (mode == 1)
			write_l(find_inside(file->inside));
		my_printf("%s\n", file->file);
	}
}

void display_ld(files_t *list)
{
	if (list->next == list) {
		list->inside = create_root_inside();
		read_d(list, 1);
	}
	for (files_t *it = list->next;
		     it != list; it = it->next) {
			it->inside = create_root_inside();
			read_d(it, 1);
	}
}

void display_just_d(files_t *list)
{
	if (list->next == list) {
		list->inside = create_root_inside();
		read_d(list, 0);
	}
	for (files_t *it = list->next;
		     it != list; it = it->next) {
			it->inside = create_root_inside();
			read_d(it, 0);
	}
}
