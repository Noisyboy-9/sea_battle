#include <stdio.h>
#include "menu/menu.h"

int main() {
    int mainMenuOrder = getUserMenuOrder(&showMainMenu);
    while (mainMenuOrder != MAIN_MENU_EXIT) {
        mainMenuOrderController(mainMenuOrder);
        mainMenuOrder = getUserMenuOrder(&showMainMenu);
    }

    printf("hope you have enjoyed :)\n");
    printf("Good Bye :)");
    return 0;
}

