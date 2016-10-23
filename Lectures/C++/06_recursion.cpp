#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void printString(int count, string str) {
  if (count <= 0) {
    return;
  }
  printString(count - 1, str);
  cout << count << " " << str << "\n";
}

int main()
{
  printString(3, "Hello, World!");
  _getch();
  return 0;
}

