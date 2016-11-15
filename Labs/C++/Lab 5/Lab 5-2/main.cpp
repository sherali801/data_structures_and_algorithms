#include <iostream>
#include <conio.h>
using namespace std;

void bubbleSort(int arr[], int N) {
  cout << "Bubble Sort\n";
  int count = 0;
  bool swaped = false;
  do {
    swaped = false;
    int i = 0;
    while (i < N - 1) {
      count++;
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swaped = true;
      }
      i++;
    }
  } while (swaped);
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  if (count <= N) {
    cout << "Time Complexity big - oh(n)\t";
  }
  else {
    cout << "Time Complexity big - oh(n^2)\t";
  }
  cout << "O(" << count << ")\n";
}

void selectionSort(int arr[], int N) {
  cout << "Selection Sort\n";
  int count = 0;
  int startIndex, minIndex, minValue;
  for (startIndex = 0; startIndex < N - 1; startIndex++) {
    minIndex = startIndex;
    minValue = arr[startIndex];
    for (int i = startIndex + 1; i < N; i++) {
      count++;
      if (arr[i] < minValue) {
        minValue = arr[i];
        minIndex = i;
      }
    }
    swap(arr[minIndex], arr[startIndex]);
  }
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  if (count <=  N) {
    cout << "Time Complexity big - oh(n)\t";
  } else {
    cout << "Time Complexity big - oh(n^2)\t";
  }
  cout << "O(" << count << ")\n";
}

void insertionSort(int arr[], int N) {
  cout << "Insertion Sort\n";
  int count = 0;
  int i, j;
  for (i = 0; i < N; i++) {
    j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      count++;
      if (arr[j - 1] > arr[j]) {
        swap(arr[j], arr[j - 1]);
      }
      j--;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  if (count <= N) {
    cout << "Time Complexity big - oh(n)\t";
  }
  else {
    cout << "Time Complexity big - oh(n^2)\t";
  }
  cout << "O(" << count << ")\n";
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

void merge(int arr[], int start, int mid, int end) {
  int leftSize = mid - start + 1;
  int rightSize = end - mid;
  int * left = new int[leftSize];
  int * right = new int[rightSize];
  int i = 0, j = 0, k = 0;
  for (i = 0, k = start; i < leftSize; i++, k++) {
    left[i] = arr[k];
  }
  for (j = 0, k = mid + 1; j < rightSize; j++, k++) {
    right[j] = arr[k];
  }
  i = 0;
  j = 0;
  k = start;
  while (i < leftSize && j < rightSize) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < leftSize) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < rightSize) {
    arr[k] = right[j];
    j++;
    k++;
  }
  delete left;
  delete right;
}

void mergeSort(int arr[], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

int main()
{
  const int N = 16;
  int start;
  int end;
  int arr[N] = { 5,14,10,27,45,30,50,7,20,40,37,43,10,14,50,53 };
  int arr1[N] = { 1,2,3,5,7,11,13,17,19,21,23,19,31,37,39,41 };
  int arr2[N] = { 30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,1 };
  int arr3[N] = { 30,1,26,24,35,20,18,2,14,45,10,8,6,4,2,1 };
  int arr4[N] = { 1,2,3,5,7,11,13,17,19,21,23,19,31,37,39,41 };
  bubbleSort(arr, N);
  selectionSort(arr1, N);
  insertionSort(arr2, N);
  cout << "Merge Sort\n";
  mergeSort(arr3, 0, N - 1);
  for (int i = 0; i < N; i++) {
    cout << arr3[i] << " ";
  }
  cout << "\n";
  cout << "Quick Sort\n";
  quickSort(arr4, 0, N - 1);
  for (int i = 0; i < N; i++) {
    cout << arr3[i] << " ";
  }
  cout << "\n";
  _getch();
  return 0;
}
