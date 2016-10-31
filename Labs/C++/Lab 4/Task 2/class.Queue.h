#pragma once

#ifndef QUEUE_H_
#define QUEUE_H_

#include "class.Node.h"

class Queue {
private:
  Node * front;
  Node * rear;
  int size;
public:
  Queue();
  ~Queue();
  bool isEmpty();
  void clear();
  void enQueue(int element);
  void deQueue();
  const Node * getFirstNode();
  void print();
};

#endif // !QUEUE_H_
