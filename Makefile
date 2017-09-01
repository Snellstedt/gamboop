#OBJS specifies which files to compile as part of the project
OBJS = ~/programs/gamboop/src/main.cpp 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = gamboop

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS)  -O3 -std=c++11 -o $(OBJ_NAME)
#debug build
debug : $(OBJS)
	g++ $(OBJS) -g3 -std=c++11 -o $(OBJ_NAME)