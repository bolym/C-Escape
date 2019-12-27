#include "wall.hpp"

/******************************************************************
 * Function: Wall()
 * Description: Default empty constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Wall::Wall(){
  //empty
}

/******************************************************************
 * Function: isOccupiable()
 * Description: returns false
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
bool Wall::isOccupiable(){
  return false;
}

/******************************************************************
 * Function: getDisplayChar()
 * Description: returns display char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char Wall::getDisplayChar(){
  return '#';
}
