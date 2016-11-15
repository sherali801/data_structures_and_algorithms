#pragma once

#ifndef WEB_SERVER_LOG_PROCESSING_H_
#define WEB_SERVER_LOG_PROCESSING_H_

#include "class.Node.h"

class WebServerLogProcessing {
private:
  Node * head;
public:
  WebServerLogProcessing();
  void processFile(char * fileName);
  void insetLog(string name, double responseTime);
  void deleteLog();
  void clearLogs();
  void printLogs();
};

#endif // !WEB_SERVER_LOG_PROCESSING_H_
