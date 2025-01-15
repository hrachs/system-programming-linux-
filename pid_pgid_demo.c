#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t pgid = getpgid(0);
    pid_t pgrp = getpgrp();

    printf("Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", ppid);
    printf("Process Group ID (getpgid): %d\n", pgid);
    printf("Process Group ID (getpgrp): %d\n", pgrp);

    // sleep(10000);

    pid = fork();

    if (pid == -1)
    {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child: PID = %d, PGID = %d\n", getpid(), getpgid(0));

        if (setpgid(0, 0) == -1)
        {
            perror("Child: setpgid failed");
            exit(1);
        }

        printf("Child after setpgid: PID = %d, PGID = %d\n", getpid(), getpgid(0));
    }
    else
    {
        sleep(1);
        printf("Parent: PID = %d, Child PID = %d, PGID = %d\n", getpid(), pid, getpgid(pid));
        // getpgid returns - 1 becouse the child has already terminated
    }

    return 0;
}