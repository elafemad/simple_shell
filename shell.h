#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdlib.h>


#define DELIM " \t\n"

#define PATH_MAX 1024

#define BUFFER_SIZE 1024


extern char **environ;



void print_string(char *str);
int execute_command(char **command, char **argv);
char *command_path(char *cmd);
int _getline(char **ptr_buf, size_t *size_buf, FILE *m);
char *read_input();
char **str_split(char *line);
char *_strdup(char *string);
int _strcmp(char *string1, char *string2);
int _strlen(char *str);
void _putchar(char c);
char *_getenv(char *n);
char *_strtok(char *str, const char *d);
void env_execute(void);
int _fgetc(FILE *m);
void exit_execute(char **command, int *status);
void setenv_execute(char **cmd);
void free_str(char **a);
char *_strcat(char *destination, char *source);
char *_strcpy(char *destination, char *source);
void cmd_zero_updt(char **cmd);
void unsetenv_execute(char **cmd);
void cd_execute(char **command);
int not_num(char *str);
char *_strchr(const char *str, int a);
int _strncmp(char *str1, char *str2, size_t n);
size_t _strspn(const char *str, const char *acc);
char *_strpbrk(const char *str, const char *z);
int handle_builtin_commands(char **command, int *status);
void print_char(char c);
void print_line(char *str);
#endif
