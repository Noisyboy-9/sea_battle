#include "multiplayer.h"
#include "../../menu/menu.h"
#include "../../players/player.h"


void playWithFriendMode() {
//    player1
    int selectUserOrder = getUserMenuOrder(&selectUserMenuShower, 1);
    int putShipOrder = getUserMenuOrder(&selectPutShipMenuShower, 1);
    Player player1 = loadPlayerFromUserChoice(selectUserOrder, putShipOrder);


//    player2
    selectUserOrder = getUserMenuOrder(&selectUserMenuShower, 2);
    putShipOrder = getUserMenuOrder(&selectPutShipMenuShower, 2);
    Player player2 = loadPlayerFromUserChoice(selectUserOrder, putShipOrder);

//    starting the game
//    startGame(player1, player2);
}

