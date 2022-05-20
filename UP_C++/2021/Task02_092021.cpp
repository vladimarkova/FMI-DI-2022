#include <iostream>
#include <vector>
#include <utility>
using std::cout;
using std::vector;
using std::pair;

struct Node {
    int val;
    vector<Node*> children;
    Node(int _val) {
        val = _val;
    }
};

class TreeSeq {
    vector<pair<int, int>> pairs;

public:
    pair<int, int> getPair(int i) const {
        return pairs[i];
    }

    int length() const {
        return pairs.size();
    }

    bool isCorrect() const {
        if (pairs.empty()) {
            return true;
        }
        if (pairs[0].first != 0) {
            return false;
        }
        int currentMaxLevel = 0;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i].first <= 0) {
                return false;
            }
            if (pairs[i].first > currentMaxLevel + 1) {
                return false;
            }
            if (pairs[i].first == currentMaxLevel + 1) {
                currentMaxLevel = pairs[i].first;
            }
        }
        return true;
    }
};

Node* createTree(const TreeSeq& seq) {
    if (!seq.isCorrect() || seq.length() == 0) {
        return nullptr;
    }
    Node* root = new Node(seq.getPair(0).second);
    vector<Node*> lastNodesInEachLevel;
    lastNodesInEachLevel.push_back(root);

    for (int i = 1; i < seq.length(); i++) {
        int currentLevel = seq.getPair(i).first;
        Node* newChild = new Node(seq.getPair(i).second);
        lastNodesInEachLevel[currentLevel - 1]->children.push_back(newChild);
        if (currentLevel == lastNodesInEachLevel.size()) {
            lastNodesInEachLevel.push_back(newChild);
        } else {
            lastNodesInEachLevel[currentLevel] = newChild;
        }
    }
    return root;
}

int main() {


    return 0;
}