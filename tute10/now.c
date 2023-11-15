#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

// extern means the variable is defined somewhere else.
// In this case, the variable is defined by the system environment.
extern char **environ;

void spawn_and_wait(char **args) {
    pid_t pid;
    int status = posix_spawn(&pid, args[0], NULL, NULL, args, environ);

    if (status != 0) {
        errno = status;
        perror("spawn");
        exit(1);
    }

    int exit_stat;
    if (waitpid(pid, &exit_stat, 0) == -1) {
        perror("waitpid");
        exit(1);
    }

    printf("exited with status %d\n", WEXITSTATUS(exit_stat));
}

int main(int argc, char *argv[]) {
    // The current date.
    char *date_arg[] = {"/bin/date", "+%d-%m-%Y", NULL};
    spawn_and_wait(date_arg);

    // The current time.
    char *time_arg[] = {"/bin/date", "+%T", NULL};
    spawn_and_wait(time_arg);

    // The current user.
    char *usr_arg[] = {"/usr/bin/whoami", NULL};
    spawn_and_wait(usr_arg);

    // The current hostname.
    char *host_arg[] = {"/bin/hostname", "-f",NULL};
    spawn_and_wait(host_arg);

    // The current working directory.
    char *cwd_arg[] = {"/usr/bin/realpath", ".", NULL};
    spawn_and_wait(cwd_arg);
}