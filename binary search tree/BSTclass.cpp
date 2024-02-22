#include <iostream>
using namespace std;

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    BinaryTreeNode<int>* root;

    BST() {
        root = nullptr;
    }

    ~BST() {
        delete root;
    }

private:
    bool search(int data, BinaryTreeNode<int>* node) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == data) {
            return true;
        }
        bool ans1 = search(data, node->left);
        bool ans2 = search(data, node->right);
        return ans1 || ans2;
    }

public:
    bool search(int data) {
        return search(data, root);
    }

private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node) {
        if (node == nullptr) {
            BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        if (data <= node->data) {
            node->left = insert(data, node->left);
        }
        else {
            node->right = insert(data, node->right);
        }
        return node;
    }

public:
    void insert(int data) {
        root = insert(data, root);
    }

private:
    BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int>* node) {
        if (node == nullptr) {
            return nullptr;
        }
        else if (node->data > data) {
            node->left = remove(data, node->left);
        }
        else if (node->data < data) {
            node->right = remove(data, node->right);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                BinaryTreeNode<int>* temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                BinaryTreeNode<int>* temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            else {
                BinaryTreeNode<int>* minnode = node->right;
                while (minnode->left != NULL) {
                    minnode = minnode->left;
                }
                int mindata = minnode->data;
                node->data = mindata;
                node->right = remove(mindata, node->right);
                return node;
            }
        }
    }

public:
    void remove(int data) {
        root = remove(data, root);
    }

private:
    void printTree(BinaryTreeNode<int>* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << ":";
        if (node->left != nullptr) {
            cout << "L:" << node->left->data << ",";
        }
        if (node->right != nullptr) {
            cout << "R:" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }

public:
    void print() {
        printTree(root);
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);

    cout << "BST elements:" << endl;
    bst.print();

    return 0;
}
