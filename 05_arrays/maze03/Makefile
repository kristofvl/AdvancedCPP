# Rule to make our program when
# ’drawMaze.o’ and ’maze.o’ are compiled:
mazeGame: drawMaze.o mazeGame.o
	g++ drawMaze.o mazeGame.o -o maze -lncurses
# Rule for dependency 'maze.o':
mazeGame.o: mazeGame.cpp drawMaze.h
	g++ -c mazeGame.cpp -std=c++11
# Rule for dependency 'drawMaze.o':
drawMaze.o: drawMaze.cpp drawMaze.h
	g++ -c drawMaze.cpp -std=c++11
