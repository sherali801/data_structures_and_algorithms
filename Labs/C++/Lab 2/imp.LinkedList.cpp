#include <iostream>
using namespace std;

#include "class.LinkedList.h"

LinkedList::LinkedList() {
  this->head = nullptr;
  this->count = 0;
}

LinkedList::~LinkedList() { }

bool LinkedList::empty() {
  return ((this->head == nullptr) ? true : false);
}

int LinkedList::size() {
  return this->count;
}

void LinkedList::show() {
  if (this->head != nullptr) {
    Node * temp = this->head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "\n";
  }
}

int LinkedList::front() {
  if (this->head != nullptr) {
    return this->head->data;
  } else {
    return NULL;
  }
}

int LinkedList::back() {
  if (this->head != nullptr) {
    Node * temp = this->head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    return temp->data;
  }
  return NULL;
}

void LinkedList::pushFront(int data) {
  Node * newNode = new Node();
  newNode->data = data;
  if (this->head != nullptr) {
    newNode->next = this->head;
    this->head = newNode;
    this->count++;
    return;
  }
  newNode->next = nullptr;
  this->head = newNode;
  this->count++;
}

void LinkedList::pushBack(int data) {
  Node * newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;
  if (this->head != nullptr) {
    Node * temp = this->head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    this->count++;
    return;
  }
  this->head = newNode;
  this->count++;
}

void LinkedList::popFront() {
  if (this->head != nullptr) {
    this->head = (this->head)->next;
    this->count--;
  }
}

void LinkedList::popBack() {
  if (this->head != nullptr) {
    Node * temp = this->head;
    for (int i = 0; i < this->count - 2; i++) {
      temp = temp->next;
    }
    temp->next = nullptr;
    this->count--;
  }
}

void LinkedList::insert(int position, int data) {
  if (this->head != nullptr && (position >= 0 && position <= this->count)) {
    if (position == 0) {
      this->pushFront(data);
      return;
    }
    Node * temp = this->head;
    for (int i = 0; i < position - 1; i++) {
      temp = temp->next;
    }
    Node * currentNode = temp;
    Node * nextNode = temp->next;
    Node * newNode = new Node();
    newNode->data = data;
    currentNode->next = newNode;
    newNode->next = nextNode;
    this->count++;
  }
}

void LinkedList::erase(int position) {
  if (this->head != nullptr && (position >= 0 && position <= this->count)) {
    if (position == 0) {
      this->popFront();
      return;
    }
    Node * temp = this->head;
    for (int i = 0; i < position - 1; i++) {
      temp = temp->next;
    }
    Node * nextNode = temp->next;
    temp->next = nextNode->next;
    this->count--;
  }
}

void LinkedList::reverse() {
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
