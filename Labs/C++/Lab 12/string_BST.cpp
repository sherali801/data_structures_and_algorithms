#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class BSTNode {
public:
  string data;
  BSTNode * left;
  BSTNode * right;
  BSTNode() {
    this->data = "";
    this->left = NULL;
    this->right = NULL;
  }
};

class BST {
private:
  BSTNode * root;

  BSTNode * getNewNode(string data) {
    BSTNode * newNode = new BSTNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  BSTNode * insertNode(BSTNode * root, string data) {
    if (root == NULL) {
      root = getNewNode(data);
    } else if (data <= root->data) {
      root->left = insertNode(root->left, data);
    } else {
      root->right = insertNode(root->right, data);
    }
    return root;
  }

  void inorderTraversal(BSTNode * root) {
    if (root == NULL) {
      return;
    }
    inorderTraversal(root->left);
    cout << root->data << ", ";
    inorderTraversal(root->right);
  }

public:

  BST() {
    this->root = NULL;
  }

  void insertNode(string data) {
    this->root = insertNode(this->root, data);
  }

  void inorderTraversal() {
    inorderTraversal(this->root);
    cout << "\n";
  }

};

int main()
{
  BST t;
  t.insertNode("january");
  t.insertNode("february");
  t.insertNode("march");
  t.insertNode("april");
  t.insertNode("may");
  t.insertNode("june");
  t.insertNode("july");
  t.insertNode("august");
  t.insertNode("september");
  t.insertNode("october");
  t.insertNode("november");
  t.insertNode("december");
  t.inorderTraversal();
  _getch();
  return 0;
}

