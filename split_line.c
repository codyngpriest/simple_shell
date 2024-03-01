#include "simple_shell.h"

/**
 * split_line - Splits a string into tokens
 * @line: The string to be split.
 * @delimiter: The delimiter character.
 *
 * Return: An array of tokens.
 */

char **split_line(char *line, const char *delimiter)
{
int bufsize = INITIAL_BUFFER_SIZE;
int position = 0;
char *token;
char **tokens = malloc(bufsize * sizeof(char *));

if (!tokens)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(line, delimiter);
while (token != NULL)
{
tokens[position] = strdup(token);
if (tokens[position] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
position++;

if (position >= bufsize)
{
bufsize += BUFFER_INCREMENT;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, delimiter);
}

tokens[position] = NULL;
return (tokens);
}

