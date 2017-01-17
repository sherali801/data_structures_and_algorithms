#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
using namespace std;


class PriorityQueue {
private:
  int * arr;
  int sizeOfArray;
  int index;
  int count;
public:

  PriorityQueue(int sizeOfArray) {
    this->sizeOfArray = sizeOfArray;
    this->sizeOfArray++;
    this->arr = new int[this->sizeOfArray];
    this->index = 0;
    this->count = 0;
  }

  bool empty() {
    return (this->count == 0 ? true : false);
  }

  int size() {
    return this->count;
  }

  int top() {
    if (this->empty()) {
      return INT_MIN;
    }
    return this->arr[1];
  }

  void push(int num) {
    if (this->count == (this->sizeOfArray - 1)) {
      cout << "Priority Queue is Full\n";
      return;
    }
    this->index++;
    this->arr[index] = num;
    count++;
    int i = index;
    while (i / 2 > 0) {
      if ((arr[i / 2] < arr[i])) {
        swap(arr[i / 2], arr[i]);
      }
      i = i / 2;
    }
  }

  void pop() {
    if (this->empty()) {
      cout << "Priority Queue is Empty\n";
      return;
    }
    this->arr[1] = this->arr[index];
    index--;
    count--;
    int i = 1;
    int greaterChildIndex = 0;
    while (i * 2 <= this->count) {
      greaterChildIndex = i * 2;
      if ((i * 2 + 1 <= this->count) && (this->arr[i * 2 + 1] > this->arr[i * 2])) {
        greaterChildIndex = i * 2 + 1;
      }
      if (this->arr[i] > this->arr[greaterChildIndex]) {
        break;
      } else {
        swap(this->arr[i], this->arr[greaterChildIndex]);
      }
      i = greaterChildIndex;
    }
  }

};


void populateArray(int *arr, int size) {
  unsigned seed = time(0);
  srand(seed);
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % INT_MAX;
  }
}

void print(int * arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << ", ";
  }
}

int main() {
  int * arr = new int[1000];
  populateArray(arr, 1000);
  PriorityQueue q(1000);
  for (int i = 0; i < 1000; i++) {
    q.push(arr[i]);
  }
  double startTime = 0.0, endTime = 0.0;
  startTime = GetTickCount();
  while (!q.empty()) {
    q.pop();
  }
  endTime = GetTickCount();
  cout << "Exe Time: " << endTime - startTime << "\n";
  _getch();
  return 0;
}
