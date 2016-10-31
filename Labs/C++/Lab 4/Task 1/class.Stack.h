#pragma once

#ifndef STACK_H_
#define STACK_H_

#include "class.Node.h"

class Stack {
private:
  Node * top;
  int count;
  int size;
  int element;
public:
  Stack(int size);
  ~Stack();
  void push(int element);
  void pop();
  bool isEmpty();
  bool isFull();
  const Node * peek();
  int getStackSize();
  void print();
};

#endif // !STACK_H_
