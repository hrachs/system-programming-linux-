#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	pid_t pid = getpid();
	pid_t ppid = getppid();

	printf("My pid = %d\n", pid);
	printf("My ppid = %d\n", ppid);

	while (1) {};
	return 0;
}
