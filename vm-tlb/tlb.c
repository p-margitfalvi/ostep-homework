#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define PAGESIZE 4096
#define SEC_TO_uS 1000000 * 1L

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Arguments should be number of pages to touch and number of trials "
           "(in millions)"
           "to run\n");
    return -1;
  }

  int NUMPAGES = atoi(argv[1]);
  long NUMTRIALS = atol(argv[2]);

  printf("Running with numpages=%d and numtrials=%ldM\n", NUMPAGES, NUMTRIALS);
  NUMTRIALS *= 1000000;

  int jump = PAGESIZE / sizeof(uint8_t);
  int s = jump * NUMPAGES;
  printf("Allocating %d bytes\n", s);

  uint8_t *arr = malloc(s);

  for (int i = 0; i < s; ++i) {
    arr[i] = 0;
  }

  struct timeval t1, t2;

  if (gettimeofday(&t1, NULL) != 0) {
    printf("gettimeofday failed\n");
  }

  long m = NUMTRIALS;
  while (m--) {
    for (int i = 0; i < s; i += jump) {
      ++arr[i];
    }
  }

  if (gettimeofday(&t2, NULL) != 0) {
    printf("gettimeofday failed\n");
  }

  double dt =
      (double)((t2.tv_sec - t1.tv_sec) * SEC_TO_uS + t2.tv_usec - t1.tv_usec) /
      NUMPAGES * 1000 / NUMTRIALS;

  printf("Time taken to run %ld trials\n", NUMTRIALS);
  printf("%lf\n", dt);

  free(arr);

  return 0;
}
