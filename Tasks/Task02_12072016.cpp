#include <iostream>
#include <vector>
#include <fstream>

struct Node {
    int val;
    std::vector<Node*> children;
};

int findMaxPath(Node* root) {
    if (!root) {
        return 0;
    }
    if (root->children.size()) {
        return root->val;
    }
    int maxPath = findMaxPath(root->children[0]);
    for (int i = 1; i < root->children.size(); i++) {
        int currentMaxPath = findMaxPath(root->children[i]);
        if (currentMaxPath > maxPath) {
            maxPath = currentMaxPath;
        }
    }
    return root->val + maxPath;
}

bool isDigit(char sym) {
    return sym >= '0' && sym <= '9'; 
}

int readNum(char*& str) {
    if (!isDigit(*str)) {
        std::cerr << "Wrong input" << '\n';
        return 0;
    }
    int num = *str - '0';
    str++;
    while(*str && isDigit(*str)) {
        num *= 10;
        num += (*str - '0');
        str++;
    }
    // std::cout << num << '\n';
    return num;
}

void getStringFromFile(char* fileName, char* tree) {
    std::ifstream ifStr(fileName);
    if (!ifStr) {
        std::cerr << "Error opening file...!" << '\n';
        return;
        // return nullptr;
    }
    int i = -1;
    char ch;
    while(ifStr.get(ch)) {
        if (ch != ' ') {
            *(tree++) = ch;
        }
    }
    *tree = '\0';
}

Node* createTreeHelper(char*& tree) {
    if (*tree == '(') {
            tree++;
    }
    int num;
    Node* root;
    if (isDigit(*tree)) {
        num = readNum(tree);
        root = new Node{num};
    }
    if (*tree == '(') {
        tree++;
        while(*tree != ')') {
            Node* child = createTreeHelper(tree);
            root->children.push_back(child);
        }
        tree++;
    }
    if (*tree == ')') {
        tree++;
    }
    return root;
}

Node* createTree(char* fileName) {
    char* tree;
    getStringFromFile(fileName, tree);
    createTreeHelper(tree);
}

int main() {
    char fileName[10] = "tree.txt";
    char tree[250];
    // getStringFromFile(fileName, tree);
    // std::cout << tree << '\n';

    char test[10] = "12345";
    // std::cout << readNum(test) << '\n';
    // readNum(test);

    return 0;
}