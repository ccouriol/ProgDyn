#include <stdio.h>
#include "../include/divideconquer.h"

int main()
{
  int arr[] = {0, 1, 2, 3, 5, 5, 6, 7, 8, 9, 10};
  for (size_t i = 0; i < 11; i++)
  {
    int res = find_by_dichotomy(arr, 10, i);
    printf("res=%d\n", res);
  }

  return 0;
}