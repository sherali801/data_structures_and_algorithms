#include <iostream>
using namespace std;

int getFactorial(int num) {
  int fac = 1;
  while (num > 0) {
    fac *= num;
    num--;
  }
  return fac;
}

int main()
{
  for (int i = 0; i < 10; i++) {
    cout << i << "  " << getFactorial(i) << "\n";
  }
  return 0;
}

