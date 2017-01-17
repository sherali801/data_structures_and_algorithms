#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int max(int left, int right) {
  return ((left > right) ? left : right); 
}

int minValueLocation(int arr[], int n) {
  int min = 0, location = 0;
  min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
      location = i;
    }
  }
  return location;
}

class BSTNode {
  public:
    int data;
    BSTNode * left;
    BSTNode * right;
    BSTNode() {
      this->data = 0;
      this->left = NULL;
      this->right = NULL;
    }
};

class BST {
  private:
    BSTNode * root;

    BSTNode * getNewNode(int data) {
      BSTNode * newNode = new BSTNode();
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
    }

    BSTNode * insertNode(BSTNode * root, int data) {
      if (root == NULL) {
        root = getNewNode(data);
      } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
      } else {
        root->right = insertNode(root->right, data);
      }
      return root;
    }

    BSTNode * deleteNode(BSTNode * root, int data) {
      if (root == NULL) {
        return root;
      } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
      } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
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
          BSTNode * temp = minValue(root->right);
          root->data = temp->data;
          root->right = deleteNode(root->right, temp->data);
        }
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

    void preorderTraversal(BSTNode * root) {
      if (root == NULL) {
        return;
      }
      cout << root->data << ", ";
      preorderTraversal(root->left);
      preorderTraversal(root->right);
    }

    void postorderTraversal(BSTNode * root) {
      if (root == NULL) {
        return;
      }
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      cout << root->data << ", ";
    }

    void allLeaves(BSTNode * root) {
      if (root == nullptr) {
        return;
      }
      if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << ", ";
        return;
      }
      allLeaves(root->left);
      allLeaves(root->right);
    }

    void printPaths(BSTNode * root) {
      if (root == nullptr) {
        return;
      }
      if (root->left == nullptr && root->right == nullptr) {
        printPath(this->root, root);
        return;
      }
      printPaths(root->left);
      printPaths(root->right);
    }

    void printPath(BSTNode * root, BSTNode * leafNode) {
      if (root == leafNode) {
        cout << root->data << "\n";
        return;
      }
      cout << root->data << ", ";
      if (leafNode->data <= root->data) {
        printPath(root->left, leafNode);
      } else {
        printPath(root->right, leafNode);
      }
    }

    void minCost(BSTNode * root) {
      int totalLeaves = 0;
      countLeaves(this->root, totalLeaves);
      int * intArray = new int[totalLeaves];
      BSTNode ** arr = new BSTNode*[totalLeaves];
      int i = 0;
      populateArrayWithLeaves(this->root, arr, i);
      int sum = 0;
      for (i = 0; i < totalLeaves; i++) {
        sum = 0;
        pathSum(this->root, arr[i], sum);
        intArray[i] = sum;
      }
      int location = minValueLocation(intArray, totalLeaves);
      printPath(this->root, arr[location]);
    }

    void countLeaves(BSTNode * root, int &totalLeaves) {
      if (root == nullptr) {
        return;
      }
      if (root->left == nullptr && root->right == nullptr) {
        totalLeaves++;
        return;
      }
      countLeaves(root->left, totalLeaves);
      countLeaves(root->right, totalLeaves);
    }

    void populateArrayWithLeaves(BSTNode * root, BSTNode ** arr, int &i) {
      if (root == nullptr) {
        return;
      }
      if (root->left == nullptr && root->right == nullptr) {
        arr[i] = root;
        i++;
        return;
      }
      populateArrayWithLeaves(root->left, arr, i);
      populateArrayWithLeaves(root->right, arr, i);
    }

    void pathSum(BSTNode * root, BSTNode * leafNode, int &sum) {
      if (root == leafNode) {
        sum = sum + root->data;
        return;
      }
      sum = sum + root->data;
      if (leafNode->data <= root->data) {
        pathSum(root->left, leafNode, sum);
      } else {
        pathSum(root->right, leafNode, sum);
      }
    }

    void countNodes(BSTNode * root, int & count) {
      if (root == nullptr) {
        return;
      }
      count++;
      countNodes(root->left, count);
      countNodes(root->right, count);
    }

    int height(BSTNode * root) {
      if (root == NULL) {
        return -1;
      } else {
        return max(height(root->left), height(root->right)) + 1;
      }
    }

    BSTNode * searchNode(BSTNode * root, int data) {
      if (root == NULL) {
        return NULL;
      } else if (data == root->data) {
        return root;
      } else if (data <= root->data) {
        return searchNode(root->left, data);
      } else {
        return searchNode(root->right, data);
      }
    }

    BSTNode * minValue(BSTNode * root) {
      if (root == NULL) {
        cout << "Empty Tree\n";
        return NULL;
      }
      if (root->left == NULL) {
        return root;
      } else {
        return minValue(root->left);
      }
    }

    void fifthMax(BSTNode * root, int * arr, int &i) {
      if (root == nullptr) {
        return;
      }
      fifthMax(root->left, arr, i);
      arr[i++] = root->data;
      fifthMax(root->right, arr, i);
    }

  public:
    BST() {
      this->root = NULL;
    }

    void insertNode(int data) {
      this->root = insertNode(this->root, data);
    }

    void deleteNode(int data) {
      this->root = deleteNode(this->root, data);
    }

    void inorderTraversal() {
      inorderTraversal(this->root);
      cout << "\n";
    }

    void preorderTraversal() {
      preorderTraversal(this->root);
      cout << "\n";
    }

    void postorderTraversal() {
      postorderTraversal(this->root);
      cout << "\n";
    }

    void allLeaves() {
      allLeaves(this->root);
      cout << "\n";
    }

    void printPaths() {
      printPaths(this->root);
    }

    void minCost() {
      minCost(this->root);
    }

    int countNodes() {
      int count = 0;
      countNodes(this->root, count);
      return count;
    }

    int height() {
      return height(this->root);
    }

    BSTNode * searchNode(int data) {
      return searchNode(this->root, data);
    }

    BSTNode * minValue() {
      return minValue(this->root);
    }

    int fifthMax() {
      int totalNodes = countNodes();
      int * arr = new int[totalNodes];
      int i = 0;
      fifthMax(this->root, arr, i);
      return arr[totalNodes - 5];
    }

};

int main()
{
  BST t;
  int size, num;
  cout << "Enter Size: ";
  cin >> size;
  for (int i = 0; i < size; i++) {
    cout << "Enter Number to insert: ";
    cin >> num;
    t.insertNode(num);
  }
  cout << "Enter Number to delete: ";
  cin >> num;
  t.deleteNode(num);
  cout << "InOrder: ";
  t.inorderTraversal();
  cout << "preOrder: ";
  t.preorderTraversal();
  cout << "postOrder: ";
  t.postorderTraversal();
  cout << "All Leaves: ";
  t.allLeaves();
  cout << "Paths from root to leaves:\n";
  t.printPaths();
  cout << "MinCost Path: ";
  t.minCost();
  cout << "Node Count: " << t.countNodes() << "\n";
  cout << "Height: " << t.height() << "\n";
  cout << "Enter Number to search: ";
  cin >> num;
  BSTNode * node = t.searchNode(num);
  cout << (node == NULL ? "Not found" : "Found") << "\n";
  t.deleteNode(num);
  node = t.minValue();
  cout << "Min Value: " << node->data << "\n";
  cout << "Fifth Max: " << t.fifthMax() << "\n";
  _getch();
  return 0;
}

