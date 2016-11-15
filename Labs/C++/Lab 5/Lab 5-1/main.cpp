#include <iostream>
#include <conio.h>
using namespace std;

const int SIZE = 16;

void computeSum(int n) {
  int sumOfFirstNNumbers = 0;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    sumOfFirstNNumbers += i;
    count++;
  }
  cout << "Sum of first " << n << " Numbers " << sumOfFirstNNumbers << "\n";
  if (count <= n) {
    cout << "Time Complexity big - oh(n)\t";
  } else {
    cout << "Time Complexity big - oh(n^2)\t";
  }
  cout << "O(" << count << ")\n";
}

void findElement(int arr[], int x) {
  int count = 0;
  for (int i = 0; i < SIZE; i++) {
    count++;
    if (arr[i] == x) {
      cout << "Found at index " << i << "\nTime Complexity big - oh(n)\tO(" << count << ")\n";
      return;
    }
  }
  if (count <= sizeof(arr) / sizeof(arr[0])) {
    cout << "Time Complexity big - oh(n)\t";
  } else {
    cout << "Time Complexity big - oh(n^2)\t";
  }
  cout << "O(" << count << ")\n";
}

void matricesMultiplication() {
  int first[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
  int second[3][3] = { {9,8,7}, {6,5,4}, {3,2,1} };
  int sum = 0;
  int count = 0;
  for (int i = 0; i < 3; i++) {
    sum = 0;
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        count++;
        sum = sum + first[i][k] * second[k][j];
      }
      first[i][j] = sum;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << first[i][j] << " ";
    }
    cout << "\n";
  }
  if (count <= 3 * 3) {
    cout << "Time Complexity big - oh(n^2)\t";
  }
  else {
    cout << "Time Complexity big - oh(n^3)\t";
  }
  cout << "O(" << count << ")\n";
}

int main()
{
  int nNumbers = 0;;
  cout << "First N Numbers: ";
  cin >> nNumbers;
  computeSum(nNumbers);
  cout << "Sum of first " << nNumbers << " Numbers " << (nNumbers * ((nNumbers + 1)) / 2) << "\n";
  cout << "Time Complexity big - oh(1)\n";
  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  findElement(arr, 8);
  matricesMultiplication();
  _getch();
  return 0;
}