/*
** EPITECH PROJECT, 2018
** option_r.c
** File description:
** reverse functions
*/

#include "my_ls.h"

void inverse_inside(inside_t *root)
{
	inside_t *save = malloc(sizeof(inside_t));

	save = root->next;
	root->next = root->prev;
	root->prev = save;
}

void inverse_file(files_t *root, char *flag_list)
{
	files_t *save;

	if (root->next != root && (find_letter(flag_list, 'r'))) {
		save = root->next;
		root->next = root->prev;
		root->prev = save;
		for (files_t *it = root->next; it != root; it = it->next) {
			save = it->next;
			it->next = it->prev;
			it->prev = save;
		}
	}
}
