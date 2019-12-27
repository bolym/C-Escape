#include <iostream>
#include "mazePerson.hpp"
using namespace std;

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

class Instructor : public MazePerson{
  protected:

  public:
    Instructor();
    char getDisplayChar();
    char getMove();
};

#endif
