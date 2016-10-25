#include <iostream>
using namespace std;

int sumOfArrayElements(int arr[], int size) {
  if (size <= 0) {
    return 0;
  }
  return sumOfArrayElements(arr, size - 1) + arr[size - 1];
}

int main()
{
  int arr[5] = { 1, 2, 3, 4, 5 };
  cout << sumOfArrayElements(arr, 0);
  return 0;
}
