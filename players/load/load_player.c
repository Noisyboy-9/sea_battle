#include "load_player.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../users/users.h"

Player loadPlayerFromUserChoice(int selectUserOrder, int putShipOrder) {
    User user = (selectUserOrder == 1) ? loadUserFromDatabase() : createNewUser();
//    return (putShipOrder == 1) ? autoPutShips(user) : putShipsManually(user);
}

