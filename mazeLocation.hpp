#include <iostream>
using namespace std;

#ifndef MAZELOCATION_HPP
#define MAZELOCATION_HPP

class MazeLocation{
  protected:

  public:
    MazeLocation();
    virtual bool isOccupiable() = 0;
    virtual char getDisplayChar() = 0;
};

#endif
