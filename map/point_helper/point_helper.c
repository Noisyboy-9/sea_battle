#include "../../auto_import.h"

int findHighestX(Coordinate start, Coordinate end) {
    return (start.x > end.x) ? start.x : end.x;
}

int findLowestX(Coordinate start, Coordinate end) {
    return (start.x > end.x) ? end.x : start.x;
}

int findHighestY(Coordinate start, Coordinate end) {
    return (start.y > end.y) ? start.y : end.y;
}

int findLowestY(Coordinate start, Coordinate end) {
    return (start.y > end.y) ? end.y : start.y;
}

bool isCoordinationOutOfRange(Coordinate coordination) {
    return coordination.x >= 0 &&
           coordination.x <= 9 &&
           coordination.y >= 0 &&
           coordination.y <= 9;
}

bool isOutOfRange(Coordinate start, Coordinate end) {
    return findHighestY(start, end) > 9 ||
           findHighestX(start, end) > 9 ||
           findLowestY(start, end) < 0 ||
           findLowestX(start, end) < 0;
}
