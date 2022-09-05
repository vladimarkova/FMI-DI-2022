#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int val;
    std::vector<Node*> children;
};

int height(Node* root) {
    if (!root) {
        return 0;
    }
    if (root->children.empty()) {
        return 1;
    }
    int maxHeight = height(root->children[0]);
    for (int i = 1; i < root->children.size(); i++) {
        int currHeight = height(root->children[i]);
        if (currHeight > maxHeight) {
            maxHeight = currHeight;
        }
    }
    return 1 + maxHeight;
}

Node* createTree(int arr[], int n, int k) {
    if (!n) {
        return nullptr;
    }
    std::queue<Node*> q;
    Node* root = new Node{arr[0]};
    q.push(root);
    int currentIndex = 1;

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        for (int i = 0; (i < k) && currentIndex < n; i++) {
            Node* child = new Node{arr[currentIndex++]};
            curr->children.push_back(child);
            q.push(child);
        }
    }
    std::cout << height(root) << std::endl;
    return root;
}

int main() {


    return 0;
}