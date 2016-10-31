#include <iostream>
using namespace std;
#include "class.Stack.h"

Stack::Stack(int size) { 
  this->size = size;
  this->count = 0;
  this->element = 0;
  this->top = nullptr;
}

Stack::~Stack() { }

void Stack::push(int element) {
  if (!isFull()) {
    this->count++;
    Node * newNode = new Node();
    this->element = element;
    newNode->data = element;
    if (this->top != nullptr) {
      newNode->next = top;
      top = newNode;
      return;
    }
    newNode->next = nullptr;
    top = newNode;
  } else {
    cout << "Stack is Full\n";
  }
}

void Stack::pop() {
  if (this->top != nullptr) {
    this->count--;
    Node * tempNode = this->top;
    this->top = (this->top)->next;
    tempNode->next = nullptr;
    delete tempNode;
    if (this->top == nullptr) {
      this->element = 0;
    } else {
      this->element = (this->top)->data;
    }
  }
}

bool Stack::isEmpty() {
  return (this->top == nullptr ? true : false);
}

bool Stack::isFull() {
  return (this->count == this->size ? true : false);
}

const Node * Stack::peek() {
  return (this->top == nullptr ? nullptr : this->top);
}

int Stack::getStackSize() {
  if (this->top != nullptr) {
    int countElements = 0;
    Node * currentNode = this->top;
    while (currentNode != nullptr) {
      countElements++;
      currentNode = currentNode->next;
    }
    delete currentNode;
    return countElements;
  }
  return 0;
}

void Stack::print() {
  if (this->top != nullptr) {
    Node * currentNode = this->top;
    while (currentNode != nullptr) {
      cout << currentNode->data << " ";
      currentNode = currentNode->next;
    }
    delete currentNode;
    cout << "\n";
  }
}
