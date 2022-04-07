#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

struct Node {
    string text;
    Node *next;
};

void printList(Node* list) {
    if (list == nullptr) {
        return;
    }

    Node* tmp = list;
    while (tmp->next != list) {
        cout << tmp->text << '\n';
        tmp = tmp->next;
    }
    cout << tmp->text << '\n';
}

Node* readList() {
    Node* first = nullptr;
    Node* last = nullptr;
    int listLength;
    string text;

    cout << "List length:\n";
    cin >> listLength;

    cout << "Enter values:\n";

    for (int i = 0; i < listLength; i++) {
        cin >> text;

        Node* tmp = new Node;
        tmp->text = text;
        tmp->next = nullptr;

        if (first == nullptr) {
            first = tmp;
            first->next = first;
            last = first;
        } else {
            last->next = tmp;
            tmp->next = first;
            last = tmp;
        }
    }

    return first;
}

void unite(Node*& list) {
    if (list == nullptr || list->next == list) {
        return;
    }

    Node* tmp = list;

    while(tmp->next != list) {
        if (tmp->text.back() == tmp->next->text.front()) {
            tmp->text = tmp->text + '-' + tmp->next->text;

            Node* toDelete = tmp->next;

            tmp->next = tmp->next->next;

            delete toDelete;
        } else {
            tmp = tmp->next;
        }  
    }

    // tmp->next == list ------> true

    if (tmp != list && tmp->text.back() == list->text.front()) {
        tmp->text = tmp->text + '-' + list->text;

        tmp->next = list->next;

        Node* toDelete = list;

        list = tmp;

        delete toDelete;
    }
}

Node* findSmallestString(Node* list) {
    if (list == nullptr || list->next == list) {
        return list;
    }

    Node* tmp = list;
    Node* smallestStringPtr = list;

    while (tmp->next != list) {
        if (tmp->text < smallestStringPtr->text) {
            smallestStringPtr = tmp;
        }
        tmp = tmp->next;
    }
    
    if (tmp->text < list->text) {
        smallestStringPtr = tmp;
    }

    return smallestStringPtr;
}

int main() {

    Node* myList = readList();

    cout << '\n';

    unite(myList);

    Node* ptr = findSmallestString(myList);

    printList(ptr);

    return 0;
}