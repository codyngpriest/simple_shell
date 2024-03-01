
#include "simple_shell.h"

/**
* custom_getline - reads input character by character into a buffer
*
* Return: void
*/


char *custom_getline(void)
{
static char buffer[BUFFER_SIZE];
static int index;
int c;
char *line = NULL;

/* Read input until newline or EOF */
while ((c = getchar()) != EOF && c != '\n')
{
if (index < BUFFER_SIZE - 1)
{
buffer[index++] = c;
}
else
{
fprintf(stderr, "Buffer overflow\n");
exit(EXIT_FAILURE);
}
}

/* Check if input was received */
if (index > 0 || c == '\n')
{
buffer[index] = '\0';
line = strdup(buffer);
if (line == NULL)
{
fprintf(stderr, "Memory allocation error\n");
exit(EXIT_FAILURE);
}
index = 0;
}

return (line);
}

