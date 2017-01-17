#ifndef HEAP_NODE_H_
#define HEAP_NODE_H_

class HeapNode {
public:
  int key;
  double data;
  HeapNode() { }
  HeapNode(int key, int data) {
    this->key = key;
    this->data = data;
  }
};

#endif // !HEAP_NODE_H_
