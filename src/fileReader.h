#ifndef fileReader_h
#define fileReader_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int NBEL;

typedef struct {
  int el;
  double prob;
} COUPLE;

int** tabInt(long n);
void swap(int a, int b);
//COUPLE* tabSort(long n, int** tabInt);


#endif
