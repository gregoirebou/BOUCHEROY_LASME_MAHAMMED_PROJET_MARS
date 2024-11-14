//
// Created by grego on 24/10/2024.
//

#ifndef BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_TREE_H
#define BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_TREE_H
#include "node.h"

typedef struct s_tree
{
    t_node *root;
}t_tree;

t_tree createEmptyNTree();
void Fill_Tree(t_tree *tree, int height, int nb_choices, int** costs, t_localisation loc_init, t_move* deplacements);
#endif //BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_TREE_H
