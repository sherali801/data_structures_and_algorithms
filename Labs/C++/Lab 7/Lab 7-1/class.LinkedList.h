#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "Node.h"

class LinkedList {
private:
  Node * head;
  int count;
public:
  LinkedList();
  ~LinkedList();
  void insertAtTail(int value);
  void insertAt(int value, int i);
  void sort();
  bool compareLinkedLists(LinkedList * headOfOtherList);
  void reverseLinkedList();
  void disply();
  void push(int data);
};

#endif // !LINKED_LIST_H_
