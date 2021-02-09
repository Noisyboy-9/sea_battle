#pragma once

#include "../../auto_import.h"

void showScoreboardHandler();

int getUsersCount(FILE *usersDatabaseHandler);

void evaluateUsersArray(int count, User users[count], FILE *usersDatabaseHandler);

int usersScoreCompareFunction(const void *a, const void *b);

void printUserArray(User *users, int count);