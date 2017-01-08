#ifndef BST_NODE_H_
#define BST_NODE_H_

#include <string>
#include <fstream>
using namespace std;

class BSTNode {
public:
  string query;
  string urls;
  fstream * fileHandle;
  BSTNode * left;
  BSTNode * right;
  BSTNode() {
    this->query = "";
    this->urls = "";
    this->fileHandle = new fstream();
    this->left = NULL;
    this->right = NULL;
  }
};

#endif // !BST_NODE_H_
