#include "load_player.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../users/users.h"

void loadPlayerFromUserChoice(int selectUserOrder, int putShipOrder) {
    if (selectUserOrder == 1) {
        User user = loadUserFromDatabase();
    } else {
        User user = createNewUser();
    }
}

