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
  int size();
  void display();
  void insertAtHead(int data);
  void insertAtTail(int data);
  void deleteFromHead();
  void deleteFromTail();
  void insert(int position, int data);
  void erase(int position);
  void reverse();
  void mid();
};

#endif // !LINKED_LIST_H_
