#include <iostream>
#include <vector>
using std::cout;
using std::vector;

struct Node {
    char sym;
    int val;
    vector<Node*> children;
};

int sumValHelper(Node* u, Node* v, int sum) {
    if (u->sym != v->sym) {
        return 0;
    }

    if (u->children.empty() && v->children.empty()) {
        return sum + u->val + v->val;
    } 

    if (u->children.empty() || v->children.empty()) {
        return 0;
    }

    int genSum = 0;
    for (int i = 0; i < u->children.size(); i++) {
        for (int j = 0; j < v->children.size(); j++) {
            genSum += sumValHelper(u->children[i], v->children[j], sum + u->val + v->val);
        }
    }
    return genSum;
}

int sumVal(Node* u, Node* v) {
    return sumValHelper(u, v, 0);
}

int main() {

    Node* v1 = new Node;
    v1->sym = 'a';
    v1->val = 1;

    Node* v2 = new Node;
    v2->sym = 'b';
    v2->val = 2;

    Node* v3 = new Node;
    v3->sym = 'c';
    v3->val = 3;

    Node* v4 = new Node;
    v4->sym = 'e';
    v4->val = 6;

    Node* v5 = new Node;
    v5->sym = 'f';
    v5->val = 7;

    Node* v6 = new Node;
    v6->sym = 'u';
    v6->val = 9;

    Node* v7 = new Node;
    v7->sym = 'b';
    v7->val = 4;

    Node* v8 = new Node;
    v8->sym = 'd';
    v8->val = 5;

    Node* v9 = new Node;
    v9->sym = 'n';
    v9->val = 10;

    Node* v10 = new Node;
    v10->sym = 's';
    v10->val = 2;

    Node* v11 = new Node;
    v11->sym = 'e';
    v11->val = 7;

    Node* v12 = new Node;
    v12->sym = 'u';
    v12->val = 8;

    Node* v13 = new Node;
    v13->sym = 'n';
    v13->val = 11;

    Node* v14 = new Node;
    v14->sym = 'f';
    v14->val = 6;

    Node* v15 = new Node;
    v15->sym = 's';
    v15->val = 1;

    v1->children.push_back(v2);
    v1->children.push_back(v3);

    v2->children.push_back(v4);
    v2->children.push_back(v5);
    v2->children.push_back(v6);

    v3->children.push_back(v7);
    v3->children.push_back(v8);  

    v4->children.push_back(v9);

    v6->children.push_back(v10);

    v7->children.push_back(v11);
    v7->children.push_back(v12);

    v11->children.push_back(v13);
    v11->children.push_back(v14);

    v12->children.push_back(v15);

    cout << sumVal(v2, v7) << '\n';

    return 0;
}