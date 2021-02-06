#ifndef SEA_BATTLE_SHIP_DEFINE_H
#define SEA_BATTLE_SHIP_DEFINE_H

#include "../../map/point_declare/point_declare.h"

typedef struct {
    int width;
    int height;
    Coordinate start;
    Coordinate finish;
} Ship;
#endif //SEA_BATTLE_SHIP_DEFINE_H