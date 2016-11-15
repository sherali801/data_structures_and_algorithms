#include <iostream>
#include <ctime>
#include <cmath>
#include <conio.h>
using namespace std;

#include "sorting_searching.h"

float MAX_FLOAT = 3.4E+38;
int MAX_INT = 2147483647;

void printFloats(int size) {
  float * floatArr = new float[size];
  unsigned seed = time(0);
  srand(seed);
  for (int j = 0; j < size; j++) {
    floatArr[j] = static_cast<float> (rand()) / MAX_FLOAT;
  }
  cout << "After Sorting\n";
  bubbleSort(floatArr, size);
  for (int k = 0; k < size; k++) {
    cout << floatArr[k] << " ";
  }
  delete[] floatArr;
}

void printInts(int size) {
  int * intArr = new int[size];
  unsigned seed = time(0);
  srand(seed);
  for (int j = 0; j < size; j++) {
    intArr[j] = rand() % MAX_INT;
  }
  cout << "\n";
  bubbleSort(intArr, size);
  cout << (binarySearch(intArr, size, 50) ? "Found" : "Not Found") << "\n";
  delete[] intArr;
}

int main()
{
  printFloats(100); cout << "\n";
  printFloats(1000); cout << "\n";
  printFloats(2000); cout << "\n";
  printFloats(3000); cout << "\n";
  printFloats(5000); cout << "\n";
  printFloats(7000); cout << "\n";
  printFloats(10000); cout << "\n";

  printInts(100); cout << "\n";
  printInts(1000); cout << "\n";
  printInts(2000); cout << "\n";
  printInts(3000); cout << "\n";
  printInts(5000); cout << "\n";
  printInts(7000); cout << "\n";
  printInts(10000); cout << "\n";
  _getch();
  return 0;
}