#pragma once

#include "../../auto_import.h"

void handleLoadGame();

void handleLoadLastGame();

void loadGameById(int id);

void makePlayersFromLog(GameSave log, Player *player1, Player *player2);

Ship *makeLinkedListFromArray(Ship shipsArray[10], int shipCount);

void setupPlayerAttackMap(Player *player1, Player *player2, GameSave log);

Ship *addItemToList(Ship *head, Ship ship);