#include <iostream>
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

int main()
{
  int num = 0, size = 0;
  cout << "Enter Size: ";
  cin >> size;
  PriorityQueue q(size);
  for (int i = 0; i < size; i++) {
    cout << "Enter Number: ";
    cin >> num;
    q.push(num);
  }
  if (q.empty()) {
    cout << "Priority Queue is empty\n";
  }
  else {
    cout << "Priority Queue is not empty\n";
  }
  num = q.top();
  q.pop();
  cout << num << " popped\n";
  cout << "Enter Number to Insert: ";
  cin >> num;
  q.push(num);
  cout << num << " pushed\n";
  cout << "Size of Priority Queue: " << q.size() << "\n";
  cout << "Top element: " << q.top() << "\n";
  while (!q.empty()) {
    cout << q.top() << ", ";
    q.pop();
  }
  _getch();
  return 0;
}
