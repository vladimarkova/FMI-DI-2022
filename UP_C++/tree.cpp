#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int key;
    std::vector<Node*> children; 
};

void DFS(Node* root) {
    if (!root) {
        return;
    }
    std::cout << root->key << ' ';
    for (int i = 0; i < root->children.size(); i++) {
        DFS(root->children[i]);
    }
}

void BFS(Node* root) {
    if (!root) {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        const Node* front = q.front();
        q.pop();
        std::cout << root->key << ' ';
        for (int i = 0; i < root->children.size(); i++) {
            q.push(root->children[i]);
        }   
    }
}