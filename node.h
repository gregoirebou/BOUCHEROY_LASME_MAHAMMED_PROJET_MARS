//
// Created by grego on 24/10/2024.
//

#ifndef BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_NODE_H
#define BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_NODE_H
#include "moves.h"
typedef struct s_node
{
    int value;
    int depth;
    struct s_node *parent;
    struct s_node **sons;
    int nbSons; // taille physique du tableau
} t_node;

t_move* remove2(t_move* deplacements, t_move dep, int TL);

void fill_node(t_node* node, int depth, int nb_choices, int** costs, t_localisation loc, t_move* deplacements, int longeur, int largeur);

t_node *createNode(int val, int nb_sons, int depth);

void display_node(t_node node);

#endif //BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_NODE_H
