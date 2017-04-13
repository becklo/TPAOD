#include "fileReader.h"


//Swap the values of two integers
void swap(int a, int b){
  int c;
  c=a;
  a=b;
  b=c;
}

//Calculates the minimum of a table 2D
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

//Function reading the file and returning a table filled with the integers and their prob
int** tabInt(long n, char* inpFile){
  FILE* fileInt = NULL;
  int intR;
  int scan;
  int** tabInt = NULL;
  int i = 0;
  int j = 0;
  bool pass = false;
  n = (int) n;

  printf("(OK)\n");
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

  printf("%s",inpFile);
  fileInt = fopen(inpFile,"r");
  if(fileInt == NULL){
    perror("File not opened");
  }

  while((scan = fscanf(fileInt, "%d",&intR))!=EOF && scan != 0){
    printf("intR = %d\n", intR);
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

  /*for(i=0;i<n;i++){
    printf("tab1 = %d et tab2 = %d\n",tabInt[i][0],tabInt[i][1]);
  }*/

  fclose(fileInt);
  return tabInt;
}

//Sort the tab given in entry
COUPLE* tabSort(long n, int** tabInt){
  COUPLE *tabSort = NULL;
  int iMin = 0;
  int i = 0;

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



int main(int argc, char const *argv[]) {
  /* code */
  long n = 10;
  int i =0;
  int** testInt = NULL;
  COUPLE *testSort = NULL;

  testInt = tabInt(n,"test.txt");
  for(i=0;i<n;i++){
    printf("tab1 = %d et tab2 = %d\n",testInt[i][0],testInt[i][1]);
  }

  printf("NBEL %d\n", NBEL);

  testSort = tabSort(n,testInt);
  for(i=0; i<NBEL; i++){
    printf("el %d prob %lf\n", testSort[i].el,testSort[i].prob);
  }


  return 0;
}
