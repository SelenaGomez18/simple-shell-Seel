#include "shell.h"

int main(void)
{
    char *line = NULL;
    char **args = NULL;
    int status = 1; /*1 = seguir, 0 = salir*/

    do
    {
        printf("seel> ");
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free_tokens(args);
    } while (status); /* bucle infinito, repetimos hasta que status sea diferente de 0*/

    return (0);
}
