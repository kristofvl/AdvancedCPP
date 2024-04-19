# Rule to make our program when
# ’drawMaze.o’ and ’maze.o’ are compiled:
maze: drawMaze.o maze.o
	g++ drawMaze.o maze.o -o maze -lncurses
# Rule for dependency 'maze.o':
maze.o: maze.cpp drawMaze.h
	g++ -c maze.cpp -std=c++11
# Rule for dependency 'drawMaze.o':
drawMaze.o: drawMaze.cpp drawMaze.h
	g++ -c drawMaze.cpp -std=c++11
