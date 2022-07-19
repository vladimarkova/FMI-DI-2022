#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using std::cout;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int _val, Node* _left = nullptr, Node* _right = nullptr) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class BST {
private:
    Node* root = nullptr;
public: 
    BST() { };
    void insert(int val) {
        insertHelper(root, val);
    }
    BST(const BST& other)
        : root(copyHelper(other.root)) { }
    BST& operator=(const BST& other) {
        if (this != &other) {
            clean();
            root = copyHelper(other.root);
        }
        return *this;
    }
    ~BST() {
        clean();
    }
    int height() const {
        return heightHelper(root);
    }
    int size() const {
        return sizeHelper(root);
    }
    bool isBalanced() const {
        return isBalancedHelper(root);
    }
    std::vector<int> preOrder() const {
        std::vector<int> path;
        preOrderHelper(root, path);
        return path;
    }
    std::vector<int> inOrder() const {
        std::vector<int> path;
        inOrderHelper(root, path);
        return path;
    }
    std::vector<int> postOrder() const {
        std::vector<int> path;
        postOrderHelper(root, path);
        return path;
    }
    void erase(int val) {
        eraseHelper(root, val);
    }
    void clean() {
        freeHelper(root);
    }
    void print() const {
        std::vector<int> path = inOrder();
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << ' ';
        }
        cout << '\n';
    }
private:
    static void insertHelper(Node*& root, int val) {
        if (!root) {
            root = new Node(val, nullptr, nullptr);
            return;
        }
        if (val < root->val) {
            insertHelper(root->left, val);
        } else {
            insertHelper(root->right, val);
        }
    }
    static int heightHelper(const Node* root) {
        if (!root) {
            return 0;
        }
        int leftHeight = heightHelper(root->left);
        int rightHeight = heightHelper(root->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
    static int sizeHelper(const Node* root) {
        if (!root) {
            return 0;
        }
        int leftSize = sizeHelper(root->left);
        int rightSize = sizeHelper(root->right);
        return leftSize + rightSize + 1;
    }
    static bool isBalancedHelper(const Node* root) {
        if (!root) {
            return true;
        }
        int leftHeight = heightHelper(root->left);
        int rightHeight = heightHelper(root->right);
        return isBalancedHelper(root->left) && 
               isBalancedHelper(root->right) &&
               std::abs(leftHeight - rightHeight) <= 1; 
    }
    static void preOrderHelper(const Node* root, std::vector<int>& path) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        preOrderHelper(root->left, path);
        preOrderHelper(root->right, path);
    }
    static void inOrderHelper(const Node* root, std::vector<int>& path) {
        if (!root) {
            return;
        }
        inOrderHelper(root->left, path);
        path.push_back(root->val);
        inOrderHelper(root->right, path);
    }
    static void postOrderHelper(const Node* root, std::vector<int>& path) {
        if (!root) {
            return;
        }
        postOrderHelper(root->left, path);
        postOrderHelper(root->right, path);
        path.push_back(root->val);
    }
    static void BFS(const Node* root, std::vector<int>& path) {
        if (!root) {
            return;
        }
        std::queue<const Node*> q;
        q.push(root);
        while(!q.empty()) {
            const Node* front = q.front();
            q.pop();
            path.push_back(front->val);
            q.push(front->left);
            q.push(front->right);
        }
    }
    static void eraseHelper(Node*& root, int val) {
        if (root->val == val) {
            if (!root->left && !root->right) {
                Node* toDelete = root;
                root = nullptr;
                delete toDelete;
            } else if(root->left && !root->right) {
                Node* child = root->left;
                delete root;
                root = child;
            } else if (!root->left && root->right) {
                Node* child = root->right;
                delete root;
                root = child;
            } else {
                Node*& maxLeftChild = findMax(root->left);
                int childVal = maxLeftChild->val;
                root->val = childVal;
                Node* toDelete = maxLeftChild;
                maxLeftChild = maxLeftChild->left;
                delete toDelete;
            }
        } 
        else if (root->val > val) {
            eraseHelper(root->left, val);
        }
        else {
            eraseHelper(root->right, val);
        }
    }
    static Node*& findMin(Node*& root) {
        if (!root->left) {
            return root;
        }
        return findMin(root->left);
    }
     static Node*& findMax(Node*& root) {
        if (!root->right) {
            return root;
        }
        return findMax(root->right);
    }
    static void freeHelper(Node*& root) {
        if (!root) {
            return;
        }
        freeHelper(root->left);
        freeHelper(root->right);
        delete root;
        root = nullptr;
    }
    static Node* copyHelper(const Node* other) {
        if (!other) {
            return nullptr;
        }
        Node* root = new Node(other->val, nullptr, nullptr);
        root->left = copyHelper(other->left);
        root->right = copyHelper(other->right);

        return root;
    }
};

int main() {
    BST tree;
    tree.insert(9);
    tree.insert(5);
    tree.insert(11);
    tree.insert(3);
    tree.insert(4);
    tree.insert(10);
    tree.insert(12);
    tree.insert(1);
    tree.insert(15);

    tree.print();

    tree.erase(12);

    tree.print();


    return 0;
}