#include <stdio.h>
#include "../include/divideconquer.h"
#include "../include/greedy.h"

int main()
{
  int arr[] = {0, 1, 2, 3, 5, 5, 6, 7, 8, 9, 10};
  for (size_t i = 0; i < 11; i++)
  {
    int res = find_by_dichotomy(arr, 10, i);
    printf("res=%d\n", res);
  }

  Sack bp;
  ItemList list;
  initSack(&bp, 20);
  initItemList(&list);
  addObject(&list, 600, 30); // skip car pas assez de place
  addObject(&list, 15, 3);   // 1
  addObject(&list, 10, 2);   // 2
  addObject(&list, 10, 5);   // 3
  addObject(&list, 10, 5);   // 4
  addObject(&list, 10, 5);   // 5 -> 20kg
  addObject(&list, 4, 4);    // non
  addObject(&list, 2, 8);    // non
  sortItemList(&list);
  fillSack(&bp, &list);

  for (int i = 0; i < list.index; i++)
    printf("V=%d W=%d\n", list.items[i].V, list.items[i].W);

  printf("itemlist index = %d\n", list.index);
  puts("---");

  for (int i = 0; i < bp.itemIndex; i++)
    printf("V=%d W=%d\n", bp.items[i].V, bp.items[i].W);

  printf("sack index = %d\n", bp.itemIndex);
  printf("sack W = %d\n", bp.currentWeight);

  return 0;
}