#include <iostream>
using namespace std;

int getFibonacciAt(int num) {
  if (num <= 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  } else {
    return getFibonacciAt(num - 1) + getFibonacciAt(num - 2);
  }
}

int sumOfFirstNFibonacciNumbers(int n) {
  if (n <= 0) {
    return 0;
  }
  return getFibonacciAt(n) + sumOfFirstNFibonacciNumbers(n - 1);
}

int main()
{
  cout << sumOfFirstNFibonacciNumbers(3);
  return 0;
}

