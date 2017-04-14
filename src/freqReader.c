/*! \file fileReader.c
 *  \brief	   This implements the creation of reading of the benchmark
 *  \author    Quentin Rühl
 *  \version   1.0
 *  \date      12/04/2016
 *  \copyright GNU Public License.
 */
#include "freqReader.h"

 double *fTabProb(long n, char* inpFile){
   int i = 0;
   FILE* fileFreq = NULL;
   int intR;
   int *tabFreq = NULL;
   double *tabProb = NULL;
   int sumFreq = 0;
   int scan;

   tabFreq = calloc(n,sizeof(int));
   if(tabFreq == NULL){
     perror("Table has not been created");
   }
   tabProb = calloc(n,sizeof(double));
   if(tabProb == NULL){
     perror("Table has not been created");
   }
   for(i=0; i<n; i++){
     tabFreq[i] = 0;
     //tabProb[i] = 0;
   }
   fileFreq = fopen(inpFile,"r");
   if(fileFreq == NULL){
     perror("File not opened");
   }
   i = 0;
   while((scan = fscanf(fileFreq, "%d",&intR))!=EOF && scan != 0){

     tabFreq[i] = intR;
     sumFreq += intR;
     i++;
   }

   for(i=0; i<n; i++){
     tabProb[i] = (double) (tabFreq[i])/sumFreq;
   }

   return tabProb;
 }

 /*int main(int argc, char const *argv[]) {
   double *test = NULL;
   int n = 10;
   test = fTabProb(n,"test.txt");
   for(int i = 0; i<n; i++){
     printf("prob %lf\n",test[i]);
   }
 }*/
