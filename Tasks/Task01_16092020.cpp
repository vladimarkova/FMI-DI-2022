#include <iostream>
#include <cstring>

int find_employee(const char* leaders[][2], const char* employee, int n) {
    for (int i = 0; i < n; i++) {
        if (!std::strcmp(employee, leaders[i][0])) {
            return i;
        }
    }
    return -1;
}

bool is_subordinate (const char* employee, const char* manager, const char* leaders[][2], size_t n) {
    for (int i = 0; i < n; i++) {
        if (std::strcmp(employee, leaders[i][0])) {
            if (std::strcmp(manager, leaders[i][1])) {
                return true;
            }
            return is_subordinate(leaders[i][1], manager, leaders, n);
        } else {
            return false;
        }
    }
}

const char* the_big_boss(const char* leaders[][2], size_t n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (std::strcmp(leaders[i][1], leaders[j][0])) {
                count++;
            }
        }
        if (count == n) {
            return leaders[i][1];
        }
    }
}

const char* the_big_boss2(const char* leaders[][2], size_t n) {
    for (int i = 0; i < n; i++ ){
        if (find_employee(leaders, leaders[i][1], n) == -1) {
            return leaders[i][1];
        }
    }
    return "";
}

int main() {

    return 0;
}