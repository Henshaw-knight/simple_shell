#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **_strtok(char *str, char *delim);
void prompt(void);
char **getPath(char **env);
char *get_full_cmd(char *path, char *command);
void exec_cmd(char **tokens, char *absolute_path, char *shell, char **env);
void print_env(char **env);
void free_memory(char **buffer);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _isdigit(char *num);
int _atoi(char *s);
void exit_shell(char **args);

#endif
