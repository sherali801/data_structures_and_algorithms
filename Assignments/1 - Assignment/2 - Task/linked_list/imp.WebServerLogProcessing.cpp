#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

#include "class.WebServerLogProcessing.h"

WebServerLogProcessing::WebServerLogProcessing() {
  this->head = nullptr;
}

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
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');//name of the page
    i = 0;
    name = "";
    while (fileLine[i] != '?' && i < fileLine.size()) {
      name += fileLine[i];
      i++;
    }
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, ' ');
    getline(*fileHandle, fileLine, '\n');//response time
    if (fileLine != "-" && fileLine != "") {
      responseTime = 0;
      responseTime = stod(fileLine, &size);
      this->insetLog(name, responseTime);
    }
  }
}

void WebServerLogProcessing::insetLog(string name, double responseTime) {
  if (this->head != nullptr) {//check whether list is empty
    Node * currentNode = this->head;
    while (currentNode != nullptr) {
      if (currentNode->name == name) {//if page name already is in list then increment its contents
        currentNode->totalRequests++;
        currentNode->totalResponseTime += responseTime;
        return;
      }
      currentNode = currentNode->next;
    }
    delete currentNode;
  }
  //if page name not in list than adding it at head
  Node * newNode = new Node();
  newNode->name = name;
  newNode->totalRequests++;
  newNode->totalResponseTime += responseTime;
  newNode->next = this->head;
  this->head = newNode;
}

void WebServerLogProcessing::deleteLog() {
  if (this->head != nullptr) {
    Node * currentNode = this->head;
    this->head = (this->head)->next;//moving head to next node
    currentNode->next = nullptr;
    delete currentNode;
  }
}

void WebServerLogProcessing::clearLogs() {
  while (this->head != nullptr) {
    this->deleteLog();
  }
}

void WebServerLogProcessing::printLogs() {
  if (this->head != nullptr) {
    Node * currentNode = this->head;
    while (currentNode != nullptr) {
      cout << setw(120) << currentNode->name << "\t" << setw(5) << currentNode->totalRequests << "\t" << setw(20) << currentNode->totalResponseTime << "\n";
      currentNode = currentNode->next;
    }
  }
}
