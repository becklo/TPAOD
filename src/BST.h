//
//  BST.h
//
//
//  Created by Loula Beck on 13/04/2017.
//
//

#ifndef BST_h
#define BST_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include "fileReader.h"

typedef struct node
{
    unsigned int val;
    struct node *fg;
    struct node *fd;
} node ;

int nbElement;
node *BSTConstruit(int tab_racine[nbElement][nbElement],int i,int j);
node *CreateNode(int tab_racine[nbElement][nbElement],int i , int j ,node *Fg ,node *Fd);
void printBST(node *Arbre);
void initTabRacine(int tab_racine[nbElement][nbElement],int nbElement);
void initMemo(double memoizationCout[nbElement][nbElement],int nbElement);
void calculCoutInit(COUPLE tab[],double tab_cout[]);
double calculCout(int i, int j,COUPLE tab[],int nbElement, double tab_cout[],double memoizationCout[nbElement][nbElement],int tab_racine[nbElement][nbElement]);
void calculTabRacine(int tab_racine[nbElement][nbElement],int tab_racine_cal[],int nbElement);

#endif /* BST_h */
