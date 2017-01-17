#ifndef NODE_H_
#define NODE_H_

class Node {
public:
  int data;
  Node * next;
  Node() {
    this->data = 0;
    this->next = nullptr;
  }
};

#endif // !NODE_H_
