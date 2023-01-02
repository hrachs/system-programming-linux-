#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t ret;
	pid_t child_pid;
	int wstatus;

	ret = fork();

	if (ret == -1)
	{
		perror("fork failed");
		exit(-1);
	}

	if (ret == 0)
	{
		printf("I'am a child\n");
		printf("My pid %d\n", getpid());
		printf("My ppid %d\n", getppid());
		exit(-15);
	}
	else
	{
		printf("I'am a parent\n");
		printf("My pid %d\n", getpid());
		printf("My ppid %d\n", getppid());

		child_pid = waitpid(-1, &wstatus, WNOHANG);
		if (child_pid == -1)
		{
			perror("wait failed");
			exit(-1);
		}

		if (!WIFEXITED(wstatus))
		{
			printf("child not exited\n");
			exit(0);
		}
		printf("child %d returned %d\n", child_pid, WEXITSTATUS(wstatus));
		exit(0);
	}
	return 0;
}
