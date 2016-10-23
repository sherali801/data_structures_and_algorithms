#include <iostream>
using namespace std;

int getFibonacciAt(int num) {
  int count = 0;
  int n1 = 0, n2 = 1, fib = 1;
  while (count < num - 1) {
    fib = n1 + n2;
    n1 = n2;
    n2 = fib;
    count++;
  }
  return fib;
}

int main()
{
  for (int i = 1; i <= 10; i++) {
   cout << getFibonacciAt(i) << " "; 
  }
  return 0;
}

