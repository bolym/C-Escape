#include "openSpace.hpp"

/******************************************************************
 * Function: OpenSpace()
 * Description: Default constructor sets member variables to default
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
OpenSpace::OpenSpace(){
  isStart = false;
  isEnd = false;
  person = NULL;
  hasSkill = false;
}

/******************************************************************
 * Function: isOccupiable()
 * Description: returns true
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
bool OpenSpace::isOccupiable(){
  return true;
}

/******************************************************************
 * Function: getDisplayChar()
 * Description: returns display char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char OpenSpace::getDisplayChar(){
  if(person != NULL){
    return person->getDisplayChar();
  } else if(hasSkill){
    return '$';
  } else if(isStart){
    return '@';
  } else if(isEnd){
    return '^';
  } else {
    return ' ';
  }
}

/******************************************************************
 * Function: getIsStart()
 * Description: returns isStart
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
bool OpenSpace::getIsStart(){
  return isStart;
}

/******************************************************************
 * Function: setIsStart(bool b)
 * Description: sets isStart to b
 * Parameters: bool b
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void OpenSpace::setIsStart(bool b){
  isStart = b;
}

/******************************************************************
 * Function: getIsEnd()
 * Description: returns isEnd
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
bool OpenSpace::getIsEnd(){
  return isEnd;
}

/******************************************************************
 * Function: setIsEnd(bool b)
 * Description: sets isEnd to b
 * Parameters: bool b
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void OpenSpace::setIsEnd(bool b){
  isEnd = b;
}

/******************************************************************
 * Function: getPerson()
 * Description: returns person
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
MazePerson* OpenSpace::getPerson(){
  return person;
}

/******************************************************************
 * Function: setPerson(MazePerson* p)
 * Description: sets person to p
 * Parameters: MazePerson* p
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void OpenSpace::setPerson(MazePerson* p){
  person = p;
}

/******************************************************************
 * Function: getHasSkill()
 * Description: returns hasSkill
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
bool OpenSpace::getHasSkill(){
  return hasSkill;
}

/******************************************************************
 * Function: setHasSkill(bool b)
 * Description: sets hasSkill to b
 * Parameters: bool b
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void OpenSpace::setHasSkill(bool b){
  hasSkill = b;
}
