#include <iostream>
using std::cout;

struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int _data) {
        data = _data;
    }
};

Node* getLastNode(Node* list) {
    Node* current = list;
    while(current->next != nullptr) {
        current = current->next;
    }
    return current;
}

Node* join(Node* a, Node* b) {
    if (a == nullptr || b == nullptr) {
        return nullptr;
    }
    Node* lastA = getLastNode(a);
    Node* currentA = lastA;
    Node* currentB = b;
    while(currentA != nullptr && currentB != nullptr) {
        if (currentA->data == currentB->data) {
            b->prev = currentA;
            lastA->next = currentB;
            return a;
        } 
        currentA = currentA->prev;
        currentB = currentB->next;
    }
    return nullptr;
}

bool isJoined(Node* start, Node* end) {
    if (start == nullptr) {
        return false;
    }
    Node* current = start;
    while (current->next != nullptr) {
        if (current != current->next->prev) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int sum(Node* start) {
    if (start == nullptr) {
        return 0;
    }
    Node* current = start;
    int sum = 0;
    while(current == current->next->prev) {
        sum += current->data;
        current = current->next;
    }
    sum += current->data;
    Node* joinPoint = current->next;
    current = current->next;
    while(current != nullptr) {
        sum += current->data;
        current = current->next;
    }
    current = joinPoint->prev;
    while (current == current->prev->next) {
        sum += current->data;
        current = current->prev;
    }
    sum += current->data;
    return sum;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(3);
    Node* n3 = new Node(5);
    Node* n4 = new Node(7);
    Node* n5 = new Node(9);
    Node* n6 = new Node(6);
    Node* n7 = new Node(3);
    Node* n8 = new Node(4);
    Node* n9 = new Node(8);
    Node* n10 = new Node(5);
    Node* n11 = new Node(7);
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;
    n10->next = n11; n11->prev = n10;

    Node* joined = join(n1, n7);
    cout << "Sum: " << sum(joined) << '\n';

    return 0;
}