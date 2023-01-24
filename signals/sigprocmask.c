#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler(int signum)
{
	printf("I will not die\n");
}

int main(int argc, char const *argv[])
{
	sigset_t set;

	if (signal(SIGINT, sig_handler) == SIG_ERR)
	{
		perror("signal failed");
		exit(EXIT_FAILURE);
	}

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, NULL);

	sleep(15);
	printf("signal %d unblocked\n", SIGINT);

	sigprocmask(SIG_UNBLOCK, &set, NULL);

	exit(EXIT_SUCCESS);
}