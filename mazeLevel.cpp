#include "maze.hpp"

/******************************************************************
 * Function: MazeLevel(ifstream& reader, int h, int w)
 * Description: Parameterized constructor fills locations with
                MazeLocation pointers. Places TAs and Skills
                randomly.
 * Parameters: ifstream& reader, int h, int w
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
MazeLevel::MazeLevel(ifstream& reader, int h, int w){
  height = h;
  width = w;
  isAppeased = false;
  appTurnsLeft = 0;
  for(int i = 0; i < h; i++){   /* fill locations with MazeLocations */
    vector<MazeLocation*> row;
    char c;
    for(int j = 0; j < w; j++){
      reader.get(c);
      if(c == '#'){             /* wall */
        row.push_back(new Wall());
      } else if(c == ' '){      /* empty */
        row.push_back(new OpenSpace());
      } else if(c == '@'){      /* start */
        OpenSpace* os = new OpenSpace();
        os->setIsStart(true);
        start = os;
        row.push_back(os);
      } else if(c == '^'){      /* finish */
        OpenSpace* os = new OpenSpace();
        os->setIsEnd(true);
        finish = os;
        row.push_back(os);
      } else if(c == '%'){      /* instructor */
        OpenSpace* os = new OpenSpace();
        instructor = new Instructor();
        instructor->setLocation(i, j);
        os->setPerson(instructor);
        row.push_back(os);
      }
    }
    locations.push_back(row);
    reader.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  int randRow = rand() % height;
  int randCol = rand() % width;
  openIndex(randRow, randCol);
  ta1 = new TA(randRow, randCol);     /* place TAs randomly */
  OpenSpace* space = dynamic_cast<OpenSpace*>(locations.at(randRow).at(randCol));
  space->setPerson(ta1);

  openIndex(randRow, randCol);
  ta2 = new TA(randRow, randCol);
  OpenSpace* space2 = dynamic_cast<OpenSpace*>(locations.at(randRow).at(randCol));
  space2->setPerson(ta2);

  for(int i = 0; i < 3; i++){       /* place skills randomly */
    openIndex(randRow, randCol);
    OpenSpace* skillSpace = dynamic_cast<OpenSpace*>(locations.at(randRow).at(randCol));
    skillSpace->setHasSkill(true);
  }

}

/******************************************************************
 * Function: ~MazeLevel()
 * Description: MazeLevel destructor deletes TAs, instructor, and
                MazeLocations.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
MazeLevel::~MazeLevel(){
  delete ta1;
  delete ta2;
  delete instructor;

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      delete locations.at(i).at(j);
    }
  }
}

/******************************************************************
 * Function: openIndex(int& randRow, int& randCol)
 * Description: Finds a random open location
 * Parameters: int& randRow, int& randCol
 * Pre-Conditions: None
 * Post-Conditions: randRow and randCol change
******************************************************************/
void MazeLevel::openIndex(int& randRow, int& randCol){
  randRow = rand() % height;
  randCol = rand() % width;
  while(locations.at(randRow).at(randCol)->getDisplayChar() != ' '){
    randRow = rand() % height;
    randCol = rand() % width;
  }
}

/******************************************************************
 * Function: : getLocation(int row, int col)
 * Description: returns location at that row, col
 * Parameters: int row, int col
 * Pre-Conditions: None
 * Post-Conditions: locations don't change
******************************************************************/
MazeLocation* MazeLevel::getLocation(int row, int col){
  return locations.at(row).at(col);
}

/******************************************************************
 * Function: : getStudent()
 * Description: returns student
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: student don't change
******************************************************************/
IntrepidStudent* MazeLevel::getStudent(){
  return student;
}

/******************************************************************
 * Function: setStudent(IntrepidStudent* stud)
 * Description: sets student to stud
 * Parameters: IntrepidStudent* stud
 * Pre-Conditions: None
 * Post-Conditions: student is assigned stud
******************************************************************/
void MazeLevel::setStudent(IntrepidStudent* stud){
  student = stud;
}

/******************************************************************
 * Function: : getTA1()
 * Description: returns student
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: ta don't change
******************************************************************/
TA* MazeLevel::getTA1(){
  return ta1;
}

/******************************************************************
 * Function: setTA1(TA* ta)
 * Description: sets ta1 to ta
 * Parameters: TA* ta
 * Pre-Conditions: None
 * Post-Conditions: ta1 is assigned ta
******************************************************************/
void MazeLevel::setTA1(TA* ta){
  ta1 = ta;
}

/******************************************************************
 * Function: : getTA2()
 * Description: returns student
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: ta don't change
******************************************************************/
TA* MazeLevel::getTA2(){
  return ta2;
}

