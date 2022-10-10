#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	int rv = fork();

	if (rv == -1)
	{
		return -1;
	}
	else if (rv == 0)
	{
		close(STDOUT_FILENO);
		printf("child trying hello\n");
	}
	else
	{
		wait(NULL);
		printf("parent trying hello\n");
	}

	return 0;
}