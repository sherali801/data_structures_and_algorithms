#include <iostream>
#include <ctime>
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
  if (q.empty()) {
    cout << "Priority Queue is empty\n";
  } else {
    cout << "Priority Queue is not empty\n";
  }
  cout << "Size of Priority Queue: " << q.size() << "\n";
  cout << "Top element: " << q.top() << "\n";
  _getch();
  return 0;
}