/******************************************************************
 * Function: setTA2(TA* ta)
 * Description: sets ta2 to ta
 * Parameters: TA* ta
 * Pre-Conditions: None
 * Post-Conditions: ta2 is assigned ta
******************************************************************/
void MazeLevel::setTA2(TA* ta){
  ta2 = ta;
}

/******************************************************************
 * Function: : getInstructor()
 * Description: returns instructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: instructor don't change
******************************************************************/
Instructor* MazeLevel::getInstructor(){
  return instructor;
}

/******************************************************************
 * Function: Instructor* instruct
 * Description: sets instructor to instruct
 * Parameters: Instructor* instruct
 * Pre-Conditions: None
 * Post-Conditions: instructor is assigned instruct
******************************************************************/
void MazeLevel::setInstructor(Instructor* instruct){
  instructor = instruct;
}

/******************************************************************
 * Function: getStart()
 * Description: returns start
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
OpenSpace* MazeLevel::getStart(){
  return start;
}

/******************************************************************
 * Function: getFinish()
 * Description: returns finish
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
OpenSpace* MazeLevel::getFinish(){
  return finish;
}

/******************************************************************
 * Function: getTurnsLeft()
 * Description: returns appTurnsLeft
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
int MazeLevel::getTurnsLeft(){
  return appTurnsLeft;
}

/******************************************************************
 * Function: setTurnsLeft(int n)
 * Description: sets appTurnsLeft to n
 * Parameters: int n
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void MazeLevel::setTurnsLeft(int n){
  appTurnsLeft = n;
}

/******************************************************************
 * Function: getIsAppeased()
 * Description: returns isAppeased
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
bool MazeLevel::getIsAppeased(){
  return isAppeased;
}

/******************************************************************
 * Function: setIsAppeased(bool b)
 * Description: sets isAppeased to b
 * Parameters: bool b
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void MazeLevel::setIsAppeased(bool b){
  isAppeased = b;
}

/******************************************************************
 * Function: displayMaze()
 * Description: displays this maze with everything in it
 * Parameters: None
 * Pre-Conditions: locations must be accurate
 * Post-Conditions: locations don't change
******************************************************************/
void MazeLevel::displayMaze(){
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      cout << locations.at(i).at(j)->getDisplayChar();
    }
    cout << endl;
  }
  cout << "You currently have: " << student->getNumSkills() << " skill(s)." << endl;
  if(isAppeased){
    cout << "The TAs are currently appeased for " << appTurnsLeft + 1 << " more turns." << endl;
  } else {
    cout << "The TAs are currently not appeased." << endl;
  }
}

/******************************************************************
 * Function: checkInstructor()
 * Description: returns true if instructor is adjacent to student
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
bool MazeLevel::checkInstructor(){

  int sRow = student->getRow();
  int sCol = student->getCol();
  int iRow = instructor->getRow();
  int iCol = instructor->getCol();

  if(sRow - 1 >= 0){   /* check top */
    if(sRow - 1 == iRow && sCol == iCol){
      return true;
    }
  }
  if(sRow + 1 < height){  /* check bottom */
    if(sRow + 1 == iRow && sCol == iCol){
      return true;
    }
  }
  if(sCol - 1 >= 0){   /* check left */
    if(sRow == iRow && sCol - 1 == iCol){
      return true;
    }
  }
  if(sCol + 1 < width){  /* check right */
    if(sRow == iRow && sCol + 1 == iCol){
      return true;
    }
  }
  return false;
}

/******************************************************************
 * Function: caughtByTA()
 * Description: returns true if TA is adjacent to student and not
                appeased.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
bool MazeLevel::caughtByTA(){
  if(isAppeased){
    return false;
  }
  int sRow = student->getRow();
  int sCol = student->getCol();
  int ta1Row = ta1->getRow();
  int ta1Col = ta1->getCol();
  int ta2Row = ta2->getRow();
  int ta2Col = ta2->getCol();

  if(sRow - 1 >= 0){   /* check top */
    if(sRow - 1 == ta1Row && sCol == ta1Col){
      return true;
    } else if(sRow - 1 == ta2Row && sCol == ta2Col){
      return true;
    }
  }
  if(sRow + 1 < height){  /* check bottom */
    if(sRow + 1 == ta1Row && sCol == ta1Col){
      return true;
    } else if(sRow + 1 == ta2Row && sCol == ta2Col){
      return true;
    }
  }
  if(sCol - 1 >= 0){   /* check left */
    if(sRow == ta1Row && sCol - 1 == ta1Col){
      return true;
    } else if(sRow == ta2Row && sCol - 1 == ta2Col){
      return true;
    }
  }
  if(sCol + 1 < width){  /* check right */
    if(sRow == ta1Row && sCol + 1 == ta1Col){
      return true;
    } else if(sRow == ta2Row && sCol + 1 == ta2Col){
      return true;
    }
  }
  return false;
}

