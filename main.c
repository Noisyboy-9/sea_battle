#include "auto_import.h"

int main() {
//    basic project setup
    setbuf(stdout, 0);
    srand(time(0));
    isApplicationInProduction = true;

    int mainMenuOrder = getUserMenuOrder(&showMainMenu, 0);

    while (mainMenuOrder != MAIN_MENU_EXIT) {
        mainMenuOrderController(mainMenuOrder);
        mainMenuOrder = getUserMenuOrder(&showMainMenu, 0);
    }

    printf("hope you have enjoyed :)\n");
    printf("Good Bye :)");
    return 0;
}

