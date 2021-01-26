#include <stdio.h>
#include "menu.h"

int getUserMenuOrder(void (*menuShowCallback)()) {
    int order;
    (*menuShowCallback)();
    printf("please input you order:\t");
    scanf("%d", &order);
    return order;
}