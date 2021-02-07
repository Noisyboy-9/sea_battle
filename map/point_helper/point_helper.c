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