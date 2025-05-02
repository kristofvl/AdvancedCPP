#include <iostream>

void initX(char row[7]) {
  // This does not work:
  //for (auto & cell : row) {
  //  cell = 'X';
  //}
  for (auto c=0; c<7; c++) {
    row[c] = 'X';
  }
}

int main() {
  char arr[7][7];
  // initialize by passing rows to a function:
  for (auto & row: arr) {
    initX(row);
  }
  // print out the matrix:
  for (auto & row: arr) {
    for (auto & cell: row) {
      std::cout << cell;
    }
    std::cout << '\n';
  }
}
