#include "multiplayer.h"
#include "../../menu/menu.h"


void playWithFriendMode() {
//    user1
    getUserMenuOrder(&selectUserMenuShower, 1);
    getUserMenuOrder(&selectPutShipMenuShower, 1);


//    user2
    getUserMenuOrder(&selectUserMenuShower, 2);
    getUserMenuOrder(&selectPutShipMenuShower, 2);

//    starting the game
//    startGame(user1, user2);
}

