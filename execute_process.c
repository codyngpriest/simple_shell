#include "simple_shell.h"

/**
 * execute_process - Forks a new process and executes the command.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: void
 */
int execute_process(char **args)
{
/* Fork a new process */
pid_t pid = fork();

if (pid == 0)
{
/*---Child process---*/
if (execvp(args[0], args) == -1)
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
/* Fork failed */
perror("Error");
}
else
{
/*---Parent process---*/
int status;
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (0);
}

