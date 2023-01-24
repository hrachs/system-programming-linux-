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
	unsigned int time_left = 0;
	if (signal(SIGINT, sig_handler) == SIG_ERR)
	{
		perror("signal failed");
		exit(EXIT_FAILURE);
	}

	time_left = sleep(100);
	printf("time left = %d\n", time_left);

	exit(EXIT_SUCCESS);
}