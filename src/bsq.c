/*!
* \file bsq.c
* \author Clément Couriol
* \version 0.1
* \date 24/10/2021
* \brief 
* \remarks None
* 
* 
* 
*/

/*! Importation of librairies*/
#include "../include/bsq.h"

/*!
* \fn int *genMatrix(int L)
* \author Clément Couriol
* \version 0.1
* \date  24/10/2021
* \brief Generate a matrix with random 0 & 1 values
* \remarks None
* \param L 
* \return 
*/
int *genMatrix(int L)
{
  int *matrix = (int *)malloc(sizeof(int) * L * L);

  srand(time(NULL));
  for (int i = 0; i < L; i++)
    for (int j = 0; j < L; j++)
      matrix[i * L + j] = rand() % 2;

  return matrix;
}

/*!
* \fn void printMatrix(int *tab, int L)
* \author Clément Couriol
* \version 0.1
* \date  24/10/2021
* \brief Print the given matrix with * for 1 and space for 0
* \remarks None
* \param tab 
* \param L 
*/
void printMatrix(int *tab, int L)
{
  for (int i = 0; i < L; i++)
  {
    for (int j = 0; j < L; j++)
      tab[i * L + j] == 1 ? write(1, "*", 1) : write(1, " ", 1);
    puts("|");
  }
}

/*!
* \fn int min(int a, int b, int c)
* \author Clément Couriol
* \version 0.1
* \date  24/10/2021
* \brief return the minimum value between a b c
* \remarks None
* \param a 
* \param b 
* \param c 
* \return 
*/
int min(int a, int b, int c)
{
  int m = a;

  if (m > b)
    m = b;
  if (m > c)
    m = c;

  return m;
}

/*!
* \fn void maxSubSquare(int *tab, int L, Square *sq)
* \author Clément Couriol
* \version 0.1
* \date  24/10/2021
* \brief find the coords & size of the biggest sub square
* \remarks None
* \param tab 
* \param L 
* \param sq 
*/
void maxSubSquare(int *tab, int L, Square *sq)
{
  int i, j;
  int S[L][L];

  // Set first column & row of S[][]
  for (i = 0; i < L; i++)
  {
    S[i][0] = tab[i * L];
    S[0][i] = tab[i];
  }

  // Construct other entries of S[][]
  for (i = 1; i < L; i++)
    for (j = 1; j < L; j++)
    {
      if (tab[i * L + j] == 0)
        S[i][j] = min(S[i][j - 1], S[i - 1][j], S[i - 1][j - 1]) + 1;
      else
        S[i][j] = 1;
    }

  // Find the maximum entry, and indexes of maximum entry in S[][]
  sq->width = S[0][0];
  sq->i = 0;
  sq->j = 0;
  for (i = 0; i < L; i++)
    for (j = 0; j < L; j++)
    {
      if (sq->width < S[i][j])
      {
        sq->width = S[i][j] - 1;
        sq->i = i;
        sq->j = j;
      }
    }
}

/*!
* \fn void printMaxSubSquare(int *tab, int L, Square *sq)
* \author Clément Couriol
* \version 0.1
* \date  24/10/2021
* \brief Print the matrix with * for 1 space for 0 and # for the biggest sub square
* \remarks None
* \param tab 
* \param L 
* \param sq 
*/
void printMaxSubSquare(int *tab, int L, Square *sq)
{
  for (int i = 0; i < L; i++)
  {
    for (int j = 0; j < L; j++)
    {
      if ((i <= sq->i && i > sq->i - sq->width) && (j <= sq->j && j > sq->j - sq->width))
        write(1, "#", 1);
      else
        tab[i * L + j] == 1 ? write(1, "*", 1) : write(1, " ", 1);
    }
    puts("|");
  }
}