#include "class.Queue.h"

#include <iostream>
using namespace std;

Queue::Queue() {
  this->front = nullptr;
  this->rear = nullptr;
}

Queue::~Queue() { }

bool Queue::isEmpty() {
  return (this->front == nullptr ? true : false);
}

void Queue::clear() {
  if (this->front != nullptr) {
    while (this->front != nullptr) {
      this->deQueue();
    }
    this->rear = nullptr;
  }
}

void Queue::enQueue(int element) {
  Node * newNode = new Node();
  newNode->data = element;
  newNode->next = nullptr;
  if (this->front != nullptr) {
    (this->rear)->next = newNode;
    this->rear = newNode;
    return;
  }
  this->front = newNode;
  this->rear = newNode;
}

void Queue::deQueue() {
  if (this->front != nullptr) {
    Node * tempNode = this->front;
    this->front = (this->front)->next;
    tempNode->next = nullptr;
    delete tempNode;
  }
}

const Node * Queue::getFirstNode() {
  return (this->front == nullptr ? nullptr : this->front);
}

void Queue::print() {
  if (this->front != nullptr) {
    Node * currentNode = this->front;
    while (currentNode != nullptr) {
      cout << currentNode->data << " ";
      currentNode = currentNode->next;
    }
    cout << "\n";
  }
}
