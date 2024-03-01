#include "simple_shell.h"

/**
 * execute_arguments - Maps if a command is a builtin or a process.
 * @args: Command and its arguments.
 *
 * Return: 1 on success, 0 otherwise.
 */
int execute_arguments(char **args)
{
char *builtin_func_list[] = {
"cd",
"env",
"setenv",
"unsetenv",
"exit"
};
int (*builtin_func[])(char **) = {
&own_cd,
&own_env,
&own_setenv,
&own_unsetenv,
&own_exit
};
size_t i;

if (args[0] == NULL)
{
/* Empty command was entered */
return (1);
}

/* Find if the command is a builtin */
for (i = 0; i < sizeof(builtin_func_list) / sizeof(char *); i++)
{
/* If there is a match, execute the builtin command */
if (strcmp(args[0], builtin_func_list[i]) == 0)
{
return ((*builtin_func[i])(args));
}
}
/* Create a new process */
return (execute_process(args));
}

