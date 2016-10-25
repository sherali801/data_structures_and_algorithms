#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int start, int end) {
  if (start > end) {
    return -1;
  }
  int mid = (start + end) / 2;
  if (arr[mid] == key) {
    return mid;
  } else if (key < arr[mid]) {
    binarySearch(arr, key, start, mid - 1);
  } else {
    binarySearch(arr, key, mid + 1, end);
  }
}

int main()
{
  int arr[5] = { 1, 2, 3, 4, 5 };
  int index = binarySearch(arr, 2, 0, 4);
  if (index == -1) {
    cout << "Not Found\n";
  } else {
    cout << "Found at index " << index << "\n";
  }
  return 0;
}

