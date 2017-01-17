#include "class.Node.h"

Node::Node() {
  this->xCoordinate = 0;
  this->yCoordinate = 0;
  this->nextNode = nullptr;
}

Node::~Node() { }

void Node::setXCoordinate(int xCoordinate) {
  this->xCoordinate = xCoordinate;
}

void Node::setYCoordinate(int yCoordinate) {
  this->yCoordinate = yCoordinate;
}

void Node::setNextNode(Node * nextNode) {
  this->nextNode = nextNode;
}

int Node::getXCoordinate() const {
  return this->xCoordinate;
}

int Node::getYCoordinate() const {
  return this->yCoordinate;
}

Node * Node::getNextNode() {
  return this->nextNode;
}
