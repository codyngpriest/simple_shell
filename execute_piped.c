#include "simple_shell.h"
/**
 * execute_piped_command - Executes a command received through a pipe.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: 1 on success, 0 otherwise.
 */
int execute_piped_command(char **args)
{
/* Fork a child process */
pid_t pid = fork();
/* Create a pipe */
int pipefd[2];
if (pipe(pipefd) == -1)
{
perror("pipe");
return (0);
}
if (pid < 0)
{
perror("fork");
return (0);
}
else if (pid == 0)
{
/*---Child process---*/
/* Redirect stdout to the write end of the pipe */
dup2(pipefd[1], STDOUT_FILENO);
/* Close the unused end of the pipe */
close(pipefd[0]);
close(pipefd[1]);
/* Execute the command */
if (execvp(args[0], args) == -1)
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else
{
/*---Parent process---*/
dup2(pipefd[0], STDIN_FILENO);
close(pipefd[0]);
close(pipefd[1]);
wait(NULL);
}
return (1);
}


