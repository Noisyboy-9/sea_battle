#ifndef SEA_BATTLE_USER_DEFINE_H
#define SEA_BATTLE_USER_DEFINE_H
#define MAX_NAME_LENGTH 100

typedef struct {
    long int id;
    char name[MAX_NAME_LENGTH];
    int winCount;
    int loseCount;
    double winLoseRation;
    int score;
} User;

#endif //SEA_BATTLE_USER_DEFINE_H