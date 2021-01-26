//
// Created by sinas on 1/26/2021.
//

#include "MenuHelpers.h"

int getUserMenuOrder(void (*menuShowCallback)()) {
    int order;
    (*menuShowCallback)();
    printf("please input you order:\t");
    scanf("%d", &order);
    return order;
}