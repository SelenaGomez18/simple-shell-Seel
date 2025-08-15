#include "shell.h"

char *builtin_str[] = 
{
    "cd",
    "pwd",
    "exit"
};

int (*builtin_func[]) (char **) =
{
    &shell_cd,
    &shell_pwd,
    &shell_exit
};

int num_builtins(void)
{
    return sizeof(builtin_str) / sizeof(char *);
}

int execute(char **args)
{
    int i = 0;

    if (args[0] == NULL)
        return (1);
    
    for (; i < num_builtins(); i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            return (*builtin_func[i])(args);
        }
    }
    
    pid_t pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
            perror ("execvp");
        exit (EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }

    return (1); /*seguimos en la shell*/
}
