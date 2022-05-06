#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;

struct Node {
    int val;
    Node* next = nullptr;
    Node* jump = nullptr;
};

Node* readList(const char* path) {
    Node* start = nullptr;
    Node* end = nullptr;

    ifstream in(path);
    while(!in.eof()) {
        int val;
        in >> val;
        Node* current = new Node;
        current->val = val;
        if (start == nullptr) {
            start = current;
            end = current;
        } else {
            end->next = current;
            end = current;
        }
    }
    return start;
}

bool member(Node* start, int searched) {
    if (searched < start->val) {
        return false;
    }
    Node* tmp = start;
    Node* previous = start;

    while (tmp != nullptr) {
        if (tmp->val > searched) {
            tmp = previous;
            while (tmp->val < searched) {
                tmp = tmp->next;
            }
            // if (tmp->val == searched) {
            //     return true;
            // }
            // return false;
            return tmp->val == searched;
        }
        if (tmp->val == searched) {
            return true;
        }
        previous = tmp;
        tmp = tmp->jump;
    }
    tmp = previous;
    while (tmp != nullptr) {
         if (tmp->val > searched) {
            return false;
        }
        if (tmp->val == searched) {
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}

int main() {
    Node* list = readList("test.txt");
    cout << member(list, 10) << '\n';

    return 0;
}