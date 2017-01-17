#pragma once

#ifndef WEB_SERVER_LOG_PROCESSING_H_
#define WEB_SERVER_LOG_PROCESSING_H_

#include <map>

#include "class.Log.h"

class WebServerLogProcessing {
private:
  map<string, Log> logs;//map which contain name of the page and Log object which has requests and response time
public:
  WebServerLogProcessing();
  ~WebServerLogProcessing();
  void processFile(char * fileName);
  void insetLog(string name, double responseTime);
  void clearLogs();
  void printLogs();
};

#endif // !WEB_SERVER_LOG_PROCESSING_H_
