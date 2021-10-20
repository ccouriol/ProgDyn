/*!
* \file divideconquer.c
* \author Clément Couriol
* \version 0.1
* \date 20/10/2021
* \brief 
* \remarks None
* 
* 
* 
*/

/*! Importation of librairies*/
#include "../include/divideconquer.h"

/*!
* \fn int find_by_dichotomy(int array[], size_t size, int value)
* \author Clément Couriol
* \version 0.1
* \date  20/10/2021
* \brief Returns the index of the value you want, -1 if not found
* \remarks None
* \param array 
* \param size 
* \param value 
* \return int
*/
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