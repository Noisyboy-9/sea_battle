#pragma once

#include "../../auto_import.h"

typedef struct {
    User attackerUser;
    User defenderUser;

    Ship attackerShips[10];
    int attackerShipCount;

    Ship defenderShips[10];
    int defenderShipCount;

    char attackerMapRow1[10];
    char attackerMapRow2[10];
    char attackerMapRow3[10];
    char attackerMapRow4[10];
    char attackerMapRow5[10];
    char attackerMapRow6[10];
    char attackerMapRow7[10];
    char attackerMapRow8[10];
    char attackerMapRow9[10];
    char attackerMapRow10[10];


    char defenderMapRow1[10];
    char defenderMapRow2[10];
    char defenderMapRow3[10];
    char defenderMapRow4[10];
    char defenderMapRow5[10];
    char defenderMapRow6[10];
    char defenderMapRow7[10];
    char defenderMapRow8[10];
    char defenderMapRow9[10];
    char defenderMapRow10[10];
} GameSave;