#include <iostream>
using namespace std;

#ifndef MAZEPERSON_HPP
#define MAZEPERSON_HPP

class MazePerson{
  protected:
    int row;
    int col;
  public:
    MazePerson();
    int getRow();
    int getCol();
    virtual char getDisplayChar() = 0;
    virtual char getMove() = 0;
    void setLocation(int r, int c);
};

#endif
