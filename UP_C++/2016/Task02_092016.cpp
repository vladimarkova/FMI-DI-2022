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

void printTree(Node* root, int spaces) {
    if (root == nullptr) {
        return;
    }
    for (int i = 0; i < spaces; i++) {
        cout << ' ';
    }
    cout << root->val << '\n';
    for (int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i], spaces + 3);
    }
}

Node* createTreeAndPrintDepth(int k, int* arr, int n) {
    if (n == 0) {
        cout << "Depth: " << 0 << '\n';
        return nullptr;
    }
    if (n == 1) {
        cout << "Depth: " << 1 << '\n';
        return new Node(arr[0]);
    }
    if (k <= 0) {
        cout << "Depth: " << 0 << '\n';
        return nullptr;
    }
    Node* root = new Node(arr[0]);
    Node* current = root;
    Node* parentOfCurrent = nullptr;
    int currentNumber = 0;
    int depth = 2;
    for (int i = 1 ; i < n; i++) {
        Node* newChild = new Node(arr[i]);
        if (current->children.size() >= k) {
            if (current == root) {
                current = root->children[0];
                parentOfCurrent = root;
                depth++;
            } 
            else if (parentOfCurrent->children.size() >= currentNumber + 2) {
                current = parentOfCurrent->children[currentNumber + 1];
                currentNumber++;
            } 
            else {
                current = parentOfCurrent->children[0]->children[0];
                parentOfCurrent = parentOfCurrent->children[0];
                currentNumber = 0;
                depth++;
            }
        }
        current->children.push_back(newChild);
    }
    cout << "Depth: " << depth << '\n';
    return root; 
}

int main() {
    int arr[14] = { 11, 20, 5, 6, 7, 12, 0, -3, 8, 40, 50, 30, 10, -5 };
    Node* root = createTreeAndPrintDepth(3, arr, 0);
    printTree(root, 0);

    return 0;
}