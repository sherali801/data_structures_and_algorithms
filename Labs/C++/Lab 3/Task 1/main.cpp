#include <iostream>
#include <conio.h>
using namespace std;

void printMessage(int n);
int factorial(int n);
void fibonacci(int num);
int getFibonacciAt(int num);
float power(float number, int n);
int gcd(int a, int b);
int sumArray(int arr[], int n);
int maxValue(int arr[], int n);
bool palindrome(string str, int start, int end);

int main()
{
  cout << "printMessage\n";
  printMessage(2);
  cout << "factorial\n";
  cout << factorial(3) << "\n";
  cout << "Fibonacci\n";
  fibonacci(5);
  cout << "\npower\n";
  cout << power(2, 3) << "\n";
  cout << "GCD\n";
  cout << gcd(13, 27) << "\n";
  cout << "sumArray\n";
  int array[] = { 6, 3, 5, 1, 2 };
  cout << sumArray(array, 5) << "\n";
  cout << "maxValue\n";
  cout << maxValue(array, 5) << "\n";
  cout << "palindrome\n";
  cout << (palindrome("hello", 0, 4) ? "true" : "false") << "\n";
  _getch();
  return 0;
}

void printMessage(int n) {
  if (n <= 0) {
    return;
  }
  cout << "Hello, World!\n";
  printMessage(n - 1);
}

int factorial(int n) {
  if (n < 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

void fibonacci(int num) {
  if (num <= 0) {
    return;
  }
  fibonacci(num - 1);
  cout << getFibonacciAt(num) << " ";
}

int getFibonacciAt(int num) {
  if (num <= 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  } else {
    return getFibonacciAt(num - 1) + getFibonacciAt(num - 2);
  }
}

float power(float number, int n) {
  if (n < 0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  } else {
    return number * power(number, n - 1);
  }
}

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int sumArray(int arr[], int n) {
  if (n <= 0) { 
    return 0;
  }
  return arr[n - 1] + sumArray(arr, n - 1);
}

int maxValue(int arr[], int n) {
  if (n <= 0) {
    return 0;
  }
  if (arr[n - 1] > maxValue(arr, n - 1)) {
    return arr[n - 1];
  }
}

bool palindrome(string str, int start, int end) { 
  if (start >= end) {
    return true;
  }
  if (str[start] != str[end]) {
    return false;
  }
  start++;
  end--;
  return palindrome(str, start, end);
}
