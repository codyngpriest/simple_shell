#include "simple_shell.h"

/**
* parse_input - parses an input
* @input: The input to parse
* @args: The arguments to parse
*
* Return: void
*/

void parse_input(char *input, char **args)
{
char *token;
int arg_count = 0;

token = strtok(input, " ");
while (token != NULL && arg_count < MAX_ARGS - 1)
{
if (token[0] == '"')
{
char *end_quote = strchr(token + 1, '"');
if (end_quote != NULL)
{
args[arg_count] = malloc(MAX_ARG_LENGTH);
if (args[arg_count] == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
strncpy(args[arg_count], token + 1, end_quote - token - 1);
args[arg_count][end_quote - token - 1] = '\0';
arg_count++;
}
}
else
{
args[arg_count] = strdup(token);
if (args[arg_count] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
arg_count++;
}
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
}

