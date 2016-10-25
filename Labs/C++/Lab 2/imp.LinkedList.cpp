#include <iostream>
using namespace std;

#include "class.LinkedList.h"

LinkedList::LinkedList() {
  this->head = nullptr;
  this->count = 0;
}

LinkedList::~LinkedList() { }

int LinkedList::size() {
  return this->count;
}

void LinkedList::display() {
  if (this->head != nullptr) {
    Node * currentNode = this->head;
    while (currentNode != nullptr) {
      cout << currentNode->data << " ";
      currentNode = currentNode->next;
    }
    cout << "\n";
  }
}

void LinkedList::insertAtHead(int data) {
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

void LinkedList::deleteFromHead() {
  if (this->head != nullptr) {
    this->head = (this->head)->next;
    this->count--;
  }
}

void LinkedList::deleteFromTail() {
  if (this->head != nullptr) {
    Node * currentNode = this->head;
    for (int i = 0; i < this->count - 2; i++) {
      currentNode = currentNode->next;
    }
    currentNode->next = nullptr;
    this->count--;
  }
}

void LinkedList::insert(int position, int data) {
  if (this->head != nullptr && (position >= 0 && position <= this->count)) {
    if (position == 0) {
      this->insertAtHead(data);
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

void LinkedList::erase(int position) {
  if (this->head != nullptr && (position >= 0 && position <= this->count)) {
    if (position == 0) {
      this->deleteFromHead();
      return;
    } else if (position == this->count) {
      this->deleteFromTail();
      return;
    }
    Node * currentNode = this->head;
    for (int i = 0; i < position - 1; i++) {
      currentNode = currentNode->next;
    }
    currentNode->next = (currentNode->next)->next;
    this->count--;
  }
}

void LinkedList::reverse() {
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

void LinkedList::mid() {
  if (this->head != nullptr) {
    Node * temp = this->head;
    //if size of list is even then print two central elements else single element in center
    for (int i = 0; i < ((this->size() % 2 == 0) ? ((count / 2) - 1) : (count / 2)); i++) {
      temp = temp->next;
    }
    if (this->size() % 2 == 0) {
      cout << temp->data << " " << (temp->next)->data << "\n";
    } else {
      cout << temp->data << "\n";
    }
  }
}
