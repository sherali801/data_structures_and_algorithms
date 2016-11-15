#pragma once

#ifndef MAZE_H_
#define MAZE_H_

class Maze {
private:
  char **mazeBoard;
  int rows;
  int columns;
  int numOfHurdles;
public:
  Maze();
  void setMaze();
  void displayMaze();
  void displayPath();
};


#endif // !MAZE_H_
