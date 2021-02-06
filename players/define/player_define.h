#ifndef SEA_BATTLE_PLAYER_DEFINE_H
#define SEA_BATTLE_PLAYER_DEFINE_H

#include "../../users/users.h"
#include "../../ship/ship.h"

typedef struct {
    User userData;
    Ship *shipHead;
    bool isPlayerTurn;
} Player;
#endif //SEA_BATTLE_PLAYER_DEFINE_H