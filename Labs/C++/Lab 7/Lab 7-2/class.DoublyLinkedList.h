#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include "class.Node.h"

class DoublyLinkedList {
private:
  Node * head;
  Node * tail;
  int count;
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void createDoublyLinkedList();
  void popFront();
  void popBack();
  void deleteithNode(int position);
  void display();
  void enQueue(int data);
};

#endif // !DOUBLY_LINKED_LIST_H_
