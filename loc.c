//
// Created by flasque on 19/10/2024.
//

#include "loc.h"

t_localisation loc_init(int x, int y, t_orientation ori)
{
    t_localisation loc;
    loc.pos.x = x;
    loc.pos.y = y;
    loc.ori = ori;
    return loc;
}

int isValidLocalisation(t_position loc, int x_max, int y_max)
{
    return (loc.x >= 0 && loc.x < x_max && loc.y >= 0 && loc.y < y_max);
}

t_position LEFT(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x - 1;
    new_pos.y = pos.y;
    return new_pos;
}

t_position RIGHT(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x + 1;
    new_pos.y = pos.y;
    return new_pos;
}

t_position UP(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x;
    new_pos.y = pos.y - 1;
    return new_pos;
}

t_position DOWN(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x;
    new_pos.y = pos.y + 1;
    return new_pos;
}

t_localisation simulate_move(t_localisation loc, t_move move)
{
    t_localisation new_loc = loc;
    switch (move) {
        case F_10:
            if (loc.ori == NORTH) {
                new_loc.pos.y -= 1;
            } else if (loc.ori == SOUTH) {
                new_loc.pos.y += 1;
            } else if (loc.ori == EAST) {
                new_loc.pos.x += 1;
            } else if (loc.ori == WEST) {
                new_loc.pos.x -= 1;
            }
            break;
        case F_20:
            if (loc.ori == NORTH) {
                new_loc.pos.y -= 2;
            } else if (loc.ori == SOUTH) {
                new_loc.pos.y += 2;
            } else if (loc.ori == EAST) {
                new_loc.pos.x += 2;
            } else if (loc.ori == WEST) {
                new_loc.pos.x -= 2;
            }
            break;
        case F_30:
            if (loc.ori == NORTH) {
                new_loc.pos.y -= 3;
            } else if (loc.ori == SOUTH) {
                new_loc.pos.y += 3;
            } else if (loc.ori == EAST) {
                new_loc.pos.x += 3;
            } else if (loc.ori == WEST) {
                new_loc.pos.x -= 3;
            }
            break;
        case B_10:
            if (loc.ori == NORTH) {
                new_loc.pos.y += 1;
            } else if (loc.ori == SOUTH) {
                new_loc.pos.y -= 1;
            } else if (loc.ori == EAST) {
                new_loc.pos.x -= 1;
            } else if (loc.ori == WEST) {
                new_loc.pos.x += 1;
            }
            break;
        case T_LEFT:
            new_loc.ori = (new_loc.ori + 3) % 4;
            break;
        case T_RIGHT:
            new_loc.ori = (new_loc.ori + 1) % 4;
            break;
        case U_TURN:
            new_loc.ori = (new_loc.ori + 2) % 4;
            break;
        default:
            break;
    }
    return new_loc;
}