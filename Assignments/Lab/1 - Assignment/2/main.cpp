#include <iostream>
#include <conio.h>
using namespace std;

#include "class.Node.h"
#include "class.DoublyLinkedList.h"

int main()
{
  DoublyLinkedList * list = new DoublyLinkedList();
  list->createDoublyLinkedList();
  list->display();
  list->deleteithNode(4);
  list->display();
  list->deleteithNode(1);
  list->display();
  list->enQueue(0);
  list->display();
  _getch();
  return 0;
}