#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

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

int getFibonacciAt(int num) {
  if (num <= 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  } else {
    return getFibonacciAt(num - 1) + getFibonacciAt(num - 2);
  }
}

void fibonacci(int num) {
  if (num <= 0) {
    return;
  }
  fibonacci(num - 1);
  cout << getFibonacciAt(num) << " ";
}

bool findElement(int arr[], int start, int end, int key) {
  if (start >= end) {
    return false;
  }
  if (arr[start] == key) {
    return true;
  }
  return findElement(arr, ++start, end, key);
}

void printArray(int * arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main()
{
  string str;
  cout << "Enter string: ";
  getline(cin, str);
  cout << str << " " << (palindrome(str, 0, str.size() - 1) ? "is palindrome" : "is not palindrome") << "\n";
  cout << "First 20 Fibonacci series\n";
  fibonacci(20);
  int arr1[16] = { 5,14,10,27,45,30,50,7,20,40,37,43,10,14,50,53 };
  cout << "\nArray: ";
  printArray(arr1, 16);
  cout << "Enter a Number to search: ";
  int num;
  cin >> num;
  cout << "Element " << (findElement(arr1, 0, 16, num) ? "Found" : "Not Found") << "\n";
  _getch();
  return 0;
}