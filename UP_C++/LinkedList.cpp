#include <iostream>
using std::cout;

struct Node {
    int val;
    Node* next = nullptr;
    Node(int _val, Node* _next = nullptr) {
        val = _val;
        next = _next;
    }
};

class LinkedList {
private:
    Node* begin = nullptr;
    Node* end = nullptr;
    int size = 0;

    void copy(const LinkedList& other) {
        free();
        Node* tmp = other.begin;
        while(tmp != nullptr) {
            push_back(tmp->val);
            tmp = tmp->next;
        }
    }
    void free() {
        Node* tmp = begin;
        Node* toDelete;
        while(tmp != nullptr) {
            toDelete = tmp;
            tmp = tmp->next;
            delete toDelete;
        }
        size = 0;
        begin = end = nullptr;
    }
public:
    LinkedList() { }
    LinkedList(const LinkedList& other) {
        copy(other);
    }
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            copy(other);
        }
        return *this;
    }

    void push_back(int x) {
        if (isEmpty()) {
            begin = end = new Node(x, nullptr);
        } else {
            end->next = new Node(x, nullptr);
            end = end->next;
        }
        size++;
    }

    void push_front(int x) {
        if (isEmpty()) {
            begin = end = new Node(x, nullptr);
        } else {
            begin = new Node(x, begin);
        }
        size++;
    }

    void insertAfter(int x, int pos) {
       if (pos == 0) {
           push_front(x);
       } else if (pos == size - 1) {
          push_back(x); 
       } else {
            Node* tmp = begin;
            while(pos--) {
                tmp = tmp->next;
            }
            tmp->next = new Node(x, tmp->next);
       }
       size++;
    }

    void pop_front() {
        if (isEmpty()) {
            cout << "Do not remove from empty stack!!!" << '\n';
            return;
        }
        Node* toDelete = begin;
        if (size == 1) {
            end = nullptr;
        }
        begin = begin->next;
        delete toDelete;
        size--;
    }

    void eraseAfter(int pos) {
        if (pos == 0) {
            pop_front();
        } else if (pos == size - 1) {
            cout << "Invalid index!!!" << '\n';
        } else {
            Node* tmp = begin;
            while(pos--) {
                tmp = tmp->next;
            }
            Node* toDelete = tmp->next;
            tmp->next = toDelete->next;
            delete toDelete;
            size--;
        }

    }

    bool isEmpty() const {
        return begin == nullptr;
    }

    void print() const {
        Node* tmp = begin;
        while (tmp) {
            cout << tmp->val << ' ';
            tmp = tmp->next;
        }
        cout << '\n';
    }

    int count() const {
        return size;
    }

    ~LinkedList() {
        free();
    }
};

int main() {
    LinkedList llist;
    llist.push_back(42);
    llist.push_back(15);
    llist.push_back(8);
    llist.push_back(9);
    llist.push_back(11);
    llist.push_back(1);
    llist.push_back(8);
    llist.push_back(75);
    llist.push_back(0);
    llist.push_back(33);

    llist.print();

    llist.insertAfter(5, 3);
    llist.print();

    // llist.pop_front();
    // llist.print();

    llist.eraseAfter(3);
    llist.print();

    return 0;
}