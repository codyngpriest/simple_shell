#include "simple_shell.h"
/**
* interactive_state - A UNIX command line interpreter
*
* Return: void
*/
void interactive_state(void)
{
char *line, **args;
int status;
size_t bufsize = 0;
do {
printf(":) ");
if (getline(&line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
printf("\n");
break;
}
else
{
perror("read_line");
exit(EXIT_FAILURE);
}
}
if (line[strlen(line) - 1] == '\n')
line[strlen(line) - 1] = '\0';
if (line[0] == '\033')
{
fprintf(stderr, "./shell: No such file or directory\n");
free(line);
continue;
}
args = split_line(line, " ");
if (strstr(line, "|") != NULL)
{
status = execute_piped_command(args);
}
else
status = execute_arguments(args);
free(args);
} while (status != -1);
free(line);
}

