#include <iostream>
#include <queue>
#include <algorithm>

struct Node {
    char text;
    Node* left = nullptr;
    Node* right = nullptr;
};

int height(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + std::max(height(root->left), height(root->right));
}

void printText(Node* root) {
    if (!root) {
        return;
    }
    int treeHeight = height(root);
    std::queue<Node*> q;
    int currentNodesNumber = 0;
    int nextNodesNumber = 0;
    q.push(root);
    currentNodesNumber++;
    int currentHeight = 0;
    while(!q.empty() && currentHeight < treeHeight) {
        Node* current = q.front();
        q.pop();
        if (!current) {
            std::cout << ' ';
            q.push(nullptr);
            q.push(nullptr);
        } else {
            std::cout << current->text;
            q.push(current->left);
            q.push(current->right);
        }
        currentNodesNumber--;
        nextNodesNumber += 2;
        if (!currentNodesNumber) {
            currentNodesNumber = nextNodesNumber;
            nextNodesNumber = 0;
            std::cout << '\n';
            currentHeight++;
        }
    }
}

int main() {
    Node a{'I'};
    Node a{'a'};
    Node a{'m'};
    Node a{'g'};
    Node a{'o'};
    Node a{'o'};
    Node a{'d'};
    Node a{'a'};
    Node a{'t'};
    Node a{'s'};
    Node a{'o'};
    Node a{'l'};
    Node a{'v'};
    Node a{'i'};
    Node a{'n'};
    Node a{'g'};
    Node a{'p'};
    Node a{'r'};
    Node a{'o'};
    Node a{'b'};
    Node a{'l'};
    Node a{'e'};
    Node a{'m'};
    Node a{'s'};
    Node a{'!'};

    return 0;
}