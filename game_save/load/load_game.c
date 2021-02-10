#include "../../auto_import.h"

void continueGameWithFriend(Player player1, Player player2);

bool isPlayerBot(Player player);

Player determineBot(Player player1, Player player2);

Player determineHuman(Player player1, Player player2);

void continueGameWithBot(Player player, Player bot);

void handleLoadGame() {

    FILE *savedGamesDatabaseHandler = fopen("../database/loader.database.binary", "rb");
    if (fileIsEmpty(savedGamesDatabaseHandler)) {
        printf("NO GAME HAS BEEN SAVED!\n");
        if (isApplicationInProduction) {
            printf("sleep for 2 seconds and then clear screen . . . \n");
            sleep(2);
            clearScreen();
        }
        return;
    }

    int idCounter = 1;
    GameSave log;
    do {
//        reading the log
        fread(&log, sizeof(GameSave), 1, savedGamesDatabaseHandler);


//        printing the log
        printf("------------------------------\n");
        printf("id : %d\n", idCounter);
        idCounter++;
        printf("attacker : %s\n", log.attackerUser.name);
        printf("defender : %s\n", log.defenderUser.name);
    } while (!feof(savedGamesDatabaseHandler));
    printf("-----------------------------------\n");

//    getting user input
    printf("please input game id you want to load:\t");
    int loadGameId;
    scanf("%d", &loadGameId);

    fclose(savedGamesDatabaseHandler);
    loadGameById(loadGameId);
}

void loadGameById(int id) {
    FILE *savedGamesDatabaseHandler = fopen("../database/loader.database.binary", "rb");
    GameSave log;

    for (int i = 0; i < id; ++i) {
//    going through saved logs until reaching the game we want to load
        fread(&log, sizeof(GameSave), 1, savedGamesDatabaseHandler);
    }

    Player player1;
    Player player2;

    makePlayersFromLog(log, &player1, &player2);

    fclose(savedGamesDatabaseHandler);


    if (isPlayerBot(player1) || isPlayerBot(player2)) {
        Player bot = determineBot(player1, player2);
        Player human = determineHuman(player1, player2);

        return continueGameWithBot(human, bot);
    }

    continueGameWithFriend(player1, player2);
}

void continueGameWithBot(Player player, Player bot) {
    while (!thereIsWinner(player, bot)) {
        Player *attacker = findAttacker(&player, &bot);
        Player *defender = findDefender(&player, &bot);

        if (strcmp(player.userData.name, attacker->userData.name) == 0) {
//            player is the attacker
            printf("%s score : %d\n", attacker->userData.name, attacker->userData.score);
            int order = getUserMenuOrder(&inGameMenuShower, 0);

            if (order == 1) {
                handleMakeMove(attacker, defender);
                if (isApplicationInProduction) {
                    printf("sleep for 2 seconds and then clear screen . . . \n");
                    sleep(2);
                    clearScreen();
                }
            } else {
                handleGameSave(attacker, defender);
                if (isApplicationInProduction) {
                    clearScreen();
                }
                return;
            }
        } else {
//            it is bot turn
            Coordinate botAttackCoordinate = handleBotMove(attacker, defender);
            printf("bot attacked coordinate with x: %d, y: %d\n", botAttackCoordinate.x, botAttackCoordinate.y);
            if (isApplicationInProduction) {
                printf("sleep for 2 seconds and then clear screen . . . \n");
                sleep(2);
                clearScreen();
            }
        }
    }

    Player *winner = findWinner(&player, &bot);
    Player *loser = findLoser(&player, &bot);

    printf("game is finished :)");
    printf("%s has won the game :)", winner->userData.name);

    updatePlayerData(winner, loser);
    updateUserScoreBoard(player.userData);

    if (isApplicationInProduction) {
        printf("sleep for 3 seconds and then clear screen . . . \n");
        sleep(3);
        clearScreen();
    }
}

Player determineHuman(Player player1, Player player2) {
    if (strcmp(player1.userData.name, "BOT") == 0) {
        return player2;
    }

    return player1;
}

Player determineBot(Player player1, Player player2) {
    if (strcmp(player1.userData.name, "BOT") == 0) {
        return player1;
    }

    return player2;
}

bool isPlayerBot(Player player) {
    return strcmp(player.userData.name, "BOT") == 0;
}

