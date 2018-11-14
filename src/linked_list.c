/*
** EPITECH PROJECT, 2018
** linked_list.c
** File description:
** linked list functions
*/

#include "my_ls.h"

files_t *create_root(char *s)
{
	files_t *root = malloc(sizeof(files_t));
	if (root != NULL) {
		root->file = s;
		root->flags = NULL;
		root->prev = root;
		root->next = root;
	}
	return (root);
}

void insert_rec(files_t *list, char *file_name)
{
	files_t *new = malloc(sizeof(files_t));

	if (new != NULL) {
		new->file = file_name;
		new->prev = list;
		new->next = list->next;
		list->next->prev = new;
		list->next = new;
	}
}

inside_t *create_root_inside(void)
{
	inside_t *root = malloc(sizeof(inside_t));

	if (root != NULL) {
		root->prev = root;
		root->next = root;
	}
	return (root);
}

void insert_inside(inside_t *inside, struct dirent *info, char *path)
{
	inside_t *new = malloc(sizeof(inside_t));
	char *str;

	if (new != NULL) {
		new->info = info;
		new->file_stat = malloc(sizeof(struct stat));
		str = str_to_path(path, new->info->d_name);
		if (stat(str, new->file_stat) != -1) {
			new->user = getpwuid(new->file_stat->st_uid);
			new->groupe = getgrgid(new->file_stat->st_gid);
			new->date = ctime(&(new->file_stat->st_mtime));
			new->nb_s = time(&(new->file_stat->st_mtime));
		}
		new->prev = inside->prev;
		new->next = inside;
		inside->prev->next = new;
		inside->prev = new;
	}
}
