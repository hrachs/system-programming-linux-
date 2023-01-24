#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigcont_handler(int signum)
{
	printf("Continue\n");
}

int main(int argc, char const *argv[])
{
	if (signal(SIGCONT, sigcont_handler) == SIG_ERR)
	{
		perror("signal failed");
		exit(EXIT_FAILURE);
	}

	while(1) {};

	exit(EXIT_SUCCESS);
}