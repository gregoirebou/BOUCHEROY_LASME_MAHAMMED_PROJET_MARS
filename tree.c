//
// Created by grego on 24/10/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "loc.h"
#include "moves.h"
#include "queue.h"

t_tree createEmptyNTree()
{
    t_tree mytree;
    mytree.root = NULL;
    return mytree;

}

void Fill_Tree(t_tree* tree, int height, int nb_choices, int** costs, t_localisation loc_init, t_move* deplacements, int longeur, int largeur )
{
    tree->root = createNode(costs[loc_init.pos.y][loc_init.pos.x], nb_choices, 0);
    fill_node(tree->root, height, nb_choices, costs, loc_init, deplacements,longeur, largeur);
}

void display_tree(t_tree tree){
    t_queue_tab file;
    file = createEmptyQueue();
    enqueue_tab(&file, tree.root);
    printf("[");
    while(isQueueEmpty(file) == 0 ){
        if ( file.values[file.first]->nbSons != 0){
            for (int i = 0; i < file.values[file.first]->nbSons; i++){
                enqueue_tab(&file, file.values[file.first]->sons[i]);
            }
        }
        printf(" %d :",dequeue_tab(&file));
    }
    printf("]");
}

