#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	char sent_str[] = "Child #2 writing to pipe\n";
	int pipefds[2];
	if (pipe(pipefds) == -1)
	{
		return -1;
	}

	int rv = fork();

	if (rv == -1)
	{
		return -1;
	}
	else if (rv == 0)
	{
		int rv = fork();
		if (rv == -1)
		{
			return -2;
		}
		else if (rv == 0)
		{
			printf("%s", sent_str);
			write(pipefds[1], sent_str, sizeof(sent_str));
		}
		else
		{
			wait(NULL);
			char out[sizeof(sent_str) + 100];
			read(pipefds[0], out, sizeof(sent_str) + 100);

			printf("Child #1 read: ");
			printf("%s", out);
		}
	}
	else
	{
		wait(NULL);
		printf("Parent exiting\n");
	}

	return 0;
}