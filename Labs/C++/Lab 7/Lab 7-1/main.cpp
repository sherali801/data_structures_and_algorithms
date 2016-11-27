#include <iostream>
#include <conio.h>
using namespace std;

#include "Node.h"
#include "class.LinkedList.h"

int main()
{
  LinkedList * first = new LinkedList();
  cout << "Inserting elements in first list:\n";
  first->insertAt(5, 0);
  first->insertAt(3, 1);
  first->insertAt(1, 2);
  first->insertAt(2, 2);
  first->insertAt(4, 4);
  cout << "Displaying inserted elements:\n";
  first->disply();
  cout << "Sorting inserted elements:\n";
  first->sort();
  cout << "Displaying sorted elements:\n";
  first->disply();
  LinkedList * second = new LinkedList();
  cout << "Insering elements in second list:\n";
  second->insertAt(1, 0);
  second->insertAt(2, 1);
  second->insertAt(3, 2);
  second->insertAt(4, 3);
  second->insertAt(5, 4);
  cout << "Comparing first list with second list:\n";
  cout << (first->compareLinkedLists(second) ? "True" : "False") << "\n";
  cout << "Reversing elements of first list:\n";
  first->reverseLinkedList();
  first->disply();
  _getch();
  return 0;
}