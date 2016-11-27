#include <iostream>
#include <conio.h>
using namespace std;

void selectionSort(int arr[], int N) {
  int startIndex, minIndex, minValue;
  for (startIndex = 0; startIndex < N - 1; startIndex++) {
    minIndex = startIndex;
    minValue = arr[startIndex];
    for (int i = startIndex + 1; i < N; i++) {
      if (arr[i] < minValue) {
        minValue = arr[i];
        minIndex = i;
      }
    }
    swap(arr[minIndex], arr[startIndex]);
  }
}

int partition(int arr[], int start, int end) {
  int pivotValue = arr[end];
  int partitionIndex = start;
  for (int i = start; i < end; i++) {
    if (arr[i] <= pivotValue) {
      swap(arr[i], arr[partitionIndex]);
      partitionIndex++;
    }
  }
  swap(arr[partitionIndex], arr[end]);
  return partitionIndex;
}

void quickSort(int arr[], int start, int end) {
  if (start < end) {
    int partitionIndex = partition(arr, start, end);
    quickSort(arr, start, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, end);
  }
}

void printArray(int * arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void copyArray(int toBeCopied[], int copyTo[], int size) {
  for (int i = 0; i < size; i++) {
    copyTo[i] = toBeCopied[i];
  }
}

int main()
{
  int arr1[16] = { 5,14,10,27,45,30,50,7,20,40,37,43,10,14,50,53 };
  int arr2[16] = { 0 };
  copyArray(arr1, arr2, 16);
  selectionSort(arr2, 16);
  cout << "Before Selection sorting:\n";
  printArray(arr1, 16);
  cout << "After Selection sorting:\n";
  printArray(arr2, 16);

  copyArray(arr1, arr2, 16);
  quickSort(arr2, 0, 15);
  cout << "Before Quick sorting:\n";
  printArray(arr1, 16);
  cout << "After Quick sorting:\n";
  printArray(arr2, 16);
  _getch();
  return 0;
}