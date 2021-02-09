#include "../../auto_import.h"

#define MAIN_MENU_PLAY_WITH_FRIEND 1
#define MAIN_MENU_PLAY_WITH_BOT 2
#define MAIN_MENU_LOAD_GAME 3
#define MAIN_MENU_LOAD_LAST_GAME 4
#define MAIN_MENU_SETTINGS 5
#define MAIN_MENU_SCORE_BOARD 6
#define MAIN_MENU_EXIT 7



void showMainMenu() {
    printf("%d.\tPlay with a friend\n", MAIN_MENU_PLAY_WITH_FRIEND);
    printf("%d.\tPlay with bot\n", MAIN_MENU_PLAY_WITH_BOT);
    printf("%d.\tLoad game\n", MAIN_MENU_LOAD_GAME);
    printf("%d.\tLoad last game\n", MAIN_MENU_LOAD_LAST_GAME);
    printf("%d.\tSettings\n", MAIN_MENU_SETTINGS);
    printf("%d.\tScore board\n", MAIN_MENU_SCORE_BOARD);
    printf("%d.\tExit\n", MAIN_MENU_EXIT);
}


int mainMenuOrderController(int order) {
    switch (order) {
        case MAIN_MENU_PLAY_WITH_FRIEND:
            playWithFriendMode();
            break;
        case MAIN_MENU_PLAY_WITH_BOT:
            playWithBotMode();
            break;
        case MAIN_MENU_SCORE_BOARD:
            showScoreboardHandler();
            break;
        default:
            order = MAIN_MENU_EXIT;
    }

    return order;
}
