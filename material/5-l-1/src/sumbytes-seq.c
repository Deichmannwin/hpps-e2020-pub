#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "util.h"

int compute_sum(long size, unsigned char *bytes) {
  int res = 0;
  for (long i = 0; i < size; i++) {
    res += bytes[i];
  }
  return res;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <infile>\n", argv[0]);
    exit(1);
  }

  const char *fname = argv[1];

  double file_bef = seconds();
  long size;
  unsigned char *bytes = read_file(fname, &size);
  assert(bytes != NULL);
  double file_aft = seconds();

  printf("I/O: %fs\n", file_aft-file_bef);

  double sum_bef = seconds();
  int sum = compute_sum(size, bytes);
  double sum_aft = seconds();

  printf("Summing: %fs\n", sum_aft-sum_bef);
  printf("Result: %d\n", sum);

  free(bytes);
}
