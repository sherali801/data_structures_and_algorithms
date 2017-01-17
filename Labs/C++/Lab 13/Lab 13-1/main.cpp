#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;

int main()
{
  priority_queue<int> q;
  int num = 0, size = 0;
  cout << "Enter Size: ";
  cin >> size;
  for (int i = 0; i < size; i++) {
    cout << "Enter Number: ";
    cin >> num;
    q.push(num);
  }
  if (q.empty()) {
    cout << "Priority Queue is empty\n";
  } else {
    cout << "Priority Queue is not empty\n";
  }
  num = q.top();
  q.pop();
  cout << num << " popped\n";
  cout << "Enter Number to push: ";
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