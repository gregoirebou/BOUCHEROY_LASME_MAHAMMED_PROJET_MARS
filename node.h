//
// Created by grego on 24/10/2024.
//

#ifndef BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_NODE_H
#define BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_NODE_H

typedef struct s_node
{
    int value;
    int depth;
    struct s_node **sons;
    int nbSons; // taille physique du tableau
} t_node;

t_node *createNode(int val, int nb_sons, int depth);

#endif //BOUCHEROY_LASME_MAHAMMED_PROJET_MARS_NODE_H
