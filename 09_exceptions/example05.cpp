#include <iostream>

// Custom exception class for tampered messages:
// complete this class so that it can be used below and returns
// "Message integrity check failed: " followed by the message
class TamperException : public std::exception {
  std::string message;
  // add you code here
};

struct Message {  // class for a checksum'd message
  std::string content;   // the message content
  std::size_t checksum;  // the message checksum
  Message(const std::string& text) : content(text),
    checksum(std::hash<std::string>{}(text)) {}
};

class SecureChannel {  // class for implementing a communication channel
 public:
  void sendMessage(const Message& msg) {
    std::cout << "Sending message: " << msg.content << '\n';
  }
  void receiveMessage(const Message& msg) {
    // note that std::hash is a functor (hash function):
    std::size_t recalculated = std::hash<std::string>{}(msg.content);
    // add code below to check the message integrity and throw an
    // appropriate exception if this is not the case:


    std::cout << "Message received safely: " << msg.content << '\n';
  }
};

int main() {
  SecureChannel channel;
  Message msg("Hello, this is a secure message.");  // message to send
  try {
    channel.sendMessage(msg);
    Message tampered = msg;  // we tamper with the message here
    tampered.content = "Hello, this is a hacked message.";
    channel.receiveMessage(tampered);  // Will throw exception
  }
  catch (const TamperException& e) {
    std::cerr << "Security Alert: " << e.what() << '\n';
  }
}
