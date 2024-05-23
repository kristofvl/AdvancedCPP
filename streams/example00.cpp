/* change the following code to output the server reply straight to a local html file
   and add exception handling in case of file or connection problems */
#include <fstream>
#include <boost/asio.hpp>
int main() {
  const int bufferSize = 4096;
  boost::asio::ip::tcp::iostream socket("www.example.com", "http");  // socket stream
  std::ofstream outputFile("myTest.txt");  // stream to output file
  outputFile << "Reply of server:\n";
  char reply[bufferSize];
  socket << "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: Close\r\n\r\n";
  socket << std::flush; 
  socket.read(reply, bufferSize);
  outputFile << reply;  // output the reply of server to our text file
  return 0;  
}
