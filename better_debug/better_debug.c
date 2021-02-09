#include "../auto_import.h"

void clearScreen() {
//#ifdef _WIN32
//    system("cls");
//#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
//    system("clear");
//#else
//#endif
    for (int i = 0; i < 40; ++i) {
        printf("\n");
    }
}