#include <iostream>
#include <vector>
#include <utility>

struct Node {
    int value;
    std::vector<Node*> children;
};

std::vector<std::pair<int, int>> readSeq() {
    int level;
    int value;
    int size;
    // std::cout << "Enter sequence size: " << '\n';
    std::cin >> size;
    std::vector<std::pair<int, int>> treeSeq;
    for (int i = 0; i < size; i++) {
        // std::cout << "Enter level: " << '\n';
        std::cin >> level;
        // std::cout << "Enter value: " << '\n';
        std::cin >> value;
        treeSeq.push_back({level, value});
        // treeSeq.push_back(std::pair<int, int>(level, value));
    }
    return treeSeq;
}

void printSeq(std::vector<std::pair<int, int>>& treeSeq) {
    for (int i = 0; i < treeSeq.size(); i++) {
        std::cout<< '(' << treeSeq[i].first << ", " << treeSeq[i].second << ") ";
    }
    std::cout << '\n';
}

int fillTree(Node* root, std::vector<std::pair<int, int>>& treeSeq, int current) {
    int childId = current + 1;

    while(childId < treeSeq.size() && treeSeq[current].first + 1 == treeSeq[childId].first) {
        root->children.push_back(new Node{treeSeq[childId].second});
        childId = fillTree(root->children.back(), treeSeq, childId);
    }
    return childId;
}

Node* createTree(std::vector<std::pair<int, int>>& treeSeq) {
    if (treeSeq.empty() || treeSeq[0].first != 0) {
        std::cout << "Invalid input!" << '\n';
        return nullptr;
    }
    Node* root = new Node{treeSeq[0].second};
    int current = 0;
    int idx = fillTree(root, treeSeq, current);
    if (idx == treeSeq.size()){
        return root;
    }
    return nullptr;
}

void printTree(Node* root, int level) {
    if (root) {
        std::cout << '(' << level << ", " << root->value << ") ";
        for (int i = 0; i < root->children.size(); i++) {
            printTree(root->children[i], level + 1);
        }
    }
}

void deleteTree(Node*& root) {
    if (!root) {
        return;
    }
    Node* toDelete = root;
    for (int i = 0; i < root->children.size(); i++) {
        deleteTree(root->children[i]);
    }
    delete toDelete;
    root = nullptr;
}

int main() {
    std::vector<std::pair<int, int>> treeSeq = readSeq();
    // printSeq(treeSeq);

    Node* root = createTree(treeSeq);
    printTree(root, 0);
    std::cout << '\n';
    deleteTree(root);

    // Node test1{3};
    // Node* test2 = new Node{3};

    return 0;
}

/*
    8
    0 5
    1 4
    1 5
    2 3
    1 6
    2 2
    3 3
    2 5
*/