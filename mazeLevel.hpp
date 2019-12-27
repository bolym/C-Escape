#include <iostream>
#include <fstream>
#include <vector>
#include "mazeLocation.hpp"
#include "openSpace.hpp"
#include "wall.hpp"
#include "mazePerson.hpp"
#include "instructor.hpp"
#include "TA.hpp"
#include "intrepidStudent.hpp"
using namespace std;

#ifndef MAZE_HPP
#define MAZE_HPP

class MazeLevel{
  protected:
    int height;
    int width;
    vector<vector<MazeLocation*> > locations;
    IntrepidStudent* student;
    TA* ta1;
    TA* ta2;
    Instructor* instructor;
    OpenSpace* start;
    OpenSpace* finish;
    int appTurnsLeft;
    bool isAppeased;

  public:
    MazeLevel(ifstream& reader, int h, int w);
    ~MazeLevel();
    void openIndex(int& randRow, int& randCol);
    MazeLocation* getLocation(int row, int col);
    IntrepidStudent* getStudent();
    void setStudent(IntrepidStudent* stud);
    TA* getTA1();
    void setTA1(TA* ta);
    TA* getTA2();
    void setTA2(TA* ta);
    Instructor* getInstructor();
    void setInstructor(Instructor* instruct);
    OpenSpace* getStart();
    OpenSpace* getFinish();
    int getTurnsLeft();
    void setTurnsLeft(int n);
    bool getIsAppeased();
    void setIsAppeased(bool b);
    void displayMaze();
    bool checkInstructor();
    bool caughtByTA();
    void resetLevel();
    void movePerson(MazePerson* p);
};

#endif
