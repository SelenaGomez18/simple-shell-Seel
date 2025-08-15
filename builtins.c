#include "shell.h"

/*built-in cambiar de directorio*/
int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "cd: arguemnt missing\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
        }
    }
    return (1); /*continuar ejecución*/
}

/*built in mostrar directorio actual*/
int shell_pwd(char **args)
{
    (void)args;

    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("pwd");
    }
    return (1);
}

/*built-in salir*/
int shell_exit (char **args)
{
    (void)args;
    
    return (0); /*señal para terminar el bucle principal*/
}
