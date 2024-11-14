//
// Created by grego on 24/10/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "node.h"
#include "loc.h"
#include "moves.h"
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

t_move* remove2(t_move* deplacements, t_move dep, int TL)
{
    t_move* new = (t_move*)malloc(sizeof(t_move)*(TL - 1));
    int nb = 0;
    for (int i = 0; i < TL; i++)
    {
        if (dep != deplacements[i])
        {
            new[nb++] = deplacements[i];
        }
    }
    return new;
}


void fill_node(t_node* node, int depth, int nb_choices, int** costs, t_localisation loc, t_move* deplacements)
{
    node->depth = depth;
    node->nbSons = nb_choices;
    node->value = costs[loc.pos.x][loc.pos.y];

    for (int i = 0; i < nb_choices; i++)
    {
        t_move deplacement = deplacements[i];
        t_localisation new_loc = translate(loc, deplacement);

        t_move* new_deplacements = remove2(deplacements, deplacement, nb_choices);

        if (costs[new_loc.pos.x][new_loc.pos.y] < 9999)
        {
            t_node* son = createNode(DEFAULT_COST, DEFAULT_NB_SONS, depth + 1);
            fill_node(son, son->depth, nb_choices - 1, costs, new_loc, new_deplacements);

            node->sons[i] = son;
            node->nbSons++;
        }

        free(new_deplacements);
    }
}

void display_node(t_node node)
{



}