//
// Created by grego on 24/10/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "node.h"
#include "loc.h"
#include "moves.h"
#include "stack.h"
#define DEFAULT_COST 65535
#define DEFAULT_NB_SONS 30

t_node *createNode(int val, int nb_sons, int depth)
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->value = val;
    new_node->depth = depth;
    new_node->parent = NULL;
    new_node->nbSons = nb_sons;
    new_node->sons = (t_node **)malloc(nb_sons*sizeof(t_node *));
    for (int i=0; i <nb_sons; i++)
    {
        new_node->sons[i]=NULL;
    }
    return new_node;
}

t_move* remove_depl_from_tab(t_move* deplacements, t_move dep, int TL)
{
    // Création de la pile pour stocker les mouvements restants
    if (TL == 1) {
        if (deplacements[0] == dep) {
            free(deplacements);
            return NULL;
        }
        return deplacements;
    }
    t_stack_depl deplstack = createStackDepl(TL - 1);
    int removed = 0; // Indicateur pour vérifier si 'dep' a déjà été supprimé

    // Parcours du tableau
    for (int i = 0; i < TL; i++)
    {
        if (deplacements[i] == dep && !removed)
        {
            // Ignore cette occurrence de 'dep' une seule fois
            removed = 1;
            continue;
        }
        // Ajoute à la pile les autres mouvements
        pushDepl(&deplstack, deplacements[i]);
    }
    if (!removed)
        return deplacements;

    // Création du nouveau tableau contenant les mouvements restants
    t_move* new = (t_move*)malloc(sizeof(t_move) * (TL - 1));

    // Dépiler les éléments et les ajouter au tableau
    for (int j = TL - 2; j >= 0; j--)
    {
        new[j] = popDepl(&deplstack);
    }

    return new;
}




void fill_node(t_node* node, int depth, int nb_choices, int** costs, t_localisation loc, t_move* deplacements, int longeur, int largeur )
{
    node->depth = depth;
    node->nbSons = nb_choices;
    node->value = costs[loc.pos.y][loc.pos.x];

    for (int i = 0; i < nb_choices; i++)
    {
        t_move deplacement = deplacements[i];
        t_localisation new_loc = translate(loc, deplacement);

        if (new_loc.pos.x >= 0 && new_loc.pos.x <= largeur - 1 && new_loc.pos.y >= 0 && new_loc.pos.y <= longeur - 1) {
            t_move* new_deplacements = remove_depl_from_tab(deplacements, deplacement, nb_choices);

            if (costs[new_loc.pos.y][new_loc.pos.x] < 9999)
            {
                t_node* son = createNode(DEFAULT_COST, nb_choices - 1, depth + 1);

                son->parent = node;

                fill_node(son, son->depth, nb_choices - 1, costs, new_loc, new_deplacements, longeur, largeur);
                node->sons[i] = son;
            }
            free(new_deplacements);
        }
        else {
            node->sons[i] = NULL;
        }

    }
}

void display_node(t_node node)
{



}
