#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if ((num % i) == 0) {
      return false;
    }
  }
  return true;
}

int main()
{
  int count = 0, num = 2;
  while (count < 1000) {
    if (isPrime(num)) {
       cout << count << "  " << num << endl;
       count++;  
    }
    num++;
  }
  return 0;
}

