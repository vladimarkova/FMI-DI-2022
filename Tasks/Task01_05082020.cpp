#include <iostream>
#include <cstring>

void print_backwards(const char* begin, const char* end) {
    if(begin > end) { 
        std::cout << std::endl;
        return;
    }
    char* dyn = new char[end - begin];
    char* iter = dyn;
    --end;
    while(begin <= end && *end-- <= 32) 
        ;
    while(begin <= end && *end > 32) { 
            *iter++ = *end--;
    }
    while(dyn < iter) {
        std::cout << *dyn++;
    } 
    std::cout << " "; 
    
    delete[] dyn;
    print_backwards(begin, end);
}

void print_backwards(const char* string) {
    int length = std::strlen(string);
    print_backwards(string, string + length);
}

int main() {
    print_backwards("I\tneed a break!");
    return 0;
}