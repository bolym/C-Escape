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
#include "mazeLevel.hpp"
using namespace std;

class Maze{
  protected:
    int numLevels;
    int height;
    int width;
    vector<MazeLevel*> maze;
    IntrepidStudent* student;
    Instructor* instructor;
  public:
    Maze(ifstream& reader);
    ~Maze();
    void moveStudent();
    void beginGame(bool& passed);
    char checkInput(string question, string valid);
};
