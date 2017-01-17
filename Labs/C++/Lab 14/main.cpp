#include <iostream>
#include <conio.h>
using namespace std;

#include "class.HeapNode.h"
#include "class.MinHeap.h"

int main()
{
  int size;
  cout << "Enter Size: ";
  cin >> size;
  MinHeap minHeap(size);
  int key;
  double data;
  for (int i = 0; i < size; i++) {
    cout << "Enter Priority: ";
    cin >> key;
    cout << "Enter Data: ";
    cin >> data;
    minHeap.enQueue(key, data);
  }
  minHeap.printAll();
  cout << "Enter key: ";
  cin >> key;
  minHeap.display(key);
  key = minHeap.findMax();
  cout << ", Key: " << key << "\n";
  minHeap.deleteMax();
  cout << "Max Deleted\n";
  minHeap.printAll();
  while (!minHeap.empty()) {
    minHeap.deQueue();
    minHeap.printAll();
  }
  _getch();
  return 0;
}