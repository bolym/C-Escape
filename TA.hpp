#include <iostream>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "mazePerson.hpp"
using namespace std;

#ifndef TA_HPP
#define TA_HPP

class TA : public MazePerson{
  protected:

  public:
    TA(int r, int c);
    char getDisplayChar();
    char getMove();
};

#endif
