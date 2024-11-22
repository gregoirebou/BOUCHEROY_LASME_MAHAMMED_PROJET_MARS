//
// Created by flasque on 19/10/2024.
//

#include "moves.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

/* prototypes of local functions */
/* local functions are used only in this file, as helper functions */

/**
 * @brief Function to rotate the robot according to a move and its actual orientation
 * @param ori : the actual orientation of the robot
 * @param move : the move to do
 * @return the new orientation of the robot
 */
t_orientation rotate(t_orientation, t_move );

/**
 * @brief function to translate the robot according to a move and its actual position
 * @param loc : the actual localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation translate(t_localisation , t_move);

/* definition of local functions */

t_orientation rotate(t_orientation ori, t_move move)
{
    int rst;
    switch (move)
    {
        case T_LEFT:
            rst=3;
            break;
        case T_RIGHT:
            rst=1;
            break;
        case U_TURN:
            rst=2;
            break;
        default:
            break;
    }
    return (ori+rst)%4;
}

t_localisation translate(t_localisation loc, t_move move)
{
    /** rules for coordinates:
     *  - x grows to the right with step of +1
     *  - y grows to the bottom with step of +1
     *  - the origin (x=0, y=0) is at the top left corner
     */
    t_position res = loc.pos;
    switch (move) {
        case F_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 1;
                    break;
                case EAST:
                    res.x = loc.pos.x + 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 1;
                    break;
                case WEST:
                    res.x = loc.pos.x - 1;
                    break;
                default:
                    break;
            }
            break;
        case F_20:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 2;
                    break;
                case EAST:
                    res.x = loc.pos.x + 2;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 2;
                    break;
                case WEST:
                    res.x = loc.pos.x - 2;
                    break;
                default:
                    break;
            }
            break;
        case F_30:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 3;
                    break;
                case EAST:
                    res.x = loc.pos.x + 3;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 3;
                    break;
                case WEST:
                    res.x = loc.pos.x - 3;
                    break;
                default:
                    break;
            }
            break;
        case B_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y + 1;
                    break;
                case EAST:
                    res.x = loc.pos.x - 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y - 1;
                    break;
                case WEST:
                    res.x = loc.pos.x + 1;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
        return loc_init(res.x, res.y, loc.ori);

}

/* definitions of exported functions */

char *getMoveAsString(t_move move)
{
    return _moves[move];
}

t_localisation move(t_localisation loc, t_move move)
{
    t_localisation new_loc;
    new_loc.ori = rotate(loc.ori, move);
    new_loc = translate(loc, move);
    return new_loc;
}

void updateLocalisation(t_localisation *p_loc, t_move m)
{
    *p_loc = move(*p_loc, m);
    return;
}

/**
 * @brief Fonction pour générer un tableau de k mouvements aléatoires parmi n mouvements disponibles.
 * @param n_moves : tableau des n mouvements possibles
 * @param n : taille du tableau n_moves
 * @param k : nombre de mouvements à sélectionner
 * @return pointeur vers un tableau dynamique contenant k mouvements sélectionnés
 */
t_move* get_random_moves(t_move n_moves[], int n, int k) {
    // Il faut que k et n soient > 0 et que k > n, sinon le calcul est impossible
    if (k <= 0 || n <= 0 || k > n) {
        fprintf(stderr, "Erreur : paramètres invalides (k=%d, n=%d).\n", k, n);
        return NULL;
    }

    // Il faut allouer un tableau dynamique pour les mouvements sélectionnés
    t_move *random_moves = malloc(k * sizeof(t_move));
    // On vérifie que l'allocation n'a pas échoué
    if (random_moves == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    // On choisis aléatoirement les k mouvements
    for (int i = 0; i < k; i++) {
        int random_index = rand() % n; // Générer un index aléatoire dans [0, n-1]
        random_moves[i] = n_moves[random_index];
        n_moves = remove_depl_from_tab(n_moves,random_moves[i] , n--);
    }

    return random_moves;
}

t_move determine_best_move(t_map map, t_localisation loc, t_move* moves, int num_moves) {
    t_move best_move = moves[0];
    int min_cost = INT_MAX;

    for (int i = 0; i < num_moves; i++) {
        t_localisation new_loc = simulate_move(loc, moves[i]);
        if (new_loc.pos.x >= 0 && new_loc.pos.x < map.x_max &&
            new_loc.pos.y >= 0 && new_loc.pos.y < map.y_max) {
            int cost = map.costs[new_loc.pos.y][new_loc.pos.x];
            if (cost < min_cost) {
                min_cost = cost;
                best_move = moves[i];
            }
        }
    }

    return best_move;
}
