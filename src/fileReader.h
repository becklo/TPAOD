#ifndef fileReader_h
#define fileReader_h
#define INFINITE 9999999;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int NBEL = 0;

typedef struct {
  int el;
  double prob;
} COUPLE;

int** tabInt(long n);
int indexMin(int n, int** tab);
void swap(int a, int b);
COUPLE* tabSort(long n, int** tabInt);


#endif
