#include "../include/divideconquer.h"

int find_by_dichotomy(int array[], size_t size, int value)
{
  size_t high = array[size], low = array[0];

  while (low <= high)
  {
    size_t mid = low + (high - low) / 2;

    if (array[mid] == value)
      return mid;

    if (array[mid] < value)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}