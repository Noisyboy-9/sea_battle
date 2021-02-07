#include "../../auto_import.h"

int getUserMenuOrder(void (*menuShowCallback)(), int playerNumber) {
    int order;
    if (playerNumber) {
        printf("PLAYER %d\n", playerNumber);
    }

    (*menuShowCallback)();
    printf("please input you order:\t");
    scanf("%d", &order);
    return order;
}