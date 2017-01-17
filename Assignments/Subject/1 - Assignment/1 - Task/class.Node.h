#pragma once

#ifndef NODE_H_
#define NODE_H_

class Node {
private:
  int xCoordinate;
  int yCoordinate;
  Node * nextNode;
public:
  Node();
  ~Node();
  void setXCoordinate(int xCoordinate);
  void setYCoordinate(int yCoordinate);
  void setNextNode(Node * nextNode);
  int getXCoordinate() const;
  int getYCoordinate() const;
  Node * getNextNode();
};

#endif // !NODE_H_
