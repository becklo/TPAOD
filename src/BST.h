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
void calculCoutInit(COUPLE tab[],double tab_cout[]);
double calculCout(int i, int j,double cout[nbElement][nbElement] ,int nbElement, double tab[],double memoizationCout[nbElement][nbElement],int tab_racine[nbElement][nbElement]);

#endif /* BST_h */
