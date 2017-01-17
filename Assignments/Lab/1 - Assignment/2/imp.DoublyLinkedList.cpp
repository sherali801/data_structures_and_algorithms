#include <iostream>
using namespace std;

#include "class.DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->count = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
  while (this->head != nullptr) {
    this->popFront();
  }
  delete this->head;
  delete this->tail;
}

void DoublyLinkedList::createDoublyLinkedList() {
  for (int i = 0; i < 5; i++) {
    this->enQueue(i + 1);
  }
}

void DoublyLinkedList::popFront() {
  if (this->head != nullptr) {
    this->count--;
    Node * tempNode = this->head;
    this->head = (this->head)->next;
    tempNode->next = nullptr;
    delete tempNode;
    (this->head)->previous = nullptr;
  }
}

void DoublyLinkedList::popBack() {
  if (this->head != nullptr) {
    this->count--;
    Node * tempNode = this->tail;
    this->tail = (this->tail)->previous;
    tempNode->previous = nullptr;
    delete tempNode;
    (this->tail)->next = nullptr;
  }
}

void DoublyLinkedList::deleteithNode(int position) {
  if (this->head != nullptr && (position >= 0 && position <= this->count)) {
    if (position == 1) {
      this->popFront();
      return;
    } else if (position == this->count) {
      this->popBack();
      return;
    }
    Node * currentNode = this->head;
    for (int i = 0; i < position - 2; i++) {
      currentNode = currentNode->next;
    }
    Node * tempNode = currentNode->next;
    currentNode->next = (currentNode->next)->next;
    (currentNode->next)->previous = currentNode;
    tempNode->next = nullptr;
    tempNode->previous = nullptr;
    delete tempNode;
    this->count--;
  }
}

void DoublyLinkedList::display() {
  if (this->head != nullptr) {
    Node * currentNode = head;
    while (currentNode != nullptr) {
      cout << currentNode->data << " ";
      currentNode = currentNode->next;
    }
    cout << "\n";
    delete currentNode;
  }
}

void DoublyLinkedList::enQueue(int data) {
  this->count++;
  Node * newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;
  if (this->head != nullptr) {
    newNode->previous = tail;
    tail->next = newNode;
    tail = newNode;
    return;
  }
  newNode->previous = nullptr;
  this->head = newNode;
  this->tail = newNode;
}

