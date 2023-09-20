#ifndef MAIN_H
#define MAIN_H

#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

void signal_handler(int signum);
char **_strtok(char *str, char *delim);
void prompt(void);
char **getPath(char **env);
char *get_full_cmd(char *path, char *command);
void child_process(char **tokens, char *absolute_path,
		char *shell, char **env);
int change_dir(const char *path);
void exec_cmd(char **tokens, char *absolute_path, char *shell, char **env);
void print_env(char **env);
void free_memory(char **buffer);
int _strlen(char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, char *s2);
int _isdigit(char *num);
int _atoi(char *s);
void error_message(char **tokens, char *full_path, char *shell, size_t count);
void exit_shell(char **args, char *shell, size_t count);
void _EOF(char *buf);

#endif
