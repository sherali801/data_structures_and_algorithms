#include <iostream>
#include <conio.h>
using namespace std;

void bubbleSort(int arr[], int N) {
  bool swaped = false;
  do {
    swaped = false;
    int i = 0;
    while (i < N - 1) {
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swaped = true;
      }
      i++;
    }
  } while (swaped);
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
    }
    else {
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

bool linearSearch(int arr[], int size, int key) {
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] == key) {
      return true;
    }
  }
  return false;
}

bool binarySearch(int * arr, int size, int key) {
  int start = 0;
  int end = size - 1;
  int mid;
  bool found = false;
  while (!found && start <= end) {
    mid = (start + end) / 2;
    if (key == *(arr + mid)) {
      found = true;
    } else if (key < *(arr + mid)) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return found;
}

int main()
{
  const int N = 16;
  int arr[N] = { 5,14,10,27,45,30,50,7,20,40,37,43,10,14,50,53 };
  int arr1[N] = { 1,2,3,5,7,11,13,17,19,21,23,19,31,37,39,41 };
  int arr2[N] = { 30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,1 };
  cout << "Linear Search on ";
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  cout << (linearSearch(arr, N, 50) ? "Found" : "Not Found") << "\n";
  cout << "Bubble Sort on ";
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  bubbleSort(arr, N);
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  cout << "Binary Search on ";
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  cout << (binarySearch(arr, N, 50) ? "Found" : "Not Found") << "\n";
  cout << "Merge Sort on ";
  for (int i = 0; i < N; i++) {
    cout << arr1[i] << " ";
  }
  cout << "\n";
  mergeSort(arr1, 0, N - 1);
  for (int i = 0; i < N; i++) {
    cout << arr1[i] << " ";
  }
  cout << "\n";
  _getch();
  return 0;
}
