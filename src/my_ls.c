/*
** EPITECH PROJECT, 2017
** My ls
** File description:
** ls command
*/

#include <dirent.h>
#include "my_ls.h"

void my_ls(char *file)
{
	DIR *dir = opendir(file);
	struct dirent *info;

	while ((info = readdir(dir)) != NULL) {
		if (info->d_name[0] != '.')
			my_printf("%s\n", info->d_name);
	}
	closedir(dir);
}

int main(int ac, char **argv)
{
	if (ac == 1)
	{
		my_ls(".");
	}
	if (ac >= 2)
		analyse_arg(ac, argv);
	return (0);
}
