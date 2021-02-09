#include "../../auto_import.h"


void showScoreboardHandler() {
    FILE *usersDatabaseHandler = fopen("../database/users.database.binary", "rb");

    int usersCount = getUsersCount(usersDatabaseHandler);

    User users[usersCount];

//    reading data from file and adding to array
    evaluateUsersArray(usersCount, users, usersDatabaseHandler);

//    sort
    qsort(users, usersCount, sizeof(User), &usersScoreCompareFunction);

//    print
    printUserArray(users, usersCount);
}

void printUserArray(User *users, int count) {
    for (int i = 0; i < count; ++i) {
        User printUser = users[i];
        printf("----------------------------------\n");
        printf("%d)\n ", i + 1);
        printf("name => %s\n", printUser.name);
        printf("score => %d\n", printUser.score);
        printf("win count => %d\n", printUser.winCount);
        printf("lose count => %d\n", printUser.loseCount);
        printf("win lose ratio => %f\n", printUser.winLoseRatio);
    }
    printf("----------------------------------\n");

}

int usersScoreCompareFunction(const void *a, const void *b) {
    User *user1 = (User *) a;
    User *user2 = (User *) b;

    return user1->score - user2->score;
}

void evaluateUsersArray(int count, User users[count], FILE *usersDatabaseHandler) {
    User user;

    for (int index = 0; index < count; ++index) {
        fread(&user, sizeof(user), 1, usersDatabaseHandler);

        users[index] = user;
    }
}

int getUsersCount(FILE *usersDatabaseHandler) {
    int counter = 0;
    User user;

    while (!feof(usersDatabaseHandler)) {
        fread(&user, sizeof(user), 1, usersDatabaseHandler);
        counter++;
    }
//    return to beginning of the file
    fseek(usersDatabaseHandler, 0, SEEK_SET);
    return counter;
}


