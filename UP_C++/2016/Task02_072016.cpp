#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::ifstream;
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

Node* createTree(const char* pathToFile) {
    ifstream fin(pathToFile);
    Node* imaginaryParentOfRoot = new Node(42);
    Node* current = imaginaryParentOfRoot;
    Node* parentOfCurrent = nullptr;
    while(!fin.eof()) {
        char currentSym;
        fin >> currentSym;
        if (currentSym == '(') {
            if (fin.peek() == ')') {
                current = parentOfCurrent;
                fin.ignore();
            }
            else if(fin.peek() >= '0' && fin.peek() <= '9') {
                int number;
                fin >> number;
                Node* newChild = new Node(number);
                current->children.push_back(newChild);
                parentOfCurrent = current;
                current = newChild;
            }
        } 
        else if (currentSym == ')') {
            current = parentOfCurrent;
        }
    }
    Node* root = imaginaryParentOfRoot->children[0];
    delete imaginaryParentOfRoot;
    return root;
}

void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    for (int i = 0; i < root->children.size(); i++) {
        deleteTree(root->children[i]);
    }
    delete root;
}

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    // int leftHeight = height(root->left);
    // int rightHeight = height(root->right);
    // if (leftHeight > rightHeight) {
    //     return leftHeight + 1;
    // } else {
    //     return rightHeight + 1;
    // }
    int maxSubtreeHeight = 0;
    for (int i = 0; i < root->children.size(); i++) {
        int currentSubtreeHeight = height(root->children[i]);
        if (currentSubtreeHeight > maxSubtreeHeight) {
            maxSubtreeHeight = currentSubtreeHeight;
        }
    }
    return maxSubtreeHeight + 1;
}

int findHeaviestBranch(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->children.size() == 0) {
        return root->val;
    }
    int maxSubtreeBranch = findHeaviestBranch(root->children[0]);
    for (int i = 1; i < root->children.size(); i++) {
        int currentSubtreeBranch = findHeaviestBranch(root->children[i]);
        if (currentSubtreeBranch > maxSubtreeBranch) {
            maxSubtreeBranch = currentSubtreeBranch;
        }
    }
    return maxSubtreeBranch + root->val;
}

int calculateHeaviestBranch(const char* pathToFile) {
    Node* root = createTree(pathToFile);
    int heaviestBranch = findHeaviestBranch(root);
    deleteTree(root);
    return heaviestBranch;
}

int main() {
    // printTree(createTree("test.txt"), 0);
    cout << "Heaviest branch: " << calculateHeaviestBranch("test.txt") << '\n';

    return 0;
} 