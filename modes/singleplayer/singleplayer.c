#include "../../modes/modes.h"
#include "../../menu/menu.h"
#include "../../players/player.h"


void playWithBotMode() {
//    player1
    loadPlayerFromUserChoice(
            getUserMenuOrder(&selectUserMenuShower, 0),
            getUserMenuOrder(&selectPutShipMenuShower, 0)
    );

//    bot

//    start game
}
