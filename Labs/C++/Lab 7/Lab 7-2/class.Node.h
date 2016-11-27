#ifndef NODE_H_
#define NODE_H_

class Node {
public:
  int data;
  Node * previous;
  Node * next;
  Node() {
    this->data = 0;
    this->next = nullptr;
    this->previous = nullptr;
  }
};

#endif // !NODE_H_
