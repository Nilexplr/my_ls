/*
** EPITECH PROJECT, 2018
** my_sort_word.c
** File description:
** my sort word function
*/

#include "my_ls.h"

void full_up_save(inside_t *a, save_t *new)
{
	if (new != NULL) {
		if (a->info != NULL)
			new->info = a->info;
		if (a->file_stat != NULL)
			new->file_stat = a->file_stat;
		if (a->user != NULL)
			new->user = a->user;
		if (a->groupe != NULL)
			new->groupe = a->groupe;
		new->date = a->date;
		new->nb_s = a->nb_s;
	}
}

save_t *init_save(inside_t *a)
{
	save_t *save = malloc(sizeof(save_t));

	save->info = malloc(sizeof(struct dirent));
	save->file_stat = malloc(sizeof(struct stat));
	save->user = malloc(sizeof(struct passwd));
	save->groupe = malloc(sizeof(struct group));
	save->date = malloc(sizeof(char) * 400);
	full_up_save(a, save);
	return (save);
}

void lswap(inside_t *a, inside_t* b)
{
	save_t *save = init_save(a);

	if (save != NULL) {
		a->info = b->info;
			a->user = b->user;
			a->groupe = b->groupe;
			a->date = b->date;
			a->nb_s = b->nb_s;
		b->info = save->info;
			b->user = save->user;
			b->groupe = save->groupe;
			b->date = save->date;
			b->nb_s = save->nb_s;
	}
}

int check_swap(char *first, char *sec)
{
	int i = 0;
	int j = 0;

	for (; first[i] != '\0' && sec[j] != '\0'; i++, j++) {
		if (first[i] > sec[j]) {
			return (1);
		}
		if (first[i] < sec[j])
			return (0);
	}
	return (0);
}

void sort_word(inside_t *a)
{
	int j = 0;

	for (inside_t *ct = a->next; ct != a; ct = ct->next)
		for (inside_t *it = a->next; it->next != a; it = it->next) {
			j = check_swap(my_strlowcase(it->info->d_name),
				       my_strlowcase(it->next->info->d_name));
			if (j == 1)
				lswap(it, it->next);
		}
}
