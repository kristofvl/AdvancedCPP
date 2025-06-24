#include <iostream>
#include <thread>

// Complete this custom exception class for server reply timeouts:
class TimeoutException : public std::exception {
  std::string message;


};

class ServerPinger {  // this class simulates pinging a server
 public:
  void ping(const std::string& server, int timeoutMs) {
    std::cout << "Pinging " << server << " with timeout " << timeoutMs << " ms\n";
    // Simulate random response time:
    int replyTime = 100 + (std::rand() % 1000); // reply takes 100–1099 ms
    std::this_thread::sleep_for(std::chrono::milliseconds(replyTime));
    // add code here to throw an exception if the reply takes more than
    // timeoutMs milliseconds:



    std::cout << "Ping successful, reply came in " << replyTime << " ms\n";
  }
};

int main() {
  ServerPinger pinger;
  try {
    pinger.ping("www.example.com", 500);  // 500 ms timeout
  }
  catch (const TimeoutException& e) {
    std::cerr << "Network problem: " << e.what() << '\n';
  }
}
