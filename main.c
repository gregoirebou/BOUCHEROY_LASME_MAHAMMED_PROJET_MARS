#include <stdio.h>
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
    Fill_Tree(treefor33, 3, 3, map.costs, init, depl);
    display_tree(treefor33);
    return 0;
}
