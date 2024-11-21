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

    t_move all_moves[] = {F_10, F_20, F_30, B_10, T_LEFT, T_RIGHT, U_TURN};
    int n = 9;
    int k = 5;

    t_move *selected_moves = get_random_moves(all_moves, n, k);

    // Affichage
    printf("Mouvements :\n");
    for (int i = 0; i < k; i++) {
        printf("%s\n", getMoveAsString(selected_moves[i]));
    }
    selected_moves = remove_depl_from_tab(selected_moves, F_10, 5);
    printf("After removing F_10 :\n");
    for (int i = 0; i < k - 1; i++) {
        printf("%s\n", getMoveAsString(selected_moves[i]));
    }
    free(selected_moves);
    return 0;
}
