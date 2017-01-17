#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <conio.h>
using namespace std;

#include "class.BSTNode.h"

class BST {
  private:
    BSTNode * root;

    BSTNode * insert(BSTNode * root, string query, string urls, fstream * fileHandle) {
      if (root == NULL) {
        root = getNewNode(query, urls, fileHandle);
      } else if (query <= root->query) {
        root->left = insert(root->left, query, urls, fileHandle);
      } else {
        root->right = insert(root->right, query, urls, fileHandle);
      }
      return root;
    }

    BSTNode * find(BSTNode * root, string query) {
      if (root == NULL) {
        return NULL;
      } else if (query == root->query) {
        return root;
      } else if (query <= root->query) {
        return find(root->left, query);
      } else {
        return find(root->right, query);
      }
    }

    BSTNode * minimum(BSTNode * root) {
      if (root == NULL) {
        cout << "Empty Tree\n";
        return NULL;
      }
      if (root->left == NULL) {
        return root;
      } else {
        return minimum(root->left);
      }
    }

    BSTNode * erase(BSTNode * root, string query) {
      if (root == NULL) {
        return root;
      } else if (query < root->query) {
        root->left = erase(root->left, query);
      } else if (query > root->query) {
        root->right = erase(root->right, query);
      } else {
        if (root->left == NULL && root->right == NULL) {
          delete root;
          root = NULL;
        } else if (root->left == NULL) {
          BSTNode * temp = root;
          root = root->right;
          delete temp;
        } else if (root->right == NULL) {
          BSTNode * temp = root;
          root = root->left;
          delete temp;
        } else {
          BSTNode * temp = minimum(root->right);
          root->query = temp->query;
          root->right = erase(root->right, temp->query); 
        }
      }
      return root;
    }

  public:
    BST() {
      this->root = NULL;
    }

    BSTNode * getNewNode(string query, string urls, fstream * fileHandle) {
      BSTNode * newNode = new BSTNode();
      newNode->query = query;
      newNode->urls = urls;
      newNode->fileHandle = fileHandle;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
    }

    void insert(string query, string urls, fstream * fileHandle) {
      this->root = insert(this->root, query, urls, fileHandle);
    }

    BSTNode * find(string query) {
      return find(this->root, query);
    }

    void erase(string query) {
      this->root = erase(this->root, query);
    }

    void clear() {
      while (this->root != NULL) {
        this->erase((this->root)->query);
      }
    }
};

#endif // !BST_H_
