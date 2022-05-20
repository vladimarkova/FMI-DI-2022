#include <iostream>
#include <cmath>
using std::cout;

enum RelativePosition {
    NO_COMMON_POINTS, 
    TOUCHING,
    INTERSECTING, 
    SAME
};

struct Point {
    float x;
    float y;

    bool operator==(const Point& other) {
        return x == other.x && y == other.y;
    }

    float distanceTo(const Point& other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y-other.y));
    }
};

struct Circle {
    Point center;
    float r;
};

RelativePosition findRelativePosition(Circle c1, Circle c2) {
    float distance = c1.center.distanceTo(c2.center); 
    if (c1.center == c2.center && c1.r == c2.r) {
        return SAME;
    }
    if ((c1.r + c2.r) == distance || abs(c1.r - c2.r) == distance) {
        return TOUCHING;
    }
    if ((c1.r + c2.r) < distance) {
        return NO_COMMON_POINTS;
    }
    // none of the upper ones is true
    if (c1.r == c2.r) {
        return INTERSECTING;
    }
    if (distance > abs(c1.r - c2.r)) {
        return INTERSECTING;
    } 
    return NO_COMMON_POINTS;
}

int main() {


    return 0;
}