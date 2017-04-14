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
#include "freqReader.h"

typedef struct
{
    int root;
    int **tree;
} BST ;

int nbElement;
void BSTConstruit(int i,int j, int racine, int nbElement, int **tab_racine,BST *cout);
void calculCoutInit(double tab[],double tab_cout[]);
BST *calculCout(double tab[],int nbElement, double tab_cout[]);



#endif /* BST_h */
