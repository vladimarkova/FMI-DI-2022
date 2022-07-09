#include <iostream>
#include <vector>
#include <utility>

struct Node {
    int val;
    std::vector<Node*> children;
    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// TreeSeq ---> vector<pair<int, int>>

// validateTreeSeq()...

Node* makeTree(std::vector<std::pair<int, int>> treeSeq) {
    Node* root = new Node(treeSeq[0].second, {});
    int allLevels = 4;

    int currentLevel = 0;
    int currentStart = currentLevel;
    int lastVisited = 0;

    while(currentLevel < allLevels) {
        int i = lastVisited + 1;
        while(treeSeq[i].first == currentLevel + 1) {
            root->children.push_back(new Node(treeSeq[i].second, {}));
            lastVisited++;
        }
        currentLevel++;
    }
    return root;
}

int main() {

    return 0;
}