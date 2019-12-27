#include "instructor.hpp"

/******************************************************************
 * Function: Instructor()
 * Description: Default constructor sets row and col to 0
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Instructor::Instructor(){
  row = 0;
  col = 0;
}

/******************************************************************
 * Function: getDisplayChar()
 * Description: returns display char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char Instructor::getDisplayChar(){
  return '%';
}

/******************************************************************
 * Function: getMove()
 * Description: returns move char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char Instructor::getMove(){
  return ' ';
}
