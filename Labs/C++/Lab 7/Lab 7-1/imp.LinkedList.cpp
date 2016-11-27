#include <iostream>
using namespace std;

#include "class.LinkedList.h"

LinkedList::LinkedList() {
  this->head = nullptr;
  this->count = 0;
}

LinkedList::~LinkedList() {
  Node * currentNode = new Node();;
  while (this->head != nullptr) {
    currentNode = this->head;
    this->head = (this->head)->next;
    currentNode->next = nullptr;
    delete currentNode;
  }
}

void LinkedList::insertAtTail(int data) {
  Node * newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;
  this->count++;
  if (this->head != nullptr) {
    Node * currentNode = this->head;
    while (currentNode->next != nullptr) {
      currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    return;
  }
  this->head = newNode;
}

void LinkedList::insertAt(int data, int position) {
  if (position >= 0 && position <= this->count) {
    if (position == 0) {
      this->push(data);
      return;
    } else if (position == this->count) {
      this->insertAtTail(data);
      return;
    }
    Node * currentNode = this->head;
    for (int i = 0; i < position - 1; i++) {
      currentNode = currentNode->next;
    }
    Node * newNode = new Node();
    newNode->data = data;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    this->count++;
  }
}

void LinkedList::sort() {
  if (this->head != nullptr) {
    Node * currentNode = this->head;
    Node * nextNode = new Node();
    Node * previousNode = new Node();
    Node * swap = new Node();
    bool swaped = false;
    do {
      swaped = false;
      nextNode = currentNode->next;
      previousNode = currentNode;
      while (nextNode != nullptr) {
        if (previousNode->data > nextNode->data) {
          swap->data = nextNode->data;
          nextNode->data = previousNode->data;
          previousNode->data = swap->data;
          swaped = true;
        }
        previousNode = nextNode;
        nextNode = nextNode->next;
      }
    } while (swaped);
  }
}

bool LinkedList::compareLinkedLists(LinkedList * headOfOtherList) {
  Node * currentNodeOfFirst = this->head;
  Node * currentNodeOfSecond = headOfOtherList->head;
  while (currentNodeOfFirst != nullptr && currentNodeOfSecond != nullptr) {
    if (currentNodeOfFirst->data != currentNodeOfSecond->data) {
      return false;
    }
    currentNodeOfFirst = currentNodeOfFirst->next;
    currentNodeOfSecond = currentNodeOfSecond->next;
  }
  if (currentNodeOfFirst == nullptr && currentNodeOfSecond == nullptr) {
    return true;
  }
  return false;
}

void LinkedList::reverseLinkedList() {
  if (this->head != nullptr) {
    Node * currentNode = this->head;
    Node * previousNode = nullptr;
    Node * nextNode = new Node();
    while (currentNode != nullptr) {
      nextNode = currentNode->next;//preserve next node
      currentNode->next = previousNode;//reverse arrow
      previousNode = currentNode;//after reverse current node becomes previous node
      currentNode = nextNode;//helps in next iteration
    }
    this->head = previousNode;
  }
}

void LinkedList::disply() {
  if (this->head != nullptr) {
    Node * currentNode = this->head;
    while (currentNode != nullptr) {
      cout << currentNode->data << " ";
      currentNode = currentNode->next;
    }
    cout << "\n";
    delete currentNode;
  }
}

void LinkedList::push(int data) {
  Node * newNode = new Node();
  newNode->data = data;
  this->count++;
  if (this->head != nullptr) {
    newNode->next = this->head;
    this->head = newNode;
    return;
  }
  newNode->next = nullptr;
  this->head = newNode;
}
