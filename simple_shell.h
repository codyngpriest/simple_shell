#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


/*---Macros---*/
#define TOK_DELIM " \t\r\n\a"
#define INITIAL_BUFFER_SIZE 64
#define BUFFER_INCREMENT 64
#define BUFFER_SIZE 1024

#define MAX_ARGS 64
#define MAX_ARG_LENGTH 256

#define MAX_TOKENS 64
#define MAX_TOKEN_LENGTH 32

extern char **environ;


/*---PROTOTYPES---*/
/* main.c */
void interactive_state(void);

/* interactive_state.c */
char *read_line(void);
char **split_line(char *line, const char *delimiter);
int execute_arguments(char **args);
int execute_piped_command(char **args);
int execute_process(char **args);
void parse_input(char *input, char **args);
void execute_semicolon_commands(char *line);
void execute_single_command(char *command);
void tokenize(const char *line, char **tokens);

/*---Custom_getline.c---*/
char *custom_getline(void);

/*---Builtin func---*/
int own_env(char **args);
int own_setenv(char **args);
int own_unsetenv(char **args);
int own_exit(char **args);
int own_cd(char **args);

#endif
