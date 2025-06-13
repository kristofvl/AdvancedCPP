/* Implement the two override methods of RLEstreambuf to implement a basic run
   length encoding compression of a string being sent to an output stream. The
   output of the program below should give "6A5B2CD2A6C3A".
   Note that EOF is a special terminator character that should not be handled.
   Use sputc() to write characters, and '0'+count to write the ascii digits.
   */

#include <iostream>

class RLEstreambuf : public std::streambuf {
 public:
  RLEstreambuf(std::streambuf* dest) : dest(dest), last_char(EOF), count(0) {}
 protected:
  int overflow(int ch) override;  // override overflow to handle the compression
  int sync() override;            // flush last data (last character) when done
 private:
  std::streambuf* dest;  // destination stream buffer
  int last_char;         // previous character
  int count;             // count of consecutive same characters
};

int RLEstreambuf::overflow(int ch) {
  if (ch == last_char) {  // if same character
    count++;
  } else {  // if different character
    if (last_char != EOF) {  // output count and last character:
      if (count > 1)
        dest->sputc( '0'+count );
      dest->sputc( last_char );
    }
    last_char = ch;  // update to new character and reset count
    count = 1;
  }
  return 0;  // 0 -> success
}

int RLEstreambuf::sync() {
  if (last_char != EOF) {
    if (count > 1)
      dest->sputc( '0'+count );
    dest->sputc( last_char );
  }
  return 0;  // 0 -> success
}

int main() {
  RLEstreambuf rleBuf(std::cout.rdbuf());
  std::ostream rleOut(&rleBuf);
  std::string input = "AAAAAABBBBBCCDAACCCCCCA";  // Input string to compress
  rleOut << input;  // the output is automatically RLE compressed
  rleOut.flush();  // leads to sync being called to output last character
  std::cout << '\n';
}
