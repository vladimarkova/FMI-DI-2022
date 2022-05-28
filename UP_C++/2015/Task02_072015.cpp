#include <iostream>
#include <vector>
using std::cout;
using std::vector;

struct Node {
    int val;
    vector<Node*> children;
    Node(int _val) {
        val = _val;
    }
};

void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    for (int i = 0; i < root->children.size(); i++) {
        deleteTree(root->children[i]);
    }
    delete root;
}

bool member(Node* root, int x) {
    if (root == nullptr) {
        return false;
    }
    if (root->val == x){
        return true;
    }
    for (int i = 0; i < root->children.size(); i++) {
        if (member(root->children[i], x)) {
            return true;
        }
    }
    return false;
}

void filterOdd(Node*& root) {
    if (root == nullptr) {
        return;
    }
    if (root->val % 2 != 0) {
        deleteTree(root);
        root = nullptr;
        return;
    } 
    for (int i = 0; i < root->children.size(); i++) {
        filterOdd(root->children[i]);
        if (root->children[i] == nullptr) {
            root->children.erase(root->children.begin() + i);
            i--;
        }
    }
}

int main() {


    return 0;
}