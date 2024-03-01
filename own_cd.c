#include "simple_shell.h"
/**
 * own_cd - Changes the current directory of the process.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int own_cd(char **args)
{
char *new_dir;
if (args[1] == NULL || strcmp(args[1], "~") == 0)
{
/* If no argument or "~" is given, change directory to HOME */
new_dir = getenv("HOME");
}
else if (strcmp(args[1], "-") == 0)
{
/* If argument is "-", change directory to previous directory */
new_dir = getenv("OLDPWD");
if (new_dir == NULL)
{
fprintf(stderr, "No previous directory stored.\n");
return (-1);
}
printf("%s\n", new_dir);
}
else
{
/* Otherwise, change directory to the specified directory */
new_dir = args[1];
}
/* Change directory and update PWD environment variable */
if (chdir(new_dir) != 0)
{
perror("chdir");
return (-1);
}
else
{
/* Update the PWD environment variable with the current working directory */
if (setenv("PWD", getcwd(NULL, 0), 1) != 0)
{
perror("setenv");
return (-1);
}
}
return (0);
}

