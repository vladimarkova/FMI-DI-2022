#include <iostream>
#include <queue>
#include <new>
using std::cout;
using std::queue;

struct Node {
    char text;
    Node* left = nullptr;
    Node* right = nullptr;
};

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight < rightHeight) {
        return rightHeight + 1;
    }
    return leftHeight + 1;
}


enum class type {
    real_ptr,
    end_of_level,

};

struct better_pointer {
    Node* ptr{ nullptr };
    type t;

};

void printText(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<better_pointer> q;
    q.push({ root, type::real_ptr });
    q.push({nullptr, type::end_of_level });

    int level = 1;

    int treeHeight = height(root);

    while (level <= treeHeight) {
        better_pointer tmp = q.front();
        q.pop();
        if (tmp.ptr == nullptr) {
            if(tmp.t == type::end_of_level) {
                std::cout << std::endl;
                q.push({nullptr, type::end_of_level });
                level++;
            } else {
                cout << " ";
                q.push({ nullptr, type::real_ptr });
                q.push({ nullptr, type::real_ptr });
            }
        } else {
            cout << tmp.ptr->text;
            q.push({ tmp.ptr->left, type::real_ptr });
            q.push({ tmp.ptr->right, type::real_ptr });
        }
    }
    cout << '\n';
}

int main() {
    Node* a = new Node;
    a->text = 'a';
    Node* b = new Node;
    b->text = 'b';
    Node* c = new Node;
    c->text = 'c';
    Node* d = new Node;
    d->text = 'd';
    Node* e = new Node;
    e->text = 'e';
    Node* f = new Node;
    f->text = 'f';
    Node* g = new Node;
    g->text = 'g';
    Node* h = new Node;
    h->text = 'h';

    a->left = b;
    a->right = c;
    b->right = d;
    c->left = e;
    c->right = f;
    d->left = g;
    d->right = h;

    // cout << "height: " << height(a) << '\n';

    printText(a);

    int* myptr;
    myptr = new (std::nothrow) int[5];

    if (!myptr){ // !myptr <----> myptr == nullptr |da|
        // ...
    }

    int* const gosho = new int(5);
    *gosho = 7; 

    int myA = 42;
    const int& myARef = myA; // no point in const after int&, syntax not allowed

    char myArr[10] = {'a',};

    int matrix[2][3] = {
        2, 3,
        4, 5,
        6, 7
    };

    int myB = 6;
    // myARef = myB; 
    typedef const int gosho1;
    gosho1 myg = 15;
    // myg = 8;

    using pesho = const int;
    pesho myNasko = 9;

    int* myAptr = &myA;
    (*myAptr);

    delete[] myptr;

    return 0;
}