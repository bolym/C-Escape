#include "TA.hpp"

/******************************************************************
 * Function: TA(int r, int c)
 * Description: Parameterized constructor sets row and col
 * Parameters: int r, int c
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
TA::TA(int r, int c){
  row = r;
  col = c;
}

/******************************************************************
 * Function: getDisplayChar()
 * Description: returns display char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char TA::getDisplayChar(){
  return 'T';
}

/******************************************************************
 * Function: getMove()
 * Description: returns random move char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char TA::getMove(){
  int randNum = rand() % 4;
  switch(randNum){
    case 0:
      return 'w';
      break;
    case 1:
      return 'a';
      break;
    case 2:
      return 's';
      break;
    case 3:
      return 'd';
      break;
  }
}
