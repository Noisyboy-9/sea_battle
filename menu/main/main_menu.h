#ifndef SEA_BATTLE_MAIN_MENU_H
#define SEA_BATTLE_MAIN_MENU_H

#define MAIN_MENU_PLAY_WITH_FRIEND 1
#define MAIN_MENU_PLAY_WITH_BOT 2
#define MAIN_MENU_LOAD_GAME 3
#define MAIN_MENU_LOAD_LAST_GAME 4
#define MAIN_MENU_SETTINGS 5
#define MAIN_MENU_SCORE_BOARD 6
#define MAIN_MENU_EXIT 7

void showMainMenu();

int mainMenuOrderController(int order);

#endif //SEA_BATTLE_MAIN_MENU_H
