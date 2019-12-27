#include "mazeLocation.hpp"
#include <iostream>
using namespace std;

#ifndef WALL_HPP
#define WALL_HPP

class Wall : public MazeLocation{
  protected:

  public:
    Wall();
    bool isOccupiable();
    char getDisplayChar();
};

#endif