void continueGameWithFriend(Player player1, Player player2) {
    while (!thereIsWinner(player1, player2)) {
        Player *attacker = findAttacker(&player1, &player2);
        Player *defender = findDefender(&player1, &player2);

        printf("%s score: %d\n", attacker->userData.name, attacker->userData.score);
        printf("%s score: %d\n", defender->userData.name, defender->userData.score);

        printf("%s turn:\n", attacker->userData.name);
        int order = getUserMenuOrder(&inGameMenuShower, 0);

        if (order == 1) {
            handleMakeMove(attacker, defender);
            if (isApplicationInProduction) {
                printf("sleep for 2 seconds and then clear screen . . . \n");
                sleep(2);
                clearScreen();
            }
        } else {
            handleGameSave(attacker, defender);
            printf("game saved successfully!\n");

            if (isApplicationInProduction) {
                clearScreen();
            }

            return;
        }
    }
}

void makePlayersFromLog(GameSave log, Player *player1, Player *player2) {
    player1->userData = log.attackerUser;
    player1->isPlayerTurn = true; //because player1 is attacker in the log so now it is player 1 turn
    player1->shipHead = makeLinkedListFromArray(log.attackerShips, log.attackerShipCount);

    player2->userData = log.defenderUser;
    player2->isPlayerTurn = false;
    player2->shipHead = makeLinkedListFromArray(log.defenderShips, log.defenderShipCount);

    setupPlayerAttackMap(player1, player2, log);
}

void setupPlayerAttackMap(Player *player1, Player *player2, GameSave log) {
//    SETTING UP PLAYER1
    char player1AttackMap[10][10];
//    setting up player1AttackMap
    setupMapRow(player1AttackMap[0], log.attackerMapRow1);
    setupMapRow(player1AttackMap[1], log.attackerMapRow2);
    setupMapRow(player1AttackMap[2], log.attackerMapRow3);
    setupMapRow(player1AttackMap[3], log.attackerMapRow4);
    setupMapRow(player1AttackMap[4], log.attackerMapRow5);
    setupMapRow(player1AttackMap[5], log.attackerMapRow6);
    setupMapRow(player1AttackMap[6], log.attackerMapRow7);
    setupMapRow(player1AttackMap[7], log.attackerMapRow8);
    setupMapRow(player1AttackMap[8], log.attackerMapRow9);
    setupMapRow(player1AttackMap[9], log.attackerMapRow10);

//    copy player1AttackMap to player1->attackMap
    for (int row = 0; row < 10; ++row) {
        for (int column = 0; column < 10; ++column) {
            player1->attackMap[row][column] = player1AttackMap[row][column];
        }
    }

//    SETTING UP PLAYER2
    char player2AttackMap[10][10];
//    setting up player1AttackMap
    setupMapRow(player2AttackMap[0], log.defenderMapRow1);
    setupMapRow(player2AttackMap[1], log.defenderMapRow2);
    setupMapRow(player2AttackMap[2], log.defenderMapRow3);
    setupMapRow(player2AttackMap[3], log.defenderMapRow4);
    setupMapRow(player2AttackMap[4], log.defenderMapRow5);
    setupMapRow(player2AttackMap[5], log.defenderMapRow6);
    setupMapRow(player2AttackMap[6], log.defenderMapRow7);
    setupMapRow(player2AttackMap[7], log.defenderMapRow8);
    setupMapRow(player2AttackMap[8], log.defenderMapRow9);
    setupMapRow(player2AttackMap[9], log.defenderMapRow10);

//    copy player1AttackMap to player1->attackMap
    for (int row = 0; row < 10; ++row) {
        for (int column = 0; column < 10; ++column) {
            player2->attackMap[row][column] = player2AttackMap[row][column];
        }
    }
}

Ship *makeLinkedListFromArray(Ship shipsArray[10], int shipCount) {
    Ship *head = NULL;
    for (int i = 0; i < shipCount; ++i) {
        head = addItemToList(head, shipsArray[i]);
    }

    return head;
}

Ship *addItemToList(Ship *head, Ship ship) {
    if (!head) {
        head = (Ship *) calloc(1, sizeof(ship));
        head->start = ship.start;
        head->end = ship.end;
        head->width = ship.width;
        head->hitCount = ship.hitCount;
        head->next = NULL;
        return head;
    }

    Ship *newShip = (Ship *) calloc(1, sizeof(Ship));
    newShip->start = ship.start;
    newShip->end = ship.end;
    newShip->width = ship.width;
    newShip->hitCount = ship.hitCount;
    newShip->next = NULL;

    Ship *oldTale = findTale(head);
    oldTale->next = newShip;

    return head;
}

void handleLoadLastGame() {
    FILE *savedGamesDatabaseHandler = fopen("../database/loader.database.binary", "rb");
    if (fileIsEmpty(savedGamesDatabaseHandler)) {
        printf("NO GAME HAS BEEN SAVED!\n");
        return;
    }
    loadGameById(1);
}