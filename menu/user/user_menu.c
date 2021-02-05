#include <stdio.h>
#include "../../menu/menu.h"
#include "../../modes/modes.h"
#include "user_menu.h"


void selectUserMenuShower() {
    printf("Choose user:\n");
    printf("1.\tChoose from available users\n");
    printf("2.\tNew user\n");
}

void selectPutShipMenuShower() {
    printf("How do you want to put your ships:\n");
    printf("1.\tAuto\n");
    printf("2.\tManual\n");
}