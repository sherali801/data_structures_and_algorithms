#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>
#include <queue>
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
  priority_queue<int> q;
  for (int i = 0; i < 1000; i++) {
    q.push(arr[i]);
  }
  double startTime = 0, endTime = 0;
  startTime = GetTickCount();
  while (!q.empty()) {
    q.pop();
  }
  endTime = GetTickCount();
  cout << "Exe Time: " << endTime - startTime << "\n";
  _getch();
  return 0;
}
