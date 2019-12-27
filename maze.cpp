#include "maze.hpp"

/******************************************************************
 * Function: Maze(ifstream& reader)
 * Description: Paramaterized Maze constructor reads in variables
                and information to create all MazeLevels
 * Parameters: ifstream& reader
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Maze::Maze(ifstream& reader){
  reader >> numLevels;
  reader >> height;
  reader >> width;
  reader.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  student = new IntrepidStudent();

  for(int i = 0; i < numLevels; i++){
    MazeLevel* level = new MazeLevel(reader, height, width);
    level->setStudent(student);
    level->getStart()->setPerson(student);
    maze.push_back(level);
  }

}

/******************************************************************
 * Function: ~Maze()
 * Description: Maze destructor deletes maze of MazeLevel pointers
                and deletes the student
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Maze::~Maze(){
  for(int i = 0; i < numLevels; i++){
    delete maze.at(i);
  }
  delete student;

}

/******************************************************************
 * Function: beginGame(bool& passed)
 * Description: Runs through the process of an entire game of
                Escape CS 162 repeated for each level in the maze.
                Returns whether the student passed or not.
 * Parameters: bool& passed
 * Pre-Conditions: Entire maze is initialized
 * Post-Conditions: Student has passed or failed CS 162 maze.
******************************************************************/
void Maze::beginGame(bool& passed){
  cout << "WELCOME TO ESCAPE CS 162!" << endl;

  for(int i = 0; i < numLevels; i++){       /* for every level in the maze */
    cout << "You started a new level!" << endl;
    MazeLevel* curLevel = maze.at(i);
    OpenSpace* studSpace = dynamic_cast<OpenSpace*>(curLevel->getLocation(student->getRow(), student->getCol()));
    bool finishedLevel = false;
    while(!finishedLevel){                  /* while they have not finished */
      curLevel->movePerson(curLevel->getTA1());
      curLevel->movePerson(curLevel->getTA2());     /* move TAs */
      if(curLevel->caughtByTA()){   /* check for catch */
        cout << "OH NO! A TA caught you!" << endl;
        studSpace->setPerson(NULL);
        curLevel->resetLevel();
      }
      curLevel->displayMaze();

      char choice;
      choice = checkInput("Enter 'm' to move, 'p' to use skill, or 'u' to climb ladder:", "mpu");

      if(choice == 'm'){          /* user chose to move */
        curLevel->movePerson(student);
        studSpace = dynamic_cast<OpenSpace*>(curLevel->getLocation(student->getRow(), student->getCol()));
        if(studSpace->getHasSkill()){   /* check for skill */
          cout << "You found a skill!" << endl;
          student->setNumSkills(student->getNumSkills() + 1);
          cout << "Now you have: " << student->getNumSkills() << " skills!" << endl;
          studSpace->setHasSkill(false);
        }

        curLevel->displayMaze();
        if(i == numLevels - 1){     /* check for Instructor */
          if(curLevel->checkInstructor()){
            cout << "You have reached the Instructor. He judges you." << endl;
            if(student->getNumSkills() > 2){
              cout << "YOU PASS AND ESCAPE CS 162!!" << endl;
              passed = true;
            } else {
              cout << "YOU FAIL. Time to Restart ;)" << endl;
            }
            return;
          }
        }
        if(curLevel->caughtByTA()){     /* check for catch */
          cout << "OH NO! A TA caught you!" << endl;
          curLevel->displayMaze();
          studSpace->setPerson(NULL);
          curLevel->resetLevel();
        }
      } else if(choice == 'p'){         /* use chose to use skill */
        if(student->getNumSkills() > 0){
          student->setNumSkills(student->getNumSkills() - 1);
          curLevel->setIsAppeased(true);
          curLevel->setTurnsLeft(10);
        } else {
          cout << "You have no skills to use." << endl;
        }
      } else if(choice == 'u'){         /* use chose to climb ladder */
        studSpace = dynamic_cast<OpenSpace*>(curLevel->getLocation(student->getRow(), student->getCol()));
        if(studSpace == curLevel->getFinish()){
          finishedLevel = true;
        } else {
          cout << "You are not on the ladder." << endl;
        }
      }

      if(curLevel->getTurnsLeft() > 0){     /* decrement turns of appeasal */
        curLevel->setTurnsLeft(curLevel->getTurnsLeft() - 1);
      } else {
        curLevel->setIsAppeased(false);
      }
    }

    if(i < numLevels - 1){      /* get student ready for next level */
      cout << "You finished this level!" << endl;
      curLevel->getFinish()->setPerson(NULL);
      student->setLocation(1, 1);
    }
  }
}

/******************************************************************
 * Function: checkInput
 * Description: Performs a do-while using question to only accept
 * 		characters that are in valid. Returns char
 * 		version of input.
 * Parameters: string question, string valid
 * Pre-Conditions: question and valid must not be empty
 * Post-Conditions: question and valid don't change
******************************************************************/
char Maze::checkInput(string question, string valid){
   string var_str;
   size_t found;

   do{
      cout << question << endl;
      cin >> var_str;
      found = var_str.find_first_not_of(valid);
   }
   while(found != string::npos && var_str.length() < 2);

   return var_str[0];
}
