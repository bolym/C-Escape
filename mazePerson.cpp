#include "mazePerson.hpp"

/******************************************************************
 * Function: mazePerson()
 * Description: Default empty MazePerson constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
MazePerson::MazePerson(){
  //empty
}

/******************************************************************
 * Function: getRow()
 * Description: returns row
 * Parameters: None
 * Pre-Conditions: row has been initialized
 * Post-Conditions: None
******************************************************************/
int MazePerson::getRow(){
  return row;
}

/******************************************************************
 * Function: getCol()
 * Description: returns col
 * Parameters: None
 * Pre-Conditions: col has been initialized
 * Post-Conditions: None
******************************************************************/
int MazePerson::getCol(){
  return col;
}

/******************************************************************
 * Function: setLocation(int r, int c)
 * Description: sets location to (row, col)
 * Parameters: int r, int c
 * Pre-Conditions: None
 * Post-Conditions: row and col are initialized
******************************************************************/
void MazePerson::setLocation(int r, int c){
  row = r;
  col = c;
}
