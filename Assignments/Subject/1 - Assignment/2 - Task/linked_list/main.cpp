#include <iostream>
#include <conio.h>
using namespace std;

#include "class.WebServerLogProcessing.h"

int main(int argc, char * argv[])
{
  if (argc > 0) {
    WebServerLogProcessing * log = new WebServerLogProcessing();
    log->processFile(argv[1]);
    log->printLogs();
    log->clearLogs();
    delete log;
  } else {
    cout << "Invalid arguments\nPress any key to continue...\n";
  }
  _getch();
  return 0;
}