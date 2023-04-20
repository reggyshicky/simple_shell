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
#include <sys/weight.h>
#include <sys/types.h>
extern char **environ;

int _putchar(char c);
int str_len(const char *s);
int prompt_print(const char *prmpt, size_t size);
char *get_env(char *globvar);
int find_fullpath(char **args);
int find_file(char *p_name);
void memfree(char *element);
int _exec(char **args);
int str_cmp(char *s1, char *s2);
int find_cmdinputs(char *element, char **args);
int exit_args(char **args, int exit_status);
void _gridfree(char **grid, int height);
char *str_dup(char *s);
int _errorstatus(int q);
char *cmd_append(char *path_dir, char *cmd);
int prnt_err(char **args, int tracker);

#endif /*SIMPLE_SHELL_H*/
