#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
  const int SIZE_A = 7;
  const int SIZE_B = 7;
  int A[SIZE_A] = { 13, 27, 35, 40, 49, 55, 59 };
  int B[SIZE_B] = { 17, 35, 39, 40, 55, 58, 60 };
  int i = 0, j = 0;
  while (i < SIZE_A && j < SIZE_B) {
    if (A[i] < B[j]) {
      i++;
    } else if (A[i] > B[j]) {
      j++;
    } else {
      cout << A[i] << " ";
      i++;
      j++;
    }
  }
  _getch();
  return 0;
}
