#include <stdio.h>
#include "menu/menu.h"

int main() {
    int mainMenuOrder = getUserMenuOrder(&showMainMenu, NULL);
    while (mainMenuOrder != MAIN_MENU_EXIT) {
        mainMenuOrderController(mainMenuOrder);
        mainMenuOrder = getUserMenuOrder(&showMainMenu, NULL);
    }

    printf("hope you have enjoyed :)\n");
    printf("Good Bye :)");
    return 0;
}

