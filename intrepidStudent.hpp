#include <iostream>
#include "mazePerson.hpp"
using namespace std;

#ifndef INTREPIDSTUDENT_HPP
#define INTREPIDSTUDENT_HPP

class IntrepidStudent : public MazePerson{
  protected:
    int numSkills;
  public:
    char getDisplayChar();
    IntrepidStudent();
    char getMove();
    int getNumSkills();
    void setNumSkills(int n);
    char checkInput(string question, string valid);
};

#endif
