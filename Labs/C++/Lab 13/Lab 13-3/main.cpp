#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

void populateArray(int *arr, int size) {
  unsigned seed = time(0);
  srand(seed);
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % INT_MAX;
  }
}

int main() {
  int * arr = new int[1000];
  populateArray(arr, 1000);
  printArray(arr, 1000);
  _getch();
  return 0;
}
