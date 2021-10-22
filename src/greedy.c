/*!
* \file greedy.c
* \author Clément Couriol
* \version 0.1
* \date 22/10/2021
* \brief 
* \remarks None
* 
* 
* 
*/

/*! Importation of librairies*/
#include "../include/greedy.h"

/*!
* \fn void initSack(Sack *bp, int maxWeight)
* \author Clément Couriol
* \version 0.1
* \date  22/10/2021
* \brief Set maxWeight & set currentWeight & itemIndex to 0
* \remarks None
* \param bp 
* \param maxWeight 
*/
void initSack(Sack *bp, int maxWeight)
{
  bp->maxWeight = maxWeight;
  bp->currentWeight = 0;
  bp->itemIndex = 0;
}

/*!
* \fn void initItemList(ItemList *il)
* \author Clément Couriol
* \version 0.1
* \date  22/10/2021
* \brief set index to 0
* \remarks None
* \param il 
*/
void initItemList(ItemList *il)
{
  il->index = 0;
}

/*!
* \fn void addObject(ItemList *il, int value, int weight)
* \author Clément Couriol
* \version 0.1
* \date  22/10/2021
* \brief add value and weight to itemlist with initObject()
* \remarks None
* \param il 
* \param value 
* \param weight 
*/
void addObject(ItemList *il, int value, int weight)
{
  il->items[il->index++] = initObject(value, weight);
}

/*!
* \fn Item initObject(int value, int weight)
* \author Clément Couriol
* \version 0.1
* \date  22/10/2021
* \brief set value & weight & return the item
* \remarks None
* \param value 
* \param weight 
* \return 
*/
Item initObject(int value, int weight)
{
  Item it;
  it.V = value;
  it.W = weight;
  return it;
}

/*!
* \fn void sortItemList(ItemList *il)
* \author Clément Couriol
* \version 0.1
* \date  22/10/2021
* \brief bubble sort items descendingly based on V/W ratio
* \remarks None
* \param il 
*/
void sortItemList(ItemList *il)
{
  int i, j;
  for (i = 0; i < il->index - 1; i++)
    for (j = 0; j < il->index - i - 1; j++)
      if ((double)(il->items[j].V / il->items[j].W) < (double)(il->items[j + 1].V / il->items[j + 1].W))
      {
        Item tmp = il->items[j];
        il->items[j] = il->items[j + 1];
        il->items[j + 1] = tmp;
      }
}

/*!
* \fn void fillSack(Sack *bp, ItemList *il)
* \author Clément Couriol
* \version 0.1
* \date  22/10/2021
* \brief fill sack from itemlist
* \remarks None
* \param bp 
* \param il 
*/
void fillSack(Sack *bp, ItemList *il)
{
  for (int i = 0; i < il->index; i++)
    addToSack(bp, il->items[i]);
}

/*!
* \fn void addToSack(Sack *bp, Item item)
* \author Clément Couriol
* \version 0.1
* \date  22/10/2021
* \brief add item to sack
* \remarks Makes sure bp.maxWeight isn't exceeded
* \param bp 
* \param item 
*/
void addToSack(Sack *bp, Item item)
{
  if (bp->currentWeight + item.W <= bp->maxWeight)
  {
    bp->items[bp->itemIndex] = item;
    bp->currentWeight += item.W;
    bp->itemIndex++;
  }
}
