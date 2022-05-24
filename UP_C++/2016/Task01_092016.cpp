#include <iostream>
#include <utility>
#include <cstring>
using std::cout;
using std::pair;

const int ASCII_CHARS = 128;

pair<int, int> mostDistantPositions(const char* str) {
    int length = strlen(str);
    pair<int, int> symsPositions[ASCII_CHARS];
    for (int i = 0; i < ASCII_CHARS; i++) {
        symsPositions[i].first = -1;
        symsPositions[i].second = -1;
    }
    for (int i = 0; i < length; i++) {
        if (symsPositions[str[i]].first == -1) {
            symsPositions[str[i]].first = i;
        }
        symsPositions[str[i]].second = i;
    }
    int maxDistance = 0;
    pair<int, int> maxPair(0, 0);
    for (int i = 0; i < ASCII_CHARS; i++) {
        int currentDistance = symsPositions[i].second - symsPositions[i].first;
        if (currentDistance > maxDistance) {
            maxDistance = currentDistance;
            maxPair = symsPositions[i];
        }
    }
    return maxPair;
}

int main() {
    pair<int, int> result = mostDistantPositions("this is just a simple example");
    cout << result.first << ' ' << result.second << '\n';

    return 0;
}