#ifndef SEA_BATTLE_SHIP_PLACEMENT_AUTO_H
#define SEA_BATTLE_SHIP_PLACEMENT_AUTO_H

#include "../../../auto_import.h"

typedef enum {
    HORIZONTAL = 1,
    VERTICAL = 2
} Direction;


Player handleAutoShipPlacement(User user);

Player putShipAutomatically(Player player);

Ship *autoPutShip(Ship *head, int count, int shipWidth, char map[10][10]);

Coordinate generateRandomCoordination();

int rangedRandom(int min, int max);

Direction generateRandomDirection();

#endif //SEA_BATTLE_SHIP_PLACEMENT_AUTO_H