#include "intrepidStudent.hpp"

/******************************************************************
 * Function: IntrepidStudent()
 * Description: Default constructor sets row and col to 1
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
IntrepidStudent::IntrepidStudent(){
  row = 1;
  col = 1;
  numSkills = 0;
}

/******************************************************************
 * Function: getDisplayChar()
 * Description: returns display char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char IntrepidStudent::getDisplayChar(){
  return '*';
}

/******************************************************************
 * Function: getMove()
 * Description: returns move char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char IntrepidStudent::getMove(){
  char dir;
  dir = checkInput("Enter the direction you want to move (wasd): ", "wasd");
  return dir;
}

/******************************************************************
 * Function: getNumSkills()
 * Description: returns numSkills
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
int IntrepidStudent::getNumSkills(){
  return numSkills;
}

/******************************************************************
 * Function: setNumSkills(int n)
 * Description: sets numSkills to n
 * Parameters: int n
 * Pre-Conditions: None
 * Post-Conditions: numSkills is assigned n
******************************************************************/
void IntrepidStudent::setNumSkills(int n){
  numSkills = n;
}

/******************************************************************
 * Function: checkInput
 * Description: Performs a do-while using question to only accept
 * 		characters that are in valid. Returns char
 * 		version of input.
 * Parameters: string question, string valid
 * Pre-Conditions: question and valid must not be empty
 * Post-Conditions: question and valid don't change
******************************************************************/
char IntrepidStudent::checkInput(string question, string valid){
   string var_str;
   size_t found;

   do{
      cout << question << endl;
      cin >> var_str;
      found = var_str.find_first_not_of(valid);
   }
   while(found != string::npos && var_str.length() < 2);

   return var_str[0];
}
