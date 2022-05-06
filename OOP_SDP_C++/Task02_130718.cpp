#include <iostream>
#include <string>
#include <queue>
#include <fstream>
using std::cout;
using std::string;
using std::queue;
using std::ostream;
using std::ofstream;

struct Node {
    char sym;
    Node* first = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    Node(char _sym) {
        sym = _sym;
    }
};

struct NodeWithLevel {
    Node* node = nullptr;
    int level = 0;
    NodeWithLevel(Node* _node, int _level) {
        node = _node;
        level = _level;
    }
};

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int firstHeight = height(root->first);
    int secondHeight = height(root->second);
    int thirdHeight = height(root->third);
    int maxChildHeight;
    if (firstHeight >= secondHeight && firstHeight >= thirdHeight) {
        maxChildHeight = firstHeight;
    }
    else if (secondHeight >= firstHeight && secondHeight >= thirdHeight) {
        maxChildHeight = secondHeight;
    }
    else {
        maxChildHeight = thirdHeight;
    }
    return 1 + maxChildHeight;
}

string readLast(Node* root) {
    if (root == nullptr) {
        return "";
    }
    int maxLevel = height(root) - 1;
    queue<NodeWithLevel> q;
    q.push(NodeWithLevel(root, 0));
    string word;

    while(!q.empty()) {
        NodeWithLevel current = q.front();
        q.pop();

        if (current.level == maxLevel) {
            word.push_back(current.node->sym);
        }

        if (current.node->first != nullptr) {
            q.push(NodeWithLevel(current.node->first, current.level + 1));
        } 
        if (current.node->second != nullptr) {
            q.push(NodeWithLevel(current.node->second, current.level + 1));
        } 
        if (current.node->third != nullptr) {
            q.push(NodeWithLevel(current.node->third, current.level + 1));
        }
    }
    return word;
}

void helper(Node* root, ostream& fout) {
    if (root == nullptr) {
        fout << '*';
        return;
    }
    fout << '(' << root->sym << ' ';
    helper(root->first, fout);
    fout << ' ';
    helper(root->second, fout);
    fout << ' ';
    helper(root->third, fout);
    fout << ')';
}

void serialize(Node* root, const char* pathToFile) {
    ofstream fout(pathToFile);
    helper(root, fout);
}

int main() {    
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');

    a->first = b;
    a->second = c;
    a->third = d;
    c->first = e;
    d->third = f;

    // cout << readLast(a) << '\n';
    helper(a, cout);
    cout << '\n';

    return 0;
}