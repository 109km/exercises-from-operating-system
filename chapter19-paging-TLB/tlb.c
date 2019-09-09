/*
 * Measure the size and cost of accessing a TLB
 */

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sched.h>

#define BASE_10 10
#define MS_PER_SEC 1000000

double run_trials(int page_size, int num_pages, int trials);

int main(int argc, char *argv[])
{
  long pages, trials;
  double total;
  int page_size;

  /* get number of pages and trials */
  if (argc != 3)
  {
    fprintf(stderr, "Usage: ./tlb <int: pages-to-touch> <int: trials>\n");
    exit(EXIT_FAILURE);
  }

  page_size = getpagesize();

  pages = strtol(argv[1], NULL, BASE_10);
  trials = strtol(argv[2], NULL, BASE_10);

  if (!pages || !trials)
  {
    fprintf(stderr, "Usage: ./tlb <int: pages-to-touch> <int: trials>\n");
    exit(EXIT_FAILURE);
  }

  /* perform experiments */
  total = run_trials(page_size, pages, trials);
  printf("pages=%ld\ttrials=%ld\ttotal time=%f\n", pages, trials, total);
  return 0;
}

/*
 * Measure the size and cost of accessing a TLB
 * @param page_size, the size of the system pages
 * @param num_pages, number of pages to touch per trial
 * @param trials, number times to loop through the pages
 * @return the average time to access a page
 */
double run_trials(int page_size, int num_pages, int trials)
{
  struct timeval start, end;
  uint64_t trial_time = 0;
  int tod1, tod2, elems, jump, i, j;
  int *arr, arr_size;

  /* initialise an array big enough to span num_pages */
  elems = (page_size * num_pages) / sizeof(int);
  arr = (int *)calloc(elems, sizeof(int));

  /* distance to next page */
  jump = page_size / sizeof(int);

  /* run trials */
  tod1 = gettimeofday(&start, NULL); // start time
  for (j = 0; j < trials; j++)
  {
    for (i = 0; i < num_pages * jump; i += jump)
    {
      arr[i] += 1; // page access
    }
  }
  tod2 = gettimeofday(&end, NULL); // end time
  if (tod1 == -1 || tod2 == -1)
  {
    fprintf(stderr, "failed benchmarking time\n");
    exit(EXIT_FAILURE);
  }
  trial_time = (end.tv_sec - start.tv_sec) * MS_PER_SEC + end.tv_usec - start.tv_usec;
  free(arr);
  // return trial_time;
  return trial_time / (double)(num_pages * trials);
}