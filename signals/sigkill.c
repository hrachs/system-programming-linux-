#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signum)
{
	printf("I will not die\n");
}

int main(int argc, char const *argv[])
{
	if (signal(SIGSTOP, sig_handler) == SIG_ERR)
	{
		perror("signal failed");
		exit(EXIT_FAILURE);
	}

	while(1) {};

	exit(EXIT_SUCCESS);
}