#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include <iostream>
using namespace std;

#include "class.HeapNode.h"

class MinHeap {
private:
  HeapNode * arr;
  int length;
  int numElements;
public:

  MinHeap(int length) {
    this->length = length + 1;
    this->arr = new HeapNode[this->length];
    this->numElements = 0;
  }

  bool empty() {
    return (this->numElements == 0 ? true : false);
  }

  void display(int key) {
    int k = 0;
    for (int i = 1; i <= this->numElements; i++) {
      if (key == this->arr[i].key) {
        k = i;
        break;
      }
    }
    if (k != 0) {
      if (k * 2 <= this->numElements) {
        cout << "Left Child: " << this->arr[k * 2].data << "\n";
      }
      if (k * 2 + 1 <= this->numElements) {
        cout << "Right Child: " << this->arr[k * 2 + 1].data << "\n";
      }
      if (k / 2 > 0) {
        cout << "Parent: " << this->arr[k / 2].data << "\n";
      }

    }
  }

  void enQueue(int key, double data) {
    if (this->numElements == (this->length - 1)) {
      cout << "Priority Queue is Full\n";
      return;
    }
    numElements++;
    this->arr[numElements].key = key;
    this->arr[numElements].data = data;
    heapifyUp(0, this->length);
  }

  void heapifyUp(int root, int size) {
    int i = numElements;
    while (i / 2 > 0) {
      if ((this->arr[i / 2].key > this->arr[i].key)) {
        swap(this->arr[i / 2].key, this->arr[i].key);
        swap(this->arr[i / 2].data, this->arr[i].data);
      }
      i = i / 2;
    }
  }

  void deQueue() {
    if (this->numElements == 0) {
      cout << "Priority Queue is Empty\n";
      return;
    }
    this->arr[1].key = this->arr[numElements].key;
    this->arr[1].data = this->arr[numElements].data;
    numElements--;
    heapifyDown(0, this->length);
  }

  void heapifyDown(int root, int size) {
    int i = 1;
    int smallerChildIndex = 0;
    while (i * 2 <= this->numElements) {
      smallerChildIndex = i * 2;
      if ((i * 2 + 1 <= this->numElements) && (this->arr[i * 2 + 1].key < this->arr[i * 2].key)) {
        smallerChildIndex = i * 2 + 1;
      }
      if (this->arr[i].key < this->arr[smallerChildIndex].key) {
        break;
      } else {
        swap(this->arr[i].key, this->arr[smallerChildIndex].key);
        swap(this->arr[i].data, this->arr[smallerChildIndex].data);
      }
      i = smallerChildIndex;
    }
  }

  void printAll() {
    if (this->numElements == 0) {
      cout << "Priority Queue is empty\n";
      return;
    }
    cout << "Keys\t=>\tData\n";
    for (int i = 1; i <= this->numElements; i++) {
      cout << this->arr[i].key << "\t=>\t" << this->arr[i].data << "\n";
    }
  }

  int findMax() {
    int max = this->arr[1].key;
    int index = 1;
    for (int i = 2; i <= this->numElements; i++) {
      if (this->arr[i].key > max) {
        max = this->arr[i].key;
        index = i;
      }
    }
    cout << "Max: " << this->arr[index].data;
    return max;
  }

  void deleteMax() {
    int max = this->arr[1].key;
    int index = 1;
    for (int i = 2; i <= this->numElements; i++) {
      if (this->arr[i].key > max) {
        max = this->arr[i].key;
        index = i;
      }
    }
    this->arr[index].key = this->arr[this->numElements].key;
    this->arr[index].data = this->arr[this->numElements].data;
    this->numElements--;
    this->heapifyDown(0, this->length);
  }
};

#endif // !MIN_HEAP_H_
