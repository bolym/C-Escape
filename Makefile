CC=g++ 
EXE_FILE=escape

all: $ (EXE_FILE)

$ (EXE_FILE): TA.o instructor.o intrepidStudent.o mazePerson.o openSpace.o wall.o mazeLocation.o mazeLevel.o maze.o TA.hpp instructor.hpp intrepidStudent.hpp mazePerson.hpp openSpace.hpp wall.hpp mazeLocation.hpp mazeLevel.hpp maze.hpp app.cpp
	$(CC) TA.o instructor.o intrepidStudent.o mazePerson.o openSpace.o wall.o mazeLocation.o mazeLevel.o maze.o app.cpp -std=c++11 -o $(EXE_FILE)

TA.o: TA.hpp TA.cpp
	$(CC) -c TA.cpp

instructor.o: instructor.hpp instructor.cpp
	$(CC) -c instructor.cpp

intrepidStudent.o: intrepidStudent.hpp intrepidStudent.cpp
	$(CC) -c intrepidStudent.cpp

mazePerson.o: mazePerson.hpp mazePerson.cpp
	$(CC) -c mazePerson.cpp

openSpace.o: openSpace.hpp openSpace.cpp
	$(CC) -c openSpace.cpp

wall.o: wall.hpp wall.cpp
	$(CC) -c wall.cpp

mazeLocation.o: mazeLocation.hpp mazeLocation.cpp
	$(CC) -c mazeLocation.cpp

mazeLevel.o: mazeLevel.hpp mazeLevel.cpp
	$(CC) -c mazeLevel.cpp -std=c++11

maze.o: maze.hpp maze.cpp
	$(CC) -c maze.cpp -std=c++11

clean:
	rm -f *.o $(EXE_FILE)
