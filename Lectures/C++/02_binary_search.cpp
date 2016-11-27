#include <iostream>
#include <conio.h>
using namespace std;

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
  int arr[10] =  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  
  if (!binarySearch(arr, 10, 7)) {
    cout << "Not Found\n";
  } else {
    cout << "Found\n";
  }
  _getch();
  return 0;
}

