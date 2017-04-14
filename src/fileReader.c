/*! \file fileReader.c
 *  \brief	   This implements the creation of reading of the benchmark
 *  \author    Quentin Rühl
 *  \version   1.0
 *  \date      12/04/2016
 *  \copyright GNU Public License.
 */
#include "fileReader.h"


/**
 * swap
 * \brief swap the values of the 2 integers given in entry
 * \param a integer
 * \param b integer
 */
void swap(int a, int b){
  int c;
  c=a;
  a=b;
  b=c;
}

/**
 * indexMin
 * \brief finds the minimum in a table
 * \param n the size of the table
 * \param tab 2D table
 * \returns the index of the minimum
 */
int indexMin(int n, int** tab){
  int i =0;
  int mini = tab[0][0];
  int index=0;

  for(i=1; i<n; i++){
    if(tab[i][0]< mini){
      mini = tab[i][0];
      index = i;
    }
  }
  return index;
}

/**
 * fTabInt
 * \brief reads the input File and stores the values and number of apparition in a 2D table
 * \param n number of values in the
 * \param inpFile string containing the path and name of the file to reads
 * \returns a 2D table
 */
static int** fTabInt(long n, char* inpFile){
  FILE* fileInt = NULL;
  int intR;
  int scan;
  int** tabInt = NULL;
  int i = 0;
  int j = 0;
  bool pass = false;
  n = (int) n;

  tabInt = calloc(n,sizeof(int*));
  for (i=0; i<n; i++){
    tabInt[i] = malloc(2*sizeof(int));
  }
  if(tabInt == NULL){
    perror("Table has not been created");
  }
  i = 0;
  for (i=0; i<n ; i++){
    tabInt[i][0] = -1;
    tabInt[i][1] = 0;
  }

  fileInt = fopen(inpFile,"r");
  if(fileInt == NULL){
    perror("File not opened");
  }

  while((scan = fscanf(fileInt, "%d",&intR))!=EOF && scan != 0){
    for(i=0; i<n; i++){
      if(intR == tabInt[i][0]){
        tabInt[i][1]++;
        pass = true;
        break;
      }
    }
    if(!pass){
      tabInt[j][0] = intR;
      tabInt[j][1]++;
      j++;
      pass = false;
    }
  }
  NBEL = j;
  fclose(fileInt);
  return tabInt;
}

/**
 * tabSort
 * \brief sorts the table returned by fTabInt and Calculates the probabilities to have each element
 * \param n number of values in the
 * \param inpFile string containing the path and name of the file to reads
 * \returns a COUPLE table sorted by values
 */
COUPLE* tabSort(long n, char* inpFile){
  COUPLE *tabSort = NULL;
  int iMin = 0;
  int i = 0;
  int** tabInt = NULL;

  tabInt = fTabInt(n,inpFile);

  tabSort = calloc(NBEL,sizeof(COUPLE));
  if(tabSort == NULL){
    perror("Table has not been created");
  }

  for(i=0; i<NBEL;i++){
    iMin = indexMin(NBEL, tabInt);
    tabSort[i].el = tabInt[iMin][0];
    tabSort[i].prob = ((double)(tabInt[iMin][1]))/((double)n);
    tabInt[iMin][0] = INFINITE;
  }

  return tabSort;
}



/*int main(int argc, char const *argv[]) {
  long n = 10;
  int i =0;
  int** testInt = NULL;
  COUPLE *testSort = NULL;
  double timeExec;
  clock_t tStart, tEnd;

  tStart = clock();
  testSort = tabSort(n,"test.txt");
  tEnd = clock();
  timeExec = (double) (tEnd - tStart)/CLOCKS_PER_SEC;
  printf("temps exec %lf\n", timeExec);

  return 0;
}*/
