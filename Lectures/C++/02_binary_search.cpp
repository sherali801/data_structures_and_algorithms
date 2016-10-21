#include <iostream>
#include <conio.h>
using namespace std;

const int SIZE = 10;

int main()
{
  int arr[SIZE] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int find;
  int mid;
  int start = 0;
  int end = SIZE - 1;
  bool found = false;
  cin >> find;
  while (!found && start <= end) {
    mid = (start + end) / 2;
    if (find == arr[mid]) {
      found = true;
    } else if (find < arr[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  if (!found) {
    cout << "Not Found\n";
  } else {
    cout << "Found\n";
  }
  _getch();
  return 0;
}

