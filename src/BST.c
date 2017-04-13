//
//  BST.c
//
//
//  Created by Loula Beck on 13/04/2017.
//
//

#include "BST.h"

int nbElement = 5;

static int BSTroot ;
static int BSTtree [5][1];
double tab_cout[5];
double cout[5][5];

node *BSTConstruit(int tab_racine[nbElement][nbElement],int i,int j) {
  printf("hello1" );
  node *Arbre;
  Arbre = CreateNode(tab_racine,i,j,NULL,NULL);
  if(i<tab_racine[i][j]-1){
    Arbre->fg=BSTConstruit(tab_racine,i,tab_racine[i][j]-1);
  }
  if(tab_racine[i][j]<j){
    Arbre->fd=BSTConstruit(tab_racine,tab_racine[i][j],j);
  }
  return Arbre;
}

node *CreateNode(int tab_racine[nbElement][nbElement],int i,int j,node *Fg ,node *Fd){
  printf("creation" );
  node *noeud;
  noeud->val = tab_racine[i][j];
  noeud->fg= NULL;
  noeud->fd = NULL;
  return noeud;
}

void printBST(node *Arbre)
{
    if(!Arbre) return;
    if(Arbre->fg)  printBST(Arbre->fg);
    printf("Cle = %d\n", Arbre->val);
    if(Arbre->fd) printBST(Arbre->fd);
}
/*void* (*e)(int i){
    assert(i>=0 && i<n);
}*/

double calculCout(int i, int j,double cout[nbElement][nbElement] ,int nbElement, double tab_cout[nbElement],double memoizationCout[nbElement][nbElement],int tab_racine[nbElement][nbElement]){
    double min = 999999.0;
    double val;
    int racine = -1;
    if(i==0 && j==0){
      return 0;
    }
    for (int l = 1; l <= j-i; l++) {
        for( int i_in = i; i_in <= nbElement - l ; i_in++){
          min = 999999.0;
            for(int k = i+1;k<=j;k++){
              if (memoizationCout[i_in][k-1] == 99999.0){
                memoizationCout[i_in][k-1] = calculCout(i_in,k-1,cout,nbElement,tab_cout,memoizationCout,tab_racine) ;
              }
              else if (memoizationCout[k][j] == 99999.0){
                memoizationCout[k][j] = calculCout(k,j,cout,nbElement,tab_cout,memoizationCout,tab_racine) ;
              }
              val = memoizationCout[i_in][k-1] + memoizationCout[k][j];
              if(val<min){
                    cout[i][j] = (tab_cout[j]-tab_cout[i]) + val;
                    tab_racine[i][j] = k;
                    min = val;

                }
            }
        }
    }
    return cout[i][j];
}

void initMemo(double memoizationCout[nbElement][nbElement],int nbElement){
  for(int i=0;i<nbElement;i++){
    for(int j=0;j<nbElement;j++){
      memoizationCout[i][j] = 99999.0;
    }
  }
}

void calculCoutInit(COUPLE tab[], double tab_cout[]){
    int i;
    double sum=0;
    for(int i=0;i<nbElement;i++){
        sum += tab[i].prob;
        tab_cout[i] = sum;
    }
}

int main (int argc, char *argv[]) {
  int i = 0;
  double memoizationCout[5][5];
  COUPLE tab[5];
  double result;
  int tab_racine[5][5];
  node *Arbre=NULL;
  tab[0].el = 1;
  tab[0].prob = 0.2;
  tab[1].el = 2;
  tab[1].prob = 0.5;
  tab[2].el = 5;
  tab[2].prob = 0.1;
  tab[3].el = 8;
  tab[3].prob = 0.1;
  tab[4].el = 9 ;
  tab[4].prob = 0.1;
  initMemo(memoizationCout,5);
  calculCoutInit(tab,tab_cout);
  result = calculCout(0,4,cout,5,tab_cout,memoizationCout,tab_racine);
  printf("%lf\n", result);
  printf("%d\n", tab_racine[0][4]);
  printf("Lancement construction\n" );
//  Arbre = BSTConstruit(tab_racine,0,4);
  printf("test\n" );
  printBST(Arbre);
}
