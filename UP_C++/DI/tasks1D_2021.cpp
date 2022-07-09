#include <iostream>
#include <cmath>

enum RelativePositions {
    NO_COMMON_POINTS,
    TOUCHING,
    INTERSECTING,
    SAME
};

struct Point {
    float x = 0;
    float y = 0;
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

float twoPointsDistance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

bool pointsEqual(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

struct Circle {
    Point center;
    float r = 0;
};

RelativePositions findRelativePosition(const Circle& c1, const Circle& c2) {
    if (twoPointsDistance(c1.center, c2.center) > (c1.r + c2.r)) {
        return NO_COMMON_POINTS;
    }
    if (twoPointsDistance(c1.center, c2.center) < abs(c1.r - c2.r)) {
        return NO_COMMON_POINTS;
    } 
    if (twoPointsDistance(c1.center, c2.center) == (c1.r + c2.r)) {
        return TOUCHING;
    }
    if (twoPointsDistance(c1.center, c2.center) == abs(c1.r - c2.r)) {
        return TOUCHING;
    }
    if (pointsEqual(c1.center, c2.center) && c1.r == c2.r) {
        return SAME;
    }
    if (twoPointsDistance(c1.center, c2.center) > abs(c1.r - c2.r)) {
        return INTERSECTING;
    }
    // to be continued...
}

int main() {


    return 0;
}