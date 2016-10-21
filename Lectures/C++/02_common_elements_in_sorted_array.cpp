#include <iostream>
#include <conio.h>
using namespace std;

const int SIZE_A = 7;
const int SIZE_B = 7;

bool binarySearch(int * arr, int size, int num) {
  static int start = 0;
  int end = size - 1;
  int mid;
  bool found = false;
  while (!found && start <= end) {
    mid = (start + end) / 2;
    if (num == *(arr + mid)) {
      found = true;
    } else if (num < *(arr + mid)) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return found;
}

int main()
{
  int A[SIZE_A] = { 13, 27, 35, 40, 49, 55, 59 };
  int B[SIZE_B] = { 17, 35, 39, 40, 55, 58, 60 };
  for (int i = 0; i < SIZE_A; i++) {
    if (binarySearch(B, SIZE_B, A[i])) {
      cout << A[i] << " ";
    }
  }
  _getch();
  return 0;
}
