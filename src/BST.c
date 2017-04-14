//
//  BST.c
//
//
//  Created by Loula Beck on 13/04/2017.
//
//

#include "BST.h"


BST *calculCout(double tab[],int nbElement, double tab_cout[]){
    double **memoizationCout;
    int **tab_racine;
    int min,racineMin;
    BST *cout=malloc(sizeof(*cout));
    cout->tree = calloc(nbElement,sizeof(*cout->tree));
    if (cout->tree == NULL){
      perror("memoire non allouee\n");
    }

    *(cout->tree) = calloc(nbElement*2,sizeof(int));
    if (*(cout->tree) == NULL){
      free(cout->tree);
      free(cout);
      perror("memoire non allouee\n");
    }

    //Creation du tableau de cout
    memoizationCout = calloc(nbElement,sizeof(*memoizationCout));
    *memoizationCout = calloc(nbElement,sizeof(**memoizationCout));

    //Creation du tableau de racine
    tab_racine = calloc(nbElement,sizeof(*tab_racine));
    *tab_racine = calloc(nbElement,sizeof(**tab_racine));
    //initialisation
    for(int i =1;i <nbElement;i++){
      cout->tree[i] = cout->tree[i-1] +2;
      memoizationCout[i] = memoizationCout[i-1]+nbElement;
      tab_racine[i] = tab_racine[i-1]+nbElement;

    }
    // initialisation des racines
    for(int i=0;i<nbElement;i++){
      for(int j=0;j<nbElement;j++){
        tab_racine[i][j]= -1;
      }
    }
    // valeur de la diagonale (limite)
    for(int i=0;i<nbElement;i++){
      memoizationCout[i][i] = tab[i];
      tab_racine[i][i] = i;
    }
    for (int l = 2; l <= nbElement; l++) {
       for( int i = 0; i <= nbElement - l +1; i++){
         int j = i + l -1;
         min = 10000;
           for(int k = i ;k<=j;k++){
             double CoutFg = 0;
             double CoutFd = 0;
             if (k>i){
               CoutFg = memoizationCout[i][k-1] ;
             }
             else if (k<j){
               CoutFd=memoizationCout[k][j];
             }
             if(CoutFg+CoutFd<min){
               racineMin=k;
               min = CoutFg+CoutFd;
             }
           }
           memoizationCout[i][j]=(tab_cout[j]-tab_cout[i])+min;
           tab_racine[i][j]= racineMin;
           printf("%d\n",tab_racine[i][j] );
         }
      }
      cout->root = tab_racine[0][nbElement-1];
      BSTConstruit(0,nbElement-1,nbElement,tab_racine[0][nbElement-1],tab_racine,cout);
      return cout;

}

void BSTConstruit(int i,int j, int racine, int nbElement, int **tab_racine,BST *cout){
  if (racine -1 > 0 ){
    cout->tree[racine][0] = tab_racine[i][racine-1];
  }
  else {
    cout->tree[racine][0] = -1;
  }
  if (racine +1 < nbElement){
    cout->tree[racine][1] = tab_racine[racine+1][j];
  }
  else {
    cout->tree[racine][1] = -1;
  }
  if ((racine-1 >0)&&tab_racine[i][racine-1]!=-1)  {
    BSTConstruit(i,racine-1,nbElement,tab_racine[i][racine-1],tab_racine,cout);
  }
  if ((racine+ 1 <nbElement)&&tab_racine[racine+1][j]!=-1)  {
    BSTConstruit(racine+1,j,nbElement,tab_racine[racine+1][j],tab_racine,cout);
  }
}

void calculCoutInit(double tab[], double tab_cout[]){
    double sum=0;
    for(int i=0;i<nbElement;i++){
        sum += tab[i];
        tab_cout[i] = sum;
    }
}
