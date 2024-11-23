#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "map.h"
#include "tree.h"

int main() {
    t_map map = createMapFromFile("..\\maps\\littlemap.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);
    t_tree treefor33;
    treefor33 = createEmptyNTree();
    t_move depl[10] = {F_10, F_20, F_10, T_RIGHT, T_RIGHT};
    t_localisation init;
    init.pos.x = map.x_max - 2;
    init.pos.y = map.y_max - 1;
    init.ori = NORTH;
    Fill_Tree(&treefor33, 3, 3, map.costs, init, depl,map.y_max - 1, map.x_max );
    display_tree(treefor33);

    // Exemple d'utilisation de la fonction get_random_moves()

    srand(time(NULL));

    t_move all_moves[] = {
            // 22 occurrences de F_10
            F_10, F_10, F_10, F_10, F_10, F_10, F_10, F_10, F_10, F_10,
            F_10, F_10, F_10, F_10, F_10, F_10, F_10, F_10, F_10, F_10, F_10, F_10,

            // 15 occurrences de F_20
            F_20, F_20, F_20, F_20, F_20, F_20, F_20, F_20, F_20, F_20,
            F_20, F_20, F_20, F_20, F_20,

            // 7 occurrences de F_30
            F_30, F_30, F_30, F_30, F_30, F_30, F_30,

            // 7 occurrences de B_10
            B_10, B_10, B_10, B_10, B_10, B_10, B_10,

            // 21 occurrences de T_LEFT
            T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT,
            T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT, T_LEFT,

            // 21 occurrences de T_RIGHT
            T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT,
            T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT, T_RIGHT,

            // 7 occurrences de U_TURN
            U_TURN, U_TURN, U_TURN, U_TURN, U_TURN, U_TURN, U_TURN
    };

    int n = 100;
    int k = 9;

    t_move *selected_moves = get_random_moves(all_moves, n, k);

    // Affichage
    printf("Mouvements :\n");
    for (int i = 0; i < k; i++) {
        printf("%s\n", getMoveAsString(selected_moves[i]));
    }
    selected_moves = remove_depl_from_tab(selected_moves, F_10, k);
    printf("After removing F_10 :\n");
    for (int i = 0; i < k - 1; i++) {
        printf("%s\n", getMoveAsString(selected_moves[i]));
    }
    free(selected_moves);

    /* Initialisation de la position du robot
    t_localisation loc;
    loc.pos.x = 2;
    loc.pos.y = 2;
    loc.ori = NORTH;
    // Initialisation des mouvements possibles
    t_move moves[] = {F_10, F_20, F_30, B_10, T_LEFT, T_RIGHT, U_TURN};
    int num_moves = sizeof(moves) / sizeof(moves[0]);
    printf("Before determine_best_move\n");
    // Appel de la fonction determine_best_move
    t_move best_move = determine_best_move(map, loc, moves, num_moves);
    printf("After determine_best_move\n");
    // Affichage du meilleur mouvement
    printf("Le meilleur mouvement est : %s\n", getMoveAsString(best_move));
    printf("Before simulate_move\n");
    // Simulation du mouvement
    t_localisation new_loc = simulate_move(loc, best_move);
    printf("After simulate_move\n");
    // Affichage de la nouvelle position
    printf("Nouvelle position : (%d, %d) orientation : %d\n", new_loc.pos.x, new_loc.pos.y, new_loc.ori);
    for (int i = 0; i < map.y_max; i++) {
        free(map.costs[i]);
    }
    free(map.costs);*/

    return 0;
}
