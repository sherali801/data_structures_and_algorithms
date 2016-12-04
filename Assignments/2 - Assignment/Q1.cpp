#include<iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

void fillArray(int * arr, int size);
void divideInParts(int * arr, int size);
void displayDividedParts(int * arr, int start, int mid, int end);

int main()
{
  int size;
  cout << "Enter Size: ";
  cin >> size;
  int * arr = new int[size];
  fillArray(arr, size);
  divideInParts(arr, size);
  _getch();
  return 0;
}

void fillArray(int * arr, int size) {
  unsigned seed = time(0);
  srand(seed);
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % INT_MAX;
  }
}

void divideInParts(int * arr, int size) {
  for (int currentSize = size / 2; currentSize > 0; currentSize /= 2) {//in each iteration the size of array will be divided in half
    for (int leftStart = 0; leftStart < size - 1; leftStart += 2 * currentSize) {//starting from left divide the complete array
      int mid = leftStart + currentSize;                                         //in currentSize of each iteration
      int rightEnd = leftStart + 2 * currentSize;
      displayDividedParts(arr, leftStart, mid, rightEnd);
    }
  }
}

void displayDividedParts(int * arr, int start, int mid, int end) {
  int leftSize = mid - start;
  int rightSize = end - mid;
  cout << "Array : ";
  for (int i = start; i < end; i++) {
    cout << arr[i] << " ";
  }
  cout << "\nLeft: ";
  while (start < mid) {
    cout << arr[start] << " ";
    start++;
  }
  cout << "\nRight: ";
  while (mid < end) {
    cout << arr[mid] << " ";
    mid++;
  }
  cout << "\n";
}

