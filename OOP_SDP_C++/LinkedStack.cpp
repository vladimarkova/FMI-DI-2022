#include <iostream>

struct Node {
  int data;
  Node* next;
  Node(int _data, Node* _next) {
      data = _data;
      next = _next;
  }
};

class LinkedStack {
  Node* top;

  void copy(const LinkedStack& other) {
    top = nullptr;
    Node* tmp = other.top;
    LinkedStack tmpLStack;
    while(tmp) {
        tmpLStack.push(tmp->data);
        tmp = tmp->next;
    }
    while(!tmpLStack.empty()) {
        push(tmpLStack.pop());
    }
  }

  void erase() {
    while(!empty()) {
        pop();
    }
  }
public:
    LinkedStack() {
        top = nullptr;
    }
    LinkedStack(const LinkedStack& other) {
        copy(other);
    }
    LinkedStack& operator=(const LinkedStack& other) {
        if (this != &other) {
            erase();
            copy(other);
        }
        return *this;
    }
    ~LinkedStack() {
        erase();
    }
    bool empty() const {
        return top == nullptr;
    }
    void push(const int x) {
        if (empty()) {
            top = new Node(x, nullptr);
        } else {
            Node* newNode = new Node(x, top);
            top = newNode;
        }
    }
    int pop() {
        if (empty()) {
            return -1;
        }
        int topData = top->data;
        Node* tmp = top;
        top = top->next;
        delete tmp;
        return topData;
    }
    int peek() const {
        if (empty()) {
            return -1;
        }
        return top->data;
    }
    void print() const {
        Node* tmp = top;
        while(tmp) {
          std::cout << tmp->data << ' ';
          tmp = tmp->next;
        }
        std::cout << '\n';
    }
};

int main() {
    LinkedStack s;
    std::cout << s.empty() << '\n';
    s.push(3);
    std::cout << s.empty() << '\n';
    s.push(4);
    s.push(5);
    s.push(12);
    s.push(3);
    s.push(8);
    s.push(100);
    s.push(49);
    s.push(7);

    s.print();

    s.pop();
    s.print();

    s.pop();
    s.print();

    return 0;
}