/******************************************************************
 * Function: resetLevel()
 * Description: resets this level with randomly set TAs and skills
                and student at beginning with no skills.
 * Parameters: None
 * Pre-Conditions: Student was caught by TA.
 * Post-Conditions: TAs, skills, and student locations change
******************************************************************/
void MazeLevel::resetLevel(){
  start->setPerson(student);      /* reset student */
  student->setLocation(1, 1);
  student->setNumSkills(0);

  OpenSpace* ta1Space = dynamic_cast<OpenSpace*>(locations.at(ta1->getRow()).at(ta1->getCol()));
  OpenSpace* ta2Space = dynamic_cast<OpenSpace*>(locations.at(ta2->getRow()).at(ta2->getCol()));
  ta1Space->setPerson(NULL);      /* reset TAs */
  ta2Space->setPerson(NULL);

  int randRow = rand() % height;
  int randCol = rand() % width;
  openIndex(randRow, randCol);
  ta1->setLocation(randRow, randCol);     /* new TA locations */
  OpenSpace* space = dynamic_cast<OpenSpace*>(locations.at(randRow).at(randCol));
  space->setPerson(ta1);

  openIndex(randRow, randCol);
  ta2->setLocation(randRow, randCol);
  OpenSpace* space2 = dynamic_cast<OpenSpace*>(locations.at(randRow).at(randCol));
  space2->setPerson(ta2);


  for(int i = 0; i < height; i++){        /* remove old skills */
    for(int j = 0; j < width; j++){
      MazeLocation* loc = locations.at(i).at(j);
      if(loc->isOccupiable()){
        OpenSpace* skillSpace = dynamic_cast<OpenSpace*>(loc);
        skillSpace->setHasSkill(false);
      }
    }
  }

  for(int i = 0; i < 3; i++){             /* generate new skills */
    openIndex(randRow, randCol);
    OpenSpace* skillSpace = dynamic_cast<OpenSpace*>(locations.at(randRow).at(randCol));
    skillSpace->setHasSkill(true);
  }
}

/******************************************************************
 * Function: movePerson(MazePerson* p)
 * Description: moves a generic MazePerson where their getMove says
 * Parameters: MazePerson* p
 * Pre-Conditions: person is currently in a OpenSpace
 * Post-Conditions: person moves to an adjacent location
******************************************************************/
void MazeLevel::movePerson(MazePerson* p){
  OpenSpace* oldLoc = dynamic_cast<OpenSpace*>(locations.at(p->getRow()).at(p->getCol()));
  MazeLocation* newLoc;

  while(oldLoc->getPerson() != NULL){
    char dir = p->getMove();
    switch(dir){
      case 'w':          /* north */
        if(p->getRow()-1 >= 0){
          newLoc = locations.at(p->getRow()-1).at(p->getCol());
          if(newLoc->isOccupiable()){
            OpenSpace* openLoc = dynamic_cast<OpenSpace*>(newLoc);
            if(openLoc->getPerson() == NULL){
              oldLoc->setPerson(NULL);        /* change person pointers */
              openLoc->setPerson(p);
              p->setLocation(p->getRow()-1, p->getCol());
            }
          }
        }
        break;
      case 'a':            /* west */
        if(p->getCol()-1 >= 0){
          newLoc = locations.at(p->getRow()).at(p->getCol()-1);
          if(newLoc->isOccupiable()){
            OpenSpace* openLoc = dynamic_cast<OpenSpace*>(newLoc);
            if(openLoc->getPerson() == NULL){
              oldLoc->setPerson(NULL);
              openLoc->setPerson(p);
              p->setLocation(p->getRow(), p->getCol()-1);
            }
          }
        }
        break;
      case 's':              /* south */
        if(p->getRow()+1 < height){
          newLoc = locations.at(p->getRow()+1).at(p->getCol());
          if(newLoc->isOccupiable()){
            OpenSpace* openLoc = dynamic_cast<OpenSpace*>(newLoc);
            if(openLoc->getPerson() == NULL){
              oldLoc->setPerson(NULL);
              openLoc->setPerson(p);
              p->setLocation(p->getRow()+1, p->getCol());
            }
          }
        }
        break;
      case 'd':                /* east */
        if(p->getCol()+1 < width){
          newLoc = locations.at(p->getRow()).at(p->getCol()+1);
          if(newLoc->isOccupiable()){
            OpenSpace* openLoc = dynamic_cast<OpenSpace*>(newLoc);
            if(openLoc->getPerson() == NULL){
              oldLoc->setPerson(NULL);
              openLoc->setPerson(p);
              p->setLocation(p->getRow(), p->getCol()+1);
            }
          }
        }
        break;
    }
  }
}
