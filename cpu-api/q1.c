#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int x = 42;
	int rv = fork();

	if (rv == -1)
	{
		return -1;
	}
	else if (rv == 0)
	{
		printf("Child process value: %d\n", x);
		x = 100;
		printf("Child changing to 100: %d\n", x);
	}
	else
	{
		printf("Parent process value: %d\n", x);
		x = 69;
		printf("Parent changing to 69: %d\n", x);
	}

	return 0;
}