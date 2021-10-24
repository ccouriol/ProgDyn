#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  int i;
  int j;
  int width;
} Square;

int *genMatrix(int L);
void printMatrix(int *tab, int L);
int min(int a, int b, int c);
void maxSubSquare(int *tab, int L,Square *sq);
void printMaxSubSquare(int *tab, int L, Square *sq);

#endif