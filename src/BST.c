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
    node *Arbre=malloc(sizeof(node));
    if(Arbre == NULL){
      perror("arbre non aloué");
    }
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
    node *noeud=malloc(sizeof(int));
    if(noeud== NULL){
      perror("noeud non alloué");
    }
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

double calculCout(int i, int j,COUPLE tab[],int nbElement, double tab_cout[],double memoizationCout[nbElement][nbElement],int tab_racine[nbElement][nbElement]){
    double min;
    double val;
    int k_min;
    if((i==0 && j==0 )|| i==j){
      return 0;
    }
    for (int l = 1; l <= j-i; l++) {
        for( int i_in = i; i_in <= nbElement - l ; i_in++){
          int j_in=i_in+l;
          min = 1000000000;
            for(int k = i_in+1;k<=j_in;k++){
              if (memoizationCout[i_in][k-1] == 0){
                memoizationCout[i_in][k-1] = calculCout(i_in,k-1,tab,nbElement,tab_cout,memoizationCout,tab_racine) ;
              }
              else if (memoizationCout[k][j_in] == 0){
                memoizationCout[k][j_in] = calculCout(k,j_in,tab,nbElement,tab_cout,memoizationCout,tab_racine) ;
              }
              val = memoizationCout[i_in][k-1]+memoizationCout[k][j_in];
              if(val<min){
                min = val;
                k_min = k;
                }
            }
          tab_racine[i_in][j_in] = tab[k_min].el;
          memoizationCout[i_in][j_in]=(tab_cout[j_in]-tab_cout[i_in])+min;
        }
    }
    return memoizationCout[i][j];
}


void initMemo(double memoizationCout[nbElement][nbElement],int nbElement){
  for(int i=0;i<nbElement;i++){
    for(int j=0;j<nbElement;j++){
      memoizationCout[i][j] = 0;
    }
  }
}

void initTabRacine(int tab_racine[nbElement][nbElement],int nbElement,COUPLE tab[]){
  for(int i=0;i<nbElement;i++){
    for(int j=0;j<nbElement;j++){
      tab_racine[i][j]= tab[i].el;
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

/*void calculTabRacine(int tab_racine[nbElement][nbElement],int tab_racine_cal[],int nbElement){
  bool presence = false;
  for(int i=0;i<nbElement;i++){
    for(int j=0;j<nbElement;j++){
        presence = false;
        for(int k = 0 ; k<nbElement;k++){
          if(tab_racine_cal[k]==tab_racine[i][j]){
            presence = true;
          }
        }
        if(!presence){
          tab_racine_cal[i]=tab_racine[i][j];
        }
      }
    }
  }
*/

int main (int argc, char *argv[]) {
  int i = 0;
  double memoizationCout[5][5];
  COUPLE tab[5];
  double result;
  int tab_racine[5][5];
  int tab_racine_cal[5] = {-1};
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
  initTabRacine(tab_racine,5,tab);
  calculCoutInit(tab,tab_cout);
  result = calculCout(0,4,tab,5,tab_cout,memoizationCout,tab_racine);
  printf("%lf\n", result);
  //calculTabRacine(tab_racine,tab_racine_cal,5);
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      printf("%d\n",tab_racine[i][j] );
    }
  }
  Arbre = BSTConstruit(tab_racine,0,4);
  //printBST(Arbre);
}
