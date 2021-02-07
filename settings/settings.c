#include "../auto_import.h"


void changeSettingsHandler() {
    int order = getUserMenuOrder(&showSettingsMenu, 0);

    switch (order) {
        case 1:
            printf("handle ship settings");
            break;
        case 2:
            printf("handle map size settings");
            break;
        case 3:
            printf("handle theme settings");
            break;
    }
}
