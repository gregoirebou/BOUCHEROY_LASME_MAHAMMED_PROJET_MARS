//
// Created by grego on 24/10/2024.
//
#include <stdlib.h>
#include "tree.h"
#include "loc.h"
#include "moves.h"

t_tree createEmptyNTree()
{
    t_tree mytree;
    mytree.root = NULL;
    return mytree;

}

void Fill_Tree(t_tree *tree, int height, int nb_choices, int** costs, t_localisation loc_init, t_move* deplacements)
{
    fill_node(tree->root, height, nb_choices, costs, loc_init, deplacements);
}