#include <stdlib.h>

#ifndef GREEDY_H
#define GREEDY_H

#define MAX_ITEMS 10

typedef struct
{
  int W;
  int V;
} Item;

typedef struct
{
  Item items[MAX_ITEMS];
  int index;
} ItemList;

typedef struct
{
  Item items[MAX_ITEMS];
  int maxWeight;
  int currentWeight;
  int itemIndex;
} Sack;

void initSack(Sack *bp, int maxWeight);
void initItemList(ItemList *il);
void addObject(ItemList *il, int value, int weight);

Item initObject(int value, int weight);

void sortItemList(ItemList *il);

void fillSack(Sack *bp, ItemList *il);
void addToSack(Sack *bp, Item item);

#endif