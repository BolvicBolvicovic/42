#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int error(char *err) {
    write(2, err, strlen(err)); // Beware, strlen() is not allowed for the exam.
    return 1;
}

int cd(char **av, int i) {
    if (i != 2)
        return error("error: cd: bad arguments\n");
    else if (chdir(av[1]) == -1)
        return  error("error: cd: cannot change directory to "),
                error(av[1]),
                error("\n");
    return 0;
}

int exec(char **av, char **ev, int i) {
    int status;
    int fd[2];
    int has_pipe = av[i] && !strcmp(av[i], "|");

    if (has_pipe && pipe(fd) == -1)
        return error("error: fatal\n");
    int pid = fork();
    if (!pid) {
        av[i] = NULL;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
            return error("fatal\n");
        execve(*av, av, ev);
        return  error("error: cannot execute "),
                error(*av),
                error("\n");
    }
    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
        return error("fatal\n");
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **ev) {
    int status = 0;
    int i = 0;

    if (ac < 2)
        return status;
    while (av[i] && av[++i]) {
        av += i;
        i = 0;
        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
            i++;
        if (!strcmp(*av, "cd"))
            status = cd(av, i);
        else if (i)
            status = exec(av, ev, i);
    }
    return status;
}
