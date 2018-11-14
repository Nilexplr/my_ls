/*
** EPITECH PROJECT, 2018
** find_total.c
** File description:
** total for -l
*/

#include "my_ls.h"

void disp_tot(files_t *list)
{
	int total = 0;

	for (inside_t* it = list->inside->next;
	     it != list->inside; it = it->next)
		if (it->info->d_name[0] != '.')
			total += it->file_stat->st_blocks;
	my_printf("total : %d\n", total / 2);
}
