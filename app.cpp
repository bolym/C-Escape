/******************************************************************
 * Program: app.cpp
 * Author: Michael Boly
 * Date: 3/18/2019
 * Description: Escape CS 162 by the rules
 * Input: The user chooses to move, use skill, or climb ladder
 * Output: A wholesome game of Escape CS 162.
 *****************************************************************/

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "maze.hpp"
using namespace std;

/******************************************************************
 * Function: main()
 * Description: Creates a game of Escape CS 162 that continues one
                move at a time until the user wins or loses. The
                user must continue to play until they escape.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: The user will be appreciating your hard work.
 ******************************************************************/
int main(int argc, char* argv[]){
  ifstream reader;
  reader.open(argv[1]);

  if(reader.fail()){      /* check for error */
     cout << "File error" << endl;
     exit(1);
  }

  srand(time(NULL));
  bool passed = false;
  while(!passed){     /* if failed, keep playing */
    Maze maze(reader);
    maze.beginGame(passed);
    reader.clear();    /* reset infile */
    reader.seekg(0, ios::beg);
  }

  cout << "Game Over." << endl;


}
