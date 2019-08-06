#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int jobs_num = atoi(argv[1]);
  int jobs_len = atoi(argv[2]);
  int average_response = 0;

  for (int i = 0; i < jobs_num; i++)
  {
    average_response = average_response + i * jobs_len;
  }
  average_response = average_response / jobs_num;
  printf("Average response time of %d jobs at length of %d is: %d\n", jobs_num, jobs_len, average_response);
}