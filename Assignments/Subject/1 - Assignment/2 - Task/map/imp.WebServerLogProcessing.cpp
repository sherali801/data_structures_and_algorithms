#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

#include "class.WebServerLogProcessing.h"

WebServerLogProcessing::WebServerLogProcessing() { }

WebServerLogProcessing::~WebServerLogProcessing() { }

void WebServerLogProcessing::processFile(char * fileName) {
  fstream * fileHandle = new fstream();
  fileHandle->open(fileName, ios::in);
  if (!(fileHandle->is_open())) {
    cout << "Error while opening file\nPress any key to continue...\n";
    _getch();
    delete fileHandle;
    return;
  }
  string fileLine = "";
  int i = 0;
  string name = "";
  double responseTime = 0;
  string::size_type size;
  while (!fileHandle->eof()) {
    string fileLine;
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');//name of the page
    //parsing name of the page
    i = 0;
    name = "";
    while (fileLine[i] != '?' && i < fileLine.size()) {
      name += fileLine[i];
      i++;
    }
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, '\n');//response time
    responseTime = 0;
    if (fileLine != "-" && fileLine != "") {
      responseTime = stod(fileLine, &size);
      this->insetLog(name, responseTime);
    }
  }
  fileHandle->close();
  delete fileHandle;
}

void WebServerLogProcessing::insetLog(string name, double responseTime) {
  map<string, Log>::iterator it = (this->logs).find(name);//return iterator to element or to end of map
  if (it != (this->logs).end()) {
    Log oldLog = (this->logs).find(name)->second;//getting old log so it can be removed and new log can be added
    (this->logs).erase(it);//removing old log in map
    //modifying old values 
    oldLog.totalRequests++;
    oldLog.totalResponseTime += responseTime;
    (this->logs).insert({ name, oldLog });//inserting same old log after values modified
  } else {//log did not exist previously
    Log newLog;
    newLog.totalRequests++;
    newLog.totalResponseTime += responseTime;
    (this->logs).insert({ name, newLog });//inserting new log
  }
}

void WebServerLogProcessing::clearLogs() {
  (this->logs).clear();
}

void WebServerLogProcessing::printLogs() {
  cout << "#Page Name\t\t\t\t\t\t\t\tTotal Requests\t\tAverage Response Time\n";
  for (map<string, Log>::iterator it = (this->logs).begin(); it != (this->logs).end(); it++) {
    cout << setw(120) << it->first << "\t" << setw(5) << (it->second).totalRequests << "\t" << setw(20) << (it->second).getAverageResponseTime() << "\n";
  }
}
