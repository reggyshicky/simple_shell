#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct paths - structure for PATH variables
 * @dir: directory to search
 * @next: pointer to the next node
 */

typedef struct paths
{
	char *dir;
	struct paths *next;
} path_t;

int str_cmp(char *s1, char *s2);
char *str_dup(char *s);
char *rea_lloc(char *d);
int atois(char *s);
void list_free(path_t *h);
void tkn_free(char **token_array);
void control_c(int sig);
void control_d(char *lines);
int str_len(char *s);
char *str_concat(char *s1, char *s2);
char *con_cat(char *cat, char *s1, char *s2);
int tens_point(int k, char *m);
void free_everything(char *l, char *new_l, char **arr);
char *_printint(int number);
int change_dir(char **arr, char **env);
int _env(char **env);
int _exit(char **arr, char *l, char *new_l, int cmd_num);
int inbuilts(char **arr, char **env, char *l, char *new_l, int cmd_num);
void error_hand(char **argv, char **arr, int cmdnum, char *l, char *new_l);
char *pathhand(char *s, char **env);
char *get_env(const char *jina, char **env);
path_t *appendnode(char *s, path_t *lists);
path_t *develop_likedlist(char *s);
int _putchar(char c);
int exec_cmd(char **arr, char **env, char **v, char *l, char *new_l, int cmdn);
void printprompt(void);
char **str_tkn(char *l);

#endif /*SIMPLE_SHELL_H*/
