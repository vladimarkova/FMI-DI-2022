#include <iostream>
#include <utility>

std::pair<int, int> maxSubarraySum(int a[], int size) {
    int maxSoFar = -100000;
    int maxEndingHere = 0;
    int leftIndex = 0;
    int rightIndex = 0;
    int tmpStart = 0;

    for (int i = 0; i < size; i++) {
        maxEndingHere += a[i]; 
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            leftIndex = tmpStart;
            rightIndex = i;
        }
        if (maxEndingHere + a[i] < 0) {
            maxEndingHere = 0;
            tmpStart++;
        }
    }
    return std::pair<int, int>(leftIndex, rightIndex);
} 

int main() {
    int a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::pair<int, int> idxs = maxSubarraySum(a, 9);
    std::cout << "start: " << idxs.first << ' ' << "end: " << idxs.second << '\n'; 

    return 0;
}