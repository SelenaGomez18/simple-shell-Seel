#include "shell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
            else
        {
            perror("getline");
            free(line);
            exit(EXIT_FAILURE);
        }
    }

    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
    {
        line[len - 1] = '\0';
    }
    
    return (line);
}

char **split_line(char *line)
{
    size_t bufsize = 8;
    size_t position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = NULL;

    if (!tokens)
    {
        fprintf(stderr, "Error: without memory\n");
        exit(1);
    }

    token = strtok(line, " \t\r\n");
    while (token != NULL)
    {
        tokens[position++] = strdup(token);

        if (position >= bufsize)
        {
            bufsize *= 2;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens)
            {
                fprintf(stderr, "Error: without memory\n");
                exit(1);
            }
        }

        token = strtok(NULL, " ");
    }
    tokens[position] = NULL;
    return (tokens);
}

void free_tokens(char **tokens)
{
    size_t i = 0;

    for (; tokens[i] != NULL; i++)
        free(tokens[i]);
    free(tokens);
}
