# Rule to make our program when
# ’Maze.o’ and ’mazeGame.o’ are compiled:
mazeGame: Maze.o mazeGame.o
	g++ Maze.o mazeGame.o -o maze -lncurses
# Rule for dependency 'mazeGame.o':
mazeGame.o: mazeGame.cpp Maze.h
	g++ -c mazeGame.cpp -std=c++11
# Rule for dependency 'Maze.o':
Maze.o: Maze.cpp Maze.h
	g++ -c Maze.cpp -std=c++11
