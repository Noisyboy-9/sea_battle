#include <stdio.h>
#include "menu/menu.h"

int main() {
    int mainMenuOrder = getUserMenuOrder(&showMainMenu);
    handleMainMenuOrder(mainMenuOrder);
}

