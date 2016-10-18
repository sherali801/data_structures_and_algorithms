#pragma once

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "struct.Node.h"

class LinkedList {
private:
  Node * head;
  int count;
public:
  LinkedList();
  ~LinkedList();
  bool empty();
  int size();
  void show();
  int front();
  int back();
  void pushFront(int data);
  void pushBack(int data);
  void popFront();
  void popBack();
  void insert(int position, int data);
  void erase(int position);
  void reverse();
};

#endif // !LINKED_LIST_H_
