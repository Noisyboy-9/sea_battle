#include "../../modes/modes.h"
#include "../../menu/menu.h"
#include "../../players/player.h"


void playWithBotMode() {
    //    player1
    int selectUserOrder = getUserMenuOrder(&selectUserMenuShower, 0);
    int putShipOrder = getUserMenuOrder(&selectPutShipMenuShower, 0);
    Player player = loadPlayerFromUserChoice(selectUserOrder, putShipOrder);

//    bot

//    start game
}
