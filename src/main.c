#include <stdio.h>
#include "../include/divideconquer.h"
#include "../include/greedy.h"
#include "../include/bsq.h"

int main()
{
  int arr[] = {0, 1, 2, 3, 5, 5, 6, 7, 8, 9, 10};
  int arrLength = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < arrLength; i++)
    printf("Found arr[%d] at %d\n", i, find_by_dichotomy(arr, 10, i));
  puts("---");

  Sack bp;
  ItemList list;

  initSack(&bp, 20);
  initItemList(&list);
  addObject(&list, 15, 3);
  addObject(&list, 10, 5);
  addObject(&list, 4, 4);
  addObject(&list, 10, 5);
  addObject(&list, 10, 2);
  addObject(&list, 2, 8);
  addObject(&list, 600, 30);
  addObject(&list, 10, 5);
  sortItemList(&list);
  fillSack(&bp, &list);

  puts("Sorted list");
  for (int i = 0; i < list.index; i++)
    printf("V=%d W=%d\n", list.items[i].V, list.items[i].W);

  puts("---");
  puts("Backpack items");
  for (int i = 0; i < bp.itemIndex; i++)
    printf("V=%d W=%d\n", bp.items[i].V, bp.items[i].W);

  printf("bp.currentWeight = %d\n", bp.currentWeight);
  printf("bp.maxWeight = %d\n", bp.maxWeight);
  printf("bp.itemIndex = %d\n", bp.itemIndex);
  puts("---");

  int L = 10;
  Square sq;

  int *randomMatrix = genMatrix(L);
  printMatrix(randomMatrix, L);
  maxSubSquare(randomMatrix, L, &sq);
  puts("---");
  printMaxSubSquare(randomMatrix, L, &sq);
  free(randomMatrix);
  return 0;
}