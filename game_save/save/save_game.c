#include "../../auto_import.h"


void handleGameSave(Player *attacker, Player *defender) {
    int attackerShipCount = countItems(attacker->shipHead);

    if (attackerShipCount == 0) {
        printf("attacker has no ships, game is over no need to save game\n");
        return;
    }

    Ship attackerShips[attackerShipCount];
    makeArrayFromLinkedList(attacker->shipHead, attackerShips, attackerShipCount);

    int defenderShipCount = countItems(defender->shipHead);
    if (defenderShipCount == 0) {
        printf("defender has no ships, game is over no need to save game\n");
        return;
    }

    Ship defenderShips[defenderShipCount];
    makeArrayFromLinkedList(defender->shipHead, defenderShips, defenderShipCount);

//    making gameSaveStruct
    GameSave gameSaveLog;

//    setting up user data
    gameSaveLog.attackerUser = attacker->userData;
    gameSaveLog.defenderUser = defender->userData;

//    setting up ships data
    copyShipArray(gameSaveLog.attackerShips, attackerShips, attackerShipCount);
    gameSaveLog.attackerShipCount = attackerShipCount;

    copyShipArray(gameSaveLog.defenderShips, defenderShips, defenderShipCount);
    gameSaveLog.defenderShipCount = defenderShipCount;

//    setting up attacker map
    setupMapRow(gameSaveLog.attackerMapRow1, (attacker->attackMap)[0]);
    setupMapRow(gameSaveLog.attackerMapRow2, (attacker->attackMap)[1]);
    setupMapRow(gameSaveLog.attackerMapRow3, (attacker->attackMap)[2]);
    setupMapRow(gameSaveLog.attackerMapRow4, (attacker->attackMap)[3]);
    setupMapRow(gameSaveLog.attackerMapRow5, (attacker->attackMap)[4]);
    setupMapRow(gameSaveLog.attackerMapRow6, (attacker->attackMap)[5]);
    setupMapRow(gameSaveLog.attackerMapRow7, (attacker->attackMap)[6]);
    setupMapRow(gameSaveLog.attackerMapRow8, (attacker->attackMap)[7]);
    setupMapRow(gameSaveLog.attackerMapRow9, (attacker->attackMap)[8]);
    setupMapRow(gameSaveLog.attackerMapRow10, (attacker->attackMap)[9]);


//    setting up defender map
    setupMapRow(gameSaveLog.defenderMapRow1, (defender->attackMap)[0]);
    setupMapRow(gameSaveLog.defenderMapRow2, (defender->attackMap)[1]);
    setupMapRow(gameSaveLog.defenderMapRow3, (defender->attackMap)[2]);
    setupMapRow(gameSaveLog.defenderMapRow4, (defender->attackMap)[3]);
    setupMapRow(gameSaveLog.defenderMapRow5, (defender->attackMap)[4]);
    setupMapRow(gameSaveLog.defenderMapRow6, (defender->attackMap)[5]);
    setupMapRow(gameSaveLog.defenderMapRow7, (defender->attackMap)[6]);
    setupMapRow(gameSaveLog.defenderMapRow8, (defender->attackMap)[7]);
    setupMapRow(gameSaveLog.defenderMapRow9, (defender->attackMap)[8]);
    setupMapRow(gameSaveLog.defenderMapRow10, (defender->attackMap)[9]);

//    writing data to file
    saveGameDataToBeginningOfFile(gameSaveLog);
}

void saveGameDataToBeginningOfFile(GameSave log) {
    FILE *saveGameDatabaseHandler = fopen("../database/loader.database.binary", "ab");
    fseek(saveGameDatabaseHandler, 0, SEEK_SET);
    fwrite(&log, sizeof(log), 1, saveGameDatabaseHandler);
    fclose(saveGameDatabaseHandler);
}

void setupMapRow(char destinationRow[10], char sourceRow[10]) {
    for (int i = 0; i < 10; ++i) {
        destinationRow[i] = sourceRow[i];
    }
}

void copyShipArray(Ship *destination, Ship *source, int sourceCount) {
    for (int i = 0; i < sourceCount; ++i) {
        destination[i] = source[i];
    }
}

void makeArrayFromLinkedList(Ship *head, Ship array[], int count) {
    Ship *iterationShip = head;
    for (int i = 0; i < count; ++i) {
        array[i] = (*iterationShip);
        iterationShip = iterationShip->next;
    }
}

int countItems(Ship *head) {
    if (!head) {
        return 0;
    }

    int counter = 0;
    Ship *iterationShip = head;

    while (iterationShip) {
        iterationShip = iterationShip->next;
        counter++;
    }

    return counter;
}
