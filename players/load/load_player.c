#include "../../auto_import.h"

Player loadPlayerFromUserChoice(int selectUserOrder, int putShipOrder) {
    User user;
    if (selectUserOrder == 1) {
        user = loadUserFromDatabase();
    } else {
        user = createNewUser();
    }


    if (putShipOrder == 1) {
        return autoPutShips(user);
    } else {
        return putShipsManually(user);
    }
}

Player putShipsManually(User user) {

}

Player autoPutShips(User user) {

}




