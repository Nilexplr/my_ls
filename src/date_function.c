/*
** EPITECH PROJECT, 2018
** date_function.c
** File description:
** function date
*/

#include "my_ls.h"

char *change_date(char *date)
{
	char *result = malloc(sizeof(char) * 20);
	int j = 0;

	if (date != NULL)
		for (int i = 4; i < my_strlen(date) - 9; i++) {
			result[j] = date[i];
			j++;
	}
	result[j] = '\0';
	return (result);
}
