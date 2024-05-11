/* Class Maze: All data and functions related to upkeeing a maze */
#include "Maze.h"  // class definition

// initialize maze data and set up window in ncurses, use color
Maze::Maze(std::string mazeFile) {
	// read the maze file:
	std::ifstream fileData(mazeFile);
	if (fileData) {
		char symbol; auto lines = 0, cols = 0;
    std::string str;  // string to count commas in
    while (std::getline(fileData, str)) {
      if (str.length() > 1 && cols == 0)
        cols = std::count_if(str.begin(), str.end(),
                             [](char c){return c==',';});
      lines++;
    }
    this->mazeXlen = cols+1; this->mazeYlen = lines;
		// then fill the maze array:
    fileData.close();
    std::ifstream fileData(mazeFile);
    auto iter = 0;
    maze = new uint8_t[mazeYlen*mazeXlen];
    while (fileData >> symbol) {
      if (symbol=='1' || symbol=='0') {
        maze[iter] = (symbol-'0');
        iter++;
      }
    }
  }
  // set up everything for drawing:
  initscr(); curs_set(0);  // init ncurses window, hide cursor
  noecho();  // don't show keys pressed in terminal
  start_color();  // use color, with these color pairs:
  init_pair(1, COLOR_BLACK, COLOR_BLACK);   // coridors
  init_pair(2, COLOR_YELLOW, COLOR_GREEN);  // walls
  init_pair(3, COLOR_WHITE, COLOR_BLACK);  // player
}

Maze::~Maze() {
	endwin();  // close ncurses window
	delete[] maze;
}

// (re)draw the maze with player as symbol, in colorpair:
void Maze::draw(char symbol, int colorpair) {
	for ( auto line = 0; line < LINES; line++) {
    for ( auto col = 0; col < COLS; col++) {
      attron(COLOR_PAIR( get(col, line)? colorpair: 1));
      mvaddch(line, col, get(col, line)? symbol: ':' );  // draw ':' as space
      attroff(COLOR_PAIR(get(col, line)? colorpair: 1));
    }
  }
}
