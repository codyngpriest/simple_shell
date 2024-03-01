#include "simple_shell.h"

/**
 * tokenize - Tokenizes strings based on semicolons.
 * @line: The line to tokenize.
 * @tokens: The array to store the tokens.
 *
 * Return: void.
 */
void tokenize(const char *line, char **tokens)
{
char *line_copy = strdup(line);
char *token;
int token_count = 0;

if (line_copy == NULL || tokens == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}

printf("Input line: %s\n", line);

token = strtok(line_copy, ";");
while (token != NULL && token_count < MAX_TOKENS - 1)
{
tokens[token_count] = strdup(token);
if (tokens[token_count] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
printf("Token %d: %s\n", token_count, tokens[token_count]);
token_count++;
token = strtok(NULL, ";");
}
tokens[token_count] = NULL;

free(line_copy);
}

