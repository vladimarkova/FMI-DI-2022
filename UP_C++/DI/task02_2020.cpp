#include <iostream>
#include <string>

struct Node {
    std::string text;
    Node* next = nullptr;
    Node(std::string _text, Node* _next = nullptr) {
        text = _text;
        next = _next;
    }
};

void push_back(Node*& end, 
               const std::string& key) {
    if(!end) { 
        end = new Node{ key };
        end->next = end;
    } else { 
        Node* newNode = new Node{ key, end->next };
        end->next = newNode;
        end = newNode;
    }
}

void readList() {
    Node* listEnd = nullptr;
    std::cout << "Enter number of words: " << '\n';
    int n;
    std::cin >> n;
    std::string word;
    for (int i = 0; i < n; i++) {
        std::cout << word << ' ' << i << ':' << '\n';
        std::cin >> word;
        push_back(listEnd, word);
    }
}

void sortArray(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int currMin = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[currMin]) {
                currMin = j;
            }
        }
        int tmp = a[currMin];
        a[currMin] = a[i];
        a[i] = tmp;
    }
}

void printList(Node* end) {
    Node* tmp = end->next;
    while(tmp != end) {
        std::cout << tmp->text << ' ';
        tmp = tmp->next;
    }
    std::cout << tmp->text << '\n';
}

void unite(Node* list) {
    Node* current = list;

    while(current) {
        int lastCurrentChar = current->text[current->text.size() - 1];
        int firstNextChar = current->next->text[current->next->text.size() - 1];
        if (current->text[lastCurrentChar] == firstNextChar) {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            current->text += ("-" + toDelete->text);
            delete toDelete;
        }
    }
}

int main() {
    int a[5] = { 4, 1, 38, 2, 10 };
    sortArray(a, 5);

    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}