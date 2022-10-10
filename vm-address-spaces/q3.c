#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{

  if (argc != 2)
  {
    printf("Provide exactly 1 argument\n");
    return -1;
  }

  printf("PID: %d\n", getpid());
  
  int n_mb = atoi(argv[1]);
  int64_t n_bytes = n_mb*1024*1024;
  char* arr = malloc(n_bytes);

  while (1)
    for (int i = 0; i < n_bytes; ++i)
    {
      ++arr[i];
    }

  free(arr);

  return 0;
}
