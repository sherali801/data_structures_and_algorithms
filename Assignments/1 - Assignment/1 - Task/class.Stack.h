#pragma once

#ifndef STACK_H_
#define STACK_H_

#include "class.Node.h"

class Stack {
private:
  Node * top;
public:
  Stack();
  void push(int xCoordinate, int yCoordinate);
  Node * pop();
  void emptyStack();
  Node * getTop();
  void print();
};

#endif // !STACK_H_
