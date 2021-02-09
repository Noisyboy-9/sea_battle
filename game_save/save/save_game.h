#pragma once

#include "../../auto_import.h"

void handleGameSave(Player *attacker, Player *defender);

int countItems(Ship *head);

void makeArrayFromLinkedList(Ship *head, Ship array[], int count);

void copyShipArray(Ship *destination, Ship *source, int sourceCount);

void setupMapRow(char destinationRow[10], char sourceRow[10]);

void saveGameDataToBeginningOfFile(GameSave log);