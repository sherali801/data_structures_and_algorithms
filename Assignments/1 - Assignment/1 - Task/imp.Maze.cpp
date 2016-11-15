#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

#include "class.Maze.h"
#include "class.Stack.h"

Maze::Maze() {
  this->rows = 0;
  this->columns = 0;
  this->numOfHurdles = 0;
}

void Maze::setMaze() {
  fstream * fileHandle = new fstream();
  fileHandle->open("assign01-maze-input.txt", ios::in);
  if (!fileHandle->is_open()) {
    cout << "Error while opening file\nPress any key to continue...\n";
    _getch();
    delete fileHandle;
    return;
  }
  *fileHandle >> this->rows;
  *fileHandle >> this->columns;
  if (this->rows <= 0 || this->columns <= 0) {
    cout << "Combination of Rows and Columns are not suitable\nPress any key to continue...\n";
    _getch();
    fileHandle->close();
    delete fileHandle;
    return;
  }
  this->mazeBoard = new char*[this->rows];
  for (int i = 0; i < this->rows; i++) {
    this->mazeBoard[i] = new char[this->columns];
  }
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->columns; j++) {
      this->mazeBoard[i][j] = ' ';
    }
  }
  this->mazeBoard[0][0] = 'S';
  this->mazeBoard[this->rows - 1][this->columns - 1] = 'E';
  *fileHandle >> this->numOfHurdles;
  int xCoordinateOfHurdle = 0;
  int yCoordinateOfHurdle = 0;
  while (*fileHandle >> xCoordinateOfHurdle && *fileHandle >> yCoordinateOfHurdle) {
    if ((xCoordinateOfHurdle < 0 || xCoordinateOfHurdle >= this->rows) || (yCoordinateOfHurdle < 0 || yCoordinateOfHurdle >= this->columns)) {
      cout << "Coordinates of Hurdle (" << xCoordinateOfHurdle << "," << yCoordinateOfHurdle << ") are not suitable\nPress any key to continue...\n";
      _getch();
      fileHandle->close();
      delete fileHandle;
      return;
    }
    mazeBoard[xCoordinateOfHurdle][yCoordinateOfHurdle] = 'X';
  }
  fileHandle->close();
  delete fileHandle;
}

void Maze::displayMaze() {
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->columns; j++) {
      cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
    }
    cout << "\n";
    for (int j = 0; j < this->columns; j++) {
      cout << char(179) << "  " << this->mazeBoard[i][j] << "  " << char(179);
    }
    cout << "\n";
    for (int j = 0; j < this->columns; j++) {
      cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);
    }
    cout << "\n";
  }
}

void Maze::displayPath() {
  Stack * path = new Stack();
  Node * previousMove = nullptr;
  int xCoordinateOfCurrentPosition = 0;
  int yCoordinateOfCurrentPosition = 0;
  bool pathExist = true;
  while ((xCoordinateOfCurrentPosition != this->rows - 1 || yCoordinateOfCurrentPosition != this->columns - 1) && pathExist) {
    //check if no path exist
    if (this->mazeBoard[0][1] == 'X' && this->mazeBoard[1][0] == 'X') {
      pathExist = false;
    }
    if (xCoordinateOfCurrentPosition < this->rows && yCoordinateOfCurrentPosition + 1 < this->columns && this->mazeBoard[xCoordinateOfCurrentPosition][yCoordinateOfCurrentPosition + 1] != 'X') {//first try to move right
      path->push(xCoordinateOfCurrentPosition, yCoordinateOfCurrentPosition);
      yCoordinateOfCurrentPosition++;
    } else if (xCoordinateOfCurrentPosition + 1 < this->rows && yCoordinateOfCurrentPosition < this->columns && this->mazeBoard[xCoordinateOfCurrentPosition + 1][yCoordinateOfCurrentPosition] != 'X') {//second try to move down
      path->push(xCoordinateOfCurrentPosition, yCoordinateOfCurrentPosition);
      xCoordinateOfCurrentPosition++;
    } else {//if can't go right or down then putting hurdle in current place and moving back using stack
      this->mazeBoard[xCoordinateOfCurrentPosition][yCoordinateOfCurrentPosition] = 'X';
      previousMove = path->pop();
      if (previousMove != nullptr) {
        xCoordinateOfCurrentPosition = previousMove->getXCoordinate();
        yCoordinateOfCurrentPosition = previousMove->getYCoordinate();
      } else {//stack is empty and player is at (0,0)
        xCoordinateOfCurrentPosition = 0;
        yCoordinateOfCurrentPosition = 0;
      }
    }
  }
  if (pathExist) {
    path->push(this->rows - 1, this->columns - 1);
    path->print();
  }
  path->emptyStack();
  delete path;
  delete previousMove;
}
