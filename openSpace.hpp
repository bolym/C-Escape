#include "mazeLocation.hpp"
#include "mazePerson.hpp"
#include <iostream>
using namespace std;

#ifndef OPENSPACE_HPP
#define OPENSPACE_HPP

class OpenSpace : public MazeLocation{
  protected:
    bool isStart;
    bool isEnd;
    MazePerson* person;
    bool hasSkill;

  public:
    OpenSpace();
    bool isOccupiable();
    char getDisplayChar();
    bool getIsStart();
    void setIsStart(bool b);
    bool getIsEnd();
    void setIsEnd(bool b);
    MazePerson* getPerson();
    void setPerson(MazePerson* p);
    bool getHasSkill();
    void setHasSkill(bool b);

};

#endif
