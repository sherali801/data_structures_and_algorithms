#include <iostream>
#include <cmath>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

#include "sorting_searching.h"

float MAX_FLOAT = 3.4E+38;
int MAX_INT = 2147483647;

void forFloats(int size) {
  fstream * fileHandle = new fstream();
  fileHandle->open("execution.txt", ios::app);
  fstream * iterationFileHandle = new fstream();
  iterationFileHandle->open("iterations.txt", ios::app);
  float start = 0.0, end = 0.0;
  float * floatArr = new float[size];
  unsigned seed = time(0);
  srand(seed);
  for (int j = 0; j < size; j++) {
    floatArr[j] = static_cast <float> (rand()) / MAX_FLOAT;
  }
  int count = 0;
  start = GetTickCount();
  count = bubbleSort(floatArr, size);
  end = GetTickCount();
  *fileHandle << setw(20) << size << "\t";
  *iterationFileHandle << setw(20) << size << "\t";
  *fileHandle << setw(20) << (end - start) << "\t";
  *iterationFileHandle << setw(20) << count << "\t";
  start = GetTickCount();
  mergeSort(floatArr, 0, size - 1);
  end = GetTickCount();
  *fileHandle << setw(20) << (end - start) << "\t";
  *iterationFileHandle << setw(20) << 0 << "\t";
  start = GetTickCount();
  count = binarySearch(floatArr, size, 50);
  end = GetTickCount();
  *fileHandle << setw(20) << (end - start) << "\t";
  *iterationFileHandle << setw(20) << count << "\t";
  start = GetTickCount();
  count = linearSearch(floatArr, size, 50);
  end = GetTickCount();
  *fileHandle << setw(20) << (end - start) << "\n";
  *iterationFileHandle << setw(20) << count << "\n";
  fileHandle->close();
  delete fileHandle;
  delete[] floatArr;
}

void forInts(int size) {
  fstream * exeTimeFileHandle = new fstream();
  exeTimeFileHandle->open("execution.txt", ios::app);
  fstream * iterationFileHandle = new fstream();
  iterationFileHandle->open("iterations.txt", ios::app);
  float start = 0.0, end = 0.0;
  int * intArr = new int[size];
  unsigned seed = time(0);
  srand(seed);
  for (int j = 0; j < size; j++) {
    intArr[j] = rand() % MAX_INT;
  }
  int count = 0;
  start = GetTickCount();
  count = bubbleSort(intArr, size);
  end = GetTickCount();
  *exeTimeFileHandle << setw(20) << size << "\t";
  *iterationFileHandle << setw(20) << size << "\t";
  *exeTimeFileHandle << setw(20) << (end - start) << "\t";
  *iterationFileHandle << setw(20) << count << "\t";
  start = GetTickCount();
  mergeSort(intArr, 0, size - 1);
  end = GetTickCount();
  *exeTimeFileHandle << setw(20) << (end - start) << "\t";
  *iterationFileHandle << setw(20) << 0 << "\t";
  start = GetTickCount();
  count = binarySearch(intArr, size, 50);
  end = GetTickCount();
  *exeTimeFileHandle << setw(20) << (end - start) << "\t";
  *iterationFileHandle << setw(20) << count << "\t";
  start = GetTickCount();
  count = linearSearch(intArr, size, 50);
  end = GetTickCount();
  *exeTimeFileHandle << setw(20) << (end - start) << "\n";
  *iterationFileHandle << setw(20) << count << "\n";
  exeTimeFileHandle->close();
  iterationFileHandle->close();
  delete exeTimeFileHandle;
  delete iterationFileHandle;
  delete[] intArr;
}

int main()
{
  fstream * fileHandle = new fstream();
  fileHandle->open("execution.txt", ios::out | ios::trunc);
  *fileHandle << setw(20) << "Size" << "\t" << setw(20) << "Bubble Sort" << "\t" << setw(20) << "Merge Sort" << "\t" << \
    setw(20) << "Binary Search" << "\t" << setw(20) << "Linear Search\n";
  fileHandle->close();
  delete fileHandle;
  fileHandle = new fstream();
  fileHandle->open("iterations.txt", ios::out | ios::trunc);
  *fileHandle << setw(20) << "Size" << "\t" << setw(20) << "Bubble Sort" << "\t" << setw(20) << "Merge Sort" << "\t" << \
    setw(20) << "Binary Search" << "\t" << setw(20) << "Linear Search\n";
  fileHandle->close();
  delete fileHandle;

  forFloats(100); 
  forFloats(1000);
  forFloats(2000);
  forFloats(3000);
  forFloats(5000);
  forFloats(7000);
  forFloats(10000);

  forInts(100); 
  forInts(1000);
  forInts(2000);
  forInts(3000);
  forInts(5000);
  forInts(7000);
  forInts(10000); 
  cout << "Over\n";
  _getch();
  return 0;
}