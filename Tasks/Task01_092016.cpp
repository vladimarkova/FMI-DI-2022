#include <iostream>
#include <utility>
#include <cstring>

std::pair<int, int> getMaxRemoteChars(const char* str) {
    int length = std::strlen(str);
    int start = 0;
    int maxDistance = 0;
    int stIdx = 0;

    for (int i = 0; i < length; i++) {
        int j;
        for (j = length - 1; j > i; j--) {
            if(str[i] == str[j]) {
                break;
            } 
        }
        int currDistance = j - i;
        if (currDistance > maxDistance) {
            maxDistance = currDistance;
            stIdx = i;
        }
    }
    return std::pair<int, int>(stIdx, stIdx + maxDistance);
}


int main() {
    char myStr[] = "this is just a simple example";
    std::pair<int, int> res = getMaxRemoteChars(myStr);
    std::cout << '(' << res.first << ", " << res.second << ')' << std::endl; 

    return 0;
}