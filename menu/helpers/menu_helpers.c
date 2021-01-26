#include <stdio.h>

int getUserMenuOrder(void (*menuShowCallback)()) {
    int order;
    (*menuShowCallback)();
    printf("please input you order:\t");
    scanf("%d", &order);
    return order;
}