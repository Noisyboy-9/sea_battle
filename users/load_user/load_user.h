#ifndef SEA_BATTLE_LOAD_USER_H
#define SEA_BATTLE_LOAD_USER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../users.h"
#include "../define/user_define.h"

User createNewUser();

User loadUserFromDatabase();

bool userExists(char name[MAX_NAME_LENGTH]);

long determineUserId();

void printAllSavedUsers();

User getUser(char name[100]);

#endif //SEA_BATTLE_LOAD_USER_H