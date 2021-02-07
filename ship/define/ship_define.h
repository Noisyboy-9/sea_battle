#ifndef SEA_BATTLE_SHIP_DEFINE_H
#define SEA_BATTLE_SHIP_DEFINE_H

#include "../../auto_import.h"

typedef struct ship_t {
    int width;
    Coordinate start;
    Coordinate end;

    struct ship_t *next;
} Ship;
#endif //SEA_BATTLE_SHIP_DEFINE_H