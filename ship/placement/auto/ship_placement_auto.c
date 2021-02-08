#include "../../../auto_import.h"

Coordinate determineEnd(Coordinate start, Direction direction, int shipWidth);

Player handleAutoShipPlacement(User user) {
//    setting up basic player data
    Player player;
    player.userData = user;
    player.isPlayerTurn = false;

    return putShipAutomatically(player);
}

Player putShipAutomatically(Player player) {
    Ship *shipHead = NULL;
    char map[10][10];
    fillMapWithLetter(map, 'N');

    int shipWidth = 5;
    int shipCount = 1;

    while (shipWidth >= 1) {
        if (shipWidth == 4) {
            shipWidth--;
            continue;
        }

        shipHead = autoPutShip(shipHead, shipCount, shipWidth, map);
        shipWidth--;
        shipCount++;
    }

    player.shipHead = shipHead;
    showMap(map);
    return player;
}

Ship *autoPutShip(Ship *head, int count, int shipWidth, char map[10][10]) {
    for (int i = count; i > 0; --i) {
        if (shipWidth == 5) {
            Coordinate start = {
                    .x = rangedRandom(0, 5),
                    .y = rangedRandom(0, 1)
            };

            Direction direction = HORIZONTAL;

            Coordinate end = determineEnd(start, direction, shipWidth);

            while (!shipCanBePlacedInCoordinates(shipWidth, map, start, end)) {
                start.y = rangedRandom(0, 1);
                start.x = rangedRandom(0, 5);

                end = determineEnd(start, direction, shipWidth);
            }

            head = addShipToList(head, shipWidth, start, start);
            updateMap(map, start, start);
            continue;
        }


        if (shipWidth == 1) {
            Coordinate start = generateRandomCoordination();
            while (!shipCanBePlacedInCoordinates(shipWidth, map, start, start)) {
                start = generateRandomCoordination();
            }

            head = addShipToList(head, shipWidth, start, start);
            updateMap(map, start, start);
            continue;
        }

//        random placement for ships bigger than 1 and smaller than 5
        Coordinate start;
        Coordinate end;
        while (true) {
            start = generateRandomCoordination();
            Direction direction = generateRandomDirection();
            end = determineEnd(start, direction, shipWidth);

            if (shipCanBePlacedInCoordinates(shipWidth, map, start, end)) {
                break;
            }
        }

        head = addShipToList(head, shipWidth, start, end);
        updateMap(map, start, end);
    }
    return head;
}

Coordinate determineEnd(Coordinate start, Direction direction, int shipWidth) {
    Coordinate end;

    if (direction == HORIZONTAL) {
        end.x = start.x + shipWidth - 1;
        end.y = start.y;
    } else {
        end.x = start.x;
        end.y = start.y + shipWidth - 1;
    }

    return end;
}

Direction generateRandomDirection() {
    int randomNumber = rangedRandom(0, 50);

    if (randomNumber >= 25) {
        return HORIZONTAL;
    }
    return VERTICAL;
}

Coordinate generateRandomCoordination() {
    Coordinate coordinate;
    coordinate.x = rangedRandom(0, 9);
    coordinate.y = rangedRandom(0, 9);

    return coordinate;
}

int rangedRandom(int min, int max) {
    if (min == 0) {
        return rand() % ++max;
    }

    if (min > 0) {
        return rand() % ++max + min;
    }
}
