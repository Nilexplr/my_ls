/*
** EPITECH PROJECT, 2018
** inside_folder.c
** File description:
** function for readding insing the folder
*/

#include "my_ls.h"

void my_readding(files_t *file)
{
	struct dirent *info;

	file->dir = opendir(file->file);
	if (file->dir == NULL) {
		my_printf("ls: cannot access '%s': %s\n",
			  file->file, strerror(errno));
		return;
	}
	while ((info = readdir(file->dir)) != NULL) {
		insert_inside(file->inside, info, file->file);
	}
}

void setup_display(files_t *list, int counter)
{
	static int disp = 0;

	if (list->dir == NULL)
		return;
	if (counter > 1){
		if (disp > 0)
			my_putchar('\n');
		my_putstr(list->file);
		my_putstr(":\n");
		disp++;
	}
}

void display_inside(files_t *list, int counter)
{
	setup_display(list, counter);
	for (inside_t *it = list->inside->next;
	     it != list->inside; it = it->next)
		if (it->info->d_name[0] != '.') {
			my_printf("%s\n", it->info->d_name);
		}
}

void write_l(inside_t *file)
{
	struct stat *file_stat = file->file_stat;

	S_ISDIR(file_stat->st_mode) != 0 ? my_putstr("d") : my_putstr("");
	S_ISREG(file_stat->st_mode) != 0 ? my_putstr("-") : my_putstr("");
	S_ISLNK(file_stat->st_mode) != 0 ? my_putstr("l") : my_putstr("");
	(file_stat->st_mode & S_IRUSR) != 0 ? my_putstr("r") : my_putstr("-");
	(file_stat->st_mode & S_IWUSR) != 0 ? my_putstr("w") : my_putstr("-");
	(file_stat->st_mode & S_IXUSR) != 0 ? my_putstr("x") : my_putstr("-");
	(file_stat->st_mode & S_IRGRP) != 0 ? my_putstr("r") : my_putstr("-");
	(file_stat->st_mode & S_IWGRP) != 0 ? my_putstr("w") : my_putstr("-");
	(file_stat->st_mode & S_IXGRP) != 0 ? my_putstr("x") : my_putstr("-");
	(file_stat->st_mode & S_IROTH) != 0 ? my_putstr("r") : my_putstr("-");
	(file_stat->st_mode & S_IWOTH) != 0 ? my_putstr("w") : my_putstr("-");
	(file_stat->st_mode & S_IXOTH) != 0 ? my_putstr("x") : my_putstr("-");
	my_printf(". %d ", file_stat->st_nlink);
	my_printf("%s\t", file->user->pw_name);
	my_printf("%s\t", file->groupe->gr_name);
	my_printf("%d\t", file_stat->st_size);
	my_printf("%s ", change_date(ctime(&file_stat->st_mtime)));
}

void display_l_flag(files_t *list, int counter)
{
	setup_display(list, counter);
	disp_tot(list);
	for (inside_t *it = list->inside->next;
	     it != list->inside; it = it->next)
		if (it->info->d_name[0] != '.') {
			write_l(it);
			my_printf("%s\n", it->info->d_name);
		}
}

