/*
** EPITECH PROJECT, 2018
** my_ls.h
** File description:
** prototype for my ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <getopt.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

typedef struct save_s {
	struct stat *file_stat;
	struct dirent *info;
	struct passwd *user;
	struct group *groupe;
	char *date;
	time_t nb_s;
}save_t;

typedef struct inside_file_s {
	struct dirent *info;
	struct stat *file_stat;
	struct passwd *user;
	struct group *groupe;
	char *date;
	time_t nb_s;
	struct save_s *save;
	struct inside_file_s *prev;
	struct inside_file_s *next;
}inside_t;

typedef struct files_s {
	char *file;
	char *flags;
	DIR *dir;
	time_t nb_s;
	struct inside_file_s *inside;
	struct files_s *prev;
	struct files_s *next;
}files_t;

void analyse_arg(int ac, char **argv);
files_t *create_root(char *s);
void display_inside(files_t *inside, int counter);
void my_readding(files_t *file);
void insert_inside(inside_t *inside, struct dirent *info, char *path);
inside_t *create_root_inside(void);
void run_r(files_t *file, char *flag_list);
void run_d(files_t *file, char *flag_list);
void run_t(files_t *file, char *flag_list);
int run_rm(files_t *file, char *flag_list);
void run_l(files_t *file, char *flag_list, int counter);
int find_letter(char * str, char c);
void insert_rec(files_t *list, char *file_name);
void setup_rec(files_t *list);
void display_flag(files_t *list, int counter);
void display_flag_file(files_t *list, int counter);
void watch_flag(char *flag_list);
void display_l_flag(files_t *list, int counter);
char *str_to_path(char *path, char *str);
char *change_date(char *date);
void disp_tot(files_t *list);
void sort_word(inside_t *la);
int check_swap(char *first, char *sec);
void inverse_inside(inside_t *root);
void inverse_file(files_t *root, char *flag_list);
void display_just_d(files_t *list);
void display_ld(files_t *list);
void write_l(inside_t *file);

#endif /* MY_LS_H_ */
