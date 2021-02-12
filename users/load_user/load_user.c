#include "../../auto_import.h"

User createNewUser() {
    printf("CREATE NEW USER . . .\n");
    char inputName[MAX_NAME_LENGTH];
    printf("please input a name:\t");
    getchar();
    scanf("%s", inputName);

    if (userExists(inputName)) {
        printf("user already exists");
        return loadUserFromDatabase();
    }

    FILE *usersDatabaseHandler = fopen("../database/users.database.binary", "ab");
    User user;
    user.id = determineUserId();
    strcpy(user.name, inputName);
    user.winCount = 0;
    user.loseCount = 0;
    user.winLoseRatio = 0;
    user.score = 0;
    fwrite(&user, sizeof(user), 1, usersDatabaseHandler);
    printf("User Saved Successfully\n");
    fclose(usersDatabaseHandler);
    return user;
}

long determineUserId() {
    FILE *usersDatabaseHandler = fopen("../database/users.database.binary", "rb");
    if (fileIsEmpty(usersDatabaseHandler)) {
        return 1;
    }

    User iterationUser;

    do {
        fread(&iterationUser, sizeof(User), 1, usersDatabaseHandler);
    } while (!feof(usersDatabaseHandler));


    fclose(usersDatabaseHandler);

//    now we have the last user saved so we increment it's id by one for the next user
    return iterationUser.id + 1;
}

bool userExists(char name[MAX_NAME_LENGTH]) {
    FILE *usersDatabaseHandler = fopen("../database/users.database.binary", "rb");
    User iterationUser;

    do {
        fread(&iterationUser, sizeof(User), 1, usersDatabaseHandler);
        if (strcmp(iterationUser.name, name) == 0) {
            fclose(usersDatabaseHandler);
            return true;
        }
    } while (!feof(usersDatabaseHandler));


    fclose(usersDatabaseHandler);
    return false;
}

User loadUserFromDatabase() {
    FILE *usersDatabaseHandler = fopen("../database/users.database.binary", "rb");

    if (fileIsEmpty(usersDatabaseHandler)) {
        fclose(usersDatabaseHandler);
        printf("No User Has Been Saved.\n");
        return createNewUser();
    }

    fclose(usersDatabaseHandler);


    printf("LOADING USER FROM DATABASE . . .\n");

    printAllSavedUsers();

    printf("please input user name:\t");
    char inputName[MAX_NAME_LENGTH];
    scanf("%s", inputName);


    while (!userExists(inputName)) {
        printf("Error : no user with given name is stored!\n");
        printAllSavedUsers();
        printf("please input user name again:\t");
        scanf("%s", inputName);
    }

    return getUser(inputName);
}

User getUser(char name[MAX_NAME_LENGTH]) {
    FILE *usersDatabaseHandler = fopen("../database/users.database.binary", "rb");
    User iterationUser;

    do {
        fread(&iterationUser, sizeof(User), 1, usersDatabaseHandler);
        if (strcmp(iterationUser.name, name) == 0) {
            fclose(usersDatabaseHandler);
            return iterationUser;
        }
    } while (!feof(usersDatabaseHandler));
}

void printAllSavedUsers() {
    FILE *usersDatabaseHandler = fopen("../database/users.database.binary", "rb");

    if (fileIsEmpty(usersDatabaseHandler)) {
        printf("No User Has Been Saved.\n");
        return;
    }

    printf("All users are:\n");

    User iterationUser;

    do {
        fread(&iterationUser, sizeof(User), 1, usersDatabaseHandler);
        printf("%ld)\n", iterationUser.id);
        printf("name : %s\n", iterationUser.name);
        printf("win count : %d\n", iterationUser.winCount);
        printf("lose count: %d\n", iterationUser.loseCount);
        printf("win - lose ration: %.4lf\n", iterationUser.winLoseRatio);
        printf("------------------------\n");
    } while (!feof(usersDatabaseHandler));

    fclose(usersDatabaseHandler);
}

bool fileIsEmpty(FILE *databaseHandler) {
    fseek(databaseHandler, 0, SEEK_END);
    long size = ftell(databaseHandler);

    if (size == 0) {
        fseek(databaseHandler, 0, SEEK_SET);
        return true;
    }

//    return to the beginning of the file
    fseek(databaseHandler, 0, SEEK_SET);
    return false;
}
