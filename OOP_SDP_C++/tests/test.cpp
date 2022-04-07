#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};  

class LinkedList {
    private:
     Node* first;
    
    public:
     LinkedList() {
        first = NULL;
     };

    void addNode(int data) {

    };
};

int main() {
    LinkedList myList;
    myList.addNode(5);

    return 0;
}