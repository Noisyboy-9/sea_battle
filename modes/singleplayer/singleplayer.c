#include "../../auto_import.h"


Player setUpBot();

void playWithBotMode() {
    //    player1
    int selectUserOrder = getUserMenuOrder(&selectUserMenuShower, 0);
    int putShipOrder = getUserMenuOrder(&selectPutShipMenuShower, 0);
    Player player = loadPlayerFromUserChoice(selectUserOrder, putShipOrder);

//    bot
    Player bot = setUpBot();

//    start game with Bot
//    startGameWithBot(player, bot);
}

Player setUpBot() {
    User user;
//    setting up user data for bot
    user.id = -1;
    strcpy(user.name, "BOT");
    user.winLoseRatio = 0;
    user.loseCount = 0;
    user.winCount = 0;
    user.score = 0;


    //  setting up bot player ships
    return handleAutoShipPlacement(user);
}
