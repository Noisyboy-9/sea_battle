#ifndef SEA_BATTLE_LOAD_PLAYER_H
#define SEA_BATTLE_LOAD_PLAYER_H

#include "../define/player_define.h"

Player loadPlayerFromUserChoice(int selectUserOrder, int putShipOrder);


Player autoPutShips(User user);

Player putShipsManually(User user);

#endif //SEA_BATTLE_LOAD_USER_H