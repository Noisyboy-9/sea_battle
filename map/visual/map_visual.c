#include "../../auto_import.h"

void fillMapWithLetter(char map[10][10], char value) {
    for (int row = 0; row < 10; ++row) {
        for (int column = 0; column < 10; ++column) {
            map[row][column] = value;
        }
    }
}

void showMap(char map[10][10]) {
    printf("%2c", '#');
    for (int i = 0; i < 10; ++i) {
        printf("%2d", i);
    }
    printf("\n");

    for (int row = 0; row < 10; ++row) {
        printf("%2d", row);
        for (int column = 0; column < 10; ++column) {
            printf("%2c", map[row][column]);
        }

        printf("\n");
    }
}