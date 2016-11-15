#include <iostream>
#include <conio.h>
using namespace std;

#include "class.Maze.h"

int main()
{
  Maze * maze = new Maze();
  maze->setMaze();
  maze->displayMaze();
  maze->displayPath();
  delete maze;
  _getch();
  return 0;
}