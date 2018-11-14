/*
** EPITECH PROJECT, 2018
** run_flag.c
** File description:
** run flag functions
*/

#include "my_ls.h"

void run_d(files_t *file, char *flag_list)
{
	if ((find_letter(flag_list, 'd'))) {
		if ((find_letter(flag_list, 'l')))
			display_ld(file);
		else
			display_just_d(file);
		exit(0);
	}
}

void run_t(files_t *file, char *flag_list)
{
	if ((find_letter(flag_list, 't'))) {
		file = file;
	}
}

void run_r(files_t *file, char *flag_list)
{
	if ((find_letter(flag_list, 'r'))) {
		inverse_inside(file->inside);
		for (inside_t *it = file->inside->prev; it != file->inside;
		     it = it->prev)
			inverse_inside(it);
	}
}

int run_rm(files_t *file, char *flag_list)
{
	if ((find_letter(flag_list, 'R'))) {
		setup_rec(file);
		return (2);
	}
	return (0);
}

void run_l(files_t *file, char *flag_list, int counter)
{
	if ((find_letter(flag_list, 'l')))
		display_l_flag(file, counter);
	else
		display_inside(file, counter);
}
