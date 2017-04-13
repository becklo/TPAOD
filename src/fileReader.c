#include "fileReader.h"


//Swap the values of two integers
void swap(int a, int b){
  int c;
  c=a;
  a=b;
  b=c;
}

//Function reading the file and returning a table filled with the integers and their prob
int** tabInt(long n){
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
    printf("Table has not been created");
    return EXIT_FAILURE;
  }
  i = 0;
  for (i=0; i<n ; i++){
    tabInt[i][0] = -1;
    tabInt[i][1] = 0;
  }


  fileInt = fopen("test.txt","r");
  if(fileInt == NULL){
    printf("File not opened");
    return EXIT_FAILURE;
  }

  while((scan = fscanf(fileInt, "%d",&intR))!=EOF && scan != 0){
    //printf("intR = %d\n", intR);
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
  return NULL;
}



int main(int argc, char const *argv[]) {
  /* code */
  long n = 5;
  int i =0;
  int** oui = NULL;

  oui = tabInt(n);
  for(i=0;i<n;i++){
    printf("tab1 = %d et tab2 = %d\n",oui[i][0],oui[i][1]);
  }

  return 0;
}