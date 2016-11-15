#include <iostream>
#include <conio.h>
using namespace std;

#include "class.Log.h"
#include "class.WebServerLogProcessing.h"

int main(int argc, char * argv[])
{
  if (argc >= 1) {
    WebServerLogProcessing * logs = new WebServerLogProcessing();
    logs->processFile(argv[1]);
    logs->printLogs();
    logs->clearLogs();
    delete logs;
  } else {
    cout << "Invalid arguments\nPress any key to continue...\n";
  }
  _getch();
  return 0;
}