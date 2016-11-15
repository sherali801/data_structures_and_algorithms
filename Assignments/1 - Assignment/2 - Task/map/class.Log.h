#pragma once

#ifndef LOG_H_
#define LOG_H_

#include <string>
using namespace std;

//contains total requests and total response time to a specific name of page 

class Log {
public:
  double totalRequests;
  double totalResponseTime;
  Log() {
    this->totalRequests = 0;
    this->totalResponseTime = 0;
  }
  double getAverageResponseTime() {
    return this->totalResponseTime / this->totalRequests;
  }
};

#endif // !LOG_H_
