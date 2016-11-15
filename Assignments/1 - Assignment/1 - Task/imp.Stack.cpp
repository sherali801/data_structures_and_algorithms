#include <iostream>
using namespace std;

#include "class.Stack.h"

Stack::Stack() {
  this->top = nullptr;
}

void Stack::push(int xCoordinate, int yCoordinate) {
  Node * newNode = new Node();
  newNode->setXCoordinate(xCoordinate);
  newNode->setYCoordinate(yCoordinate);
  if (this->top != nullptr) {
    newNode->setNextNode(top);
    top = newNode;
    return;
  }
  newNode->setNextNode(nullptr);
  top = newNode;
}

Node * Stack::pop() {
  if (this->top != nullptr) {
    Node * tempNode = this->top;
    this->top = (this->top)->getNextNode();
    tempNode->setNextNode(nullptr);
    return tempNode;
  } else {
    return nullptr;
  }
}

void Stack::emptyStack() {
  if (this->top != nullptr) {
    Node * currentNode = this->top;
    Node * tempNode = nullptr;
    while (currentNode != nullptr) {
      tempNode = currentNode;
      currentNode = currentNode->getNextNode();
      tempNode->setNextNode(nullptr);
      delete tempNode;
    }
    delete currentNode;
  }
}

Node * Stack::getTop() {
  return this->top;
}

void Stack::print() {
  if (this->top != nullptr) {
    Node * currentNode = this->top;
    cout << "E <- ";
    while (currentNode != nullptr) {
      cout << "(" << currentNode->getXCoordinate() << ", " << currentNode->getYCoordinate() << ") <- ";
      currentNode = currentNode->getNextNode();
    }
    cout << "S\n";
    delete currentNode;
  }
}

