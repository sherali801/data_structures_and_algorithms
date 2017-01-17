#pragma once

#ifndef NODE_H_
#define NODE_H_

#include <string>
using namespace std;

class Node {
public:
  string name;
  double totalRequests;
  double totalResponseTime;
  Node * next;
  Node() {
    this->name = "";
    this->totalRequests = 0;
    this->totalResponseTime = 0;
    this->next = nullptr;
  }
};

#endif // !NODE_H_
