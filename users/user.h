#ifndef SEA_BATTLE_USER_H
#define SEA_BATTLE_USER_H
#define MAX_NAME_LENGTH 100

typedef struct {
    long int id;
    char name[MAX_NAME_LENGTH];
    int winCount;
    int loseCount;
    double winLostRatio;
    int score;
} Student;

#endif //SEA_BATTLE_USER_H