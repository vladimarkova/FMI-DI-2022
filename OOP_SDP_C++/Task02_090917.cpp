#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node<T>* next = nullptr;
    Node(T _val) {
        val = _val;
    }
};

bool isSorted(Node<int>* first) {
    if (first == nullptr) {
        return true;
    }
    Node<int>* tmp= first;
    while(tmp->next != nullptr) {
        if (tmp->val > tmp->next->val) {
            return false;
        }
        tmp = tmp->next;
    }
    return true;
}

void addElement(Node<int>*& first, Node<int>*& last, int el) {
    if (first == nullptr) {
        first = new Node<int>(el);
        last = first;
    } else {
        last->next = new Node<int>(el);
        last = last->next;
    }
}

Node<int>* merge(Node<int>* list1First, Node<int>* list2First) {
    Node<int>* result = nullptr;
    Node<int>* endResult = nullptr;
    Node<int>* tmp1 = list1First;
    Node<int>* tmp2 = list2First;
    while(tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->val < tmp2->val) {
            addElement(result, endResult, tmp1->val);
            tmp1 = tmp1->next;
        } else {
            addElement(result, endResult, tmp2->val);
            tmp2 = tmp2->next;
        }
    }
    while(tmp1 != nullptr) {
        addElement(result, endResult, tmp1->val);
        tmp1 = tmp1->next;
    }
    while(tmp2 != nullptr) {
        addElement(result, endResult, tmp2->val);
        tmp2 = tmp2->next;
    }
    return result;
}

Node<int>* mergeSortedLists(Node<Node<int>*>* listOfLists) {
    Node<Node<int>*>* tmp = listOfLists;
    Node<int>* result = nullptr;
    while (tmp != nullptr) {
        if (isSorted(tmp->val)) {
            result = merge(result, tmp->val);
        }
        tmp = tmp->next;
    }
    return result;
}

int main() {
    Node<int>* a1 = new Node<int>(2);
    Node<int>* a2 = new Node<int>(3);
    Node<int>* a3 = new Node<int>(3);
    a1->next = a2;
    a2->next = a3;

    Node<int>* b1 = new Node<int>(4);
    Node<int>* b2 = new Node<int>(3);
    Node<int>* b3 = new Node<int>(3);
    b1->next = b2;
    b2->next = b3;    

    Node<int>* c1 = new Node<int>(1);
    Node<int>* c2 = new Node<int>(5);
    c1->next = c2;

    Node<Node<int>*>* listOfLists = new Node<Node<int>*>(a1);
    listOfLists->next = new Node<Node<int>*>(b1);
    listOfLists->next->next = new Node<Node<int>*>(c1);

    Node<int>* result = mergeSortedLists(listOfLists);
    Node<int>* tmp = result;
    while (tmp != nullptr) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << '\n';

    return 0;
}