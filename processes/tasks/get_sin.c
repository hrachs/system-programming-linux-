#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t ret;

	ret = fork();
	float alp = 3*M_PI/2;

	if (ret == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	if (ret == 0)
	{
		printf("sin(%f) = %f\n", alp, sin(alp));
		exit(EXIT_SUCCESS);
	}

	if (wait(NULL) < 0)
	{
		perror("wait failed");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
