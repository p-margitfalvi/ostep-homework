#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE* fptr = fopen("q2.txt", "w");
	int rv = fork();

	if (rv == -1)
	{
		return -1;
	}
	else if (rv == 0)
	{
		fprintf(fptr, "Child hello world\n");
	}
	else
	{
		fprintf(fptr, "Parent hello world\n");
	}

	return 0;
}