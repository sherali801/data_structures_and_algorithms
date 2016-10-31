#include <iostream>
#include <conio.h>
using namespace std;

int minimumNumberOfMovesToMoveDiscs(int numberOfDiscs);//lab 3, task 2, part 2
int minimumNumberOfMinutesToMoveOneDiscPerMinute(int numberOfDiscs);//lab 3, task 2, part 3
double minimumNumberOfDaysToMoveOneDiscPerMinute(int numberOfDiscs);//lab 3, task 2, part 4
double minimumNumberOfYearsToMoveOneDiscPerSecond(double numberOfSeconds);//lab 3, task 2, part 5
void moveDiscsInMinimumNumberOfMoves(int numberOfDiscs, int fromPeg, int toPeg, int tempPeg);//lab 3, task 2, part 6

int main()
{
  cout << minimumNumberOfMovesToMoveDiscs(3) << " Moves\n";
  cout << minimumNumberOfMinutesToMoveOneDiscPerMinute(7) << " Minutes\n";
  cout << minimumNumberOfDaysToMoveOneDiscPerMinute(15) << " Days\n";
  cout << minimumNumberOfYearsToMoveOneDiscPerSecond(18446744073709551615) << "\n";
  moveDiscsInMinimumNumberOfMoves(8, 1, 3, 2);
  _getch();
  return 0;
}

int minimumNumberOfMovesToMoveDiscs(int numberOfDiscs) {
  if (numberOfDiscs <= 0) {
    return 0;
  } else {
    return pow(2, numberOfDiscs) - 1;
  }
}

int minimumNumberOfMinutesToMoveOneDiscPerMinute(int numberOfDiscs) {
  return minimumNumberOfMovesToMoveDiscs(numberOfDiscs);
}

double minimumNumberOfDaysToMoveOneDiscPerMinute(int numberOfDiscs) {
  return (( (double) minimumNumberOfMinutesToMoveOneDiscPerMinute(numberOfDiscs)) / ((double) 60)) / ((double) 24);
}

double minimumNumberOfYearsToMoveOneDiscPerSecond(double numberOfSeconds) {
  return ((((numberOfSeconds / 60) / 60) / 24) / 365);
}

void moveDiscsInMinimumNumberOfMoves(int numberOfDiscs, int fromPeg, int toPeg, int tempPeg) {
  if (numberOfDiscs > 0)
  {
    moveDiscsInMinimumNumberOfMoves(numberOfDiscs - 1, fromPeg, tempPeg, toPeg);
    cout << "Move a disc from peg " << fromPeg
      << " to peg " << toPeg << endl;
    moveDiscsInMinimumNumberOfMoves(numberOfDiscs - 1, tempPeg, toPeg, fromPeg);
  }
}
