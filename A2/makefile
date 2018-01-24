#Makefile
#set up flags
CXX = g++
CXXFLAGS = -std=c++11

#phony target make all
all: myAnts

#compile final executable
myAnts: initialization.o time_0.o time_step.o myAnts.o
	${CXX} ${CXXFLAGS} initialization.o time_0.o time_step.o myAnts.o -o myAnts

#compile initialization module
initialization.o: initialization.cc
	${CXX} ${CXXFLAGS} initialization.cc -c -o initialization.o

#compile the module setting things up at the first time step 
time_0.o: time_0.cc
	${CXX} ${CXXFLAGS} time_0.cc -c -o time_0.o

#compile the module for a single time step after the first
time_step.o: time_step.cc
	${CXX} ${CXXFLAGS} time_step.cc -c -o time_step.o

#compile module with main function 
myAnts.o: myAnts.cc initialization.h time_0.h time_step.h
	${CXX} ${CXXFLAGS} myAnts.cc -c -o myAnts.o

#remove all compiled files
clean:
	rm -f myAnts initialization.o time_0.o time_step.o myAnts.o