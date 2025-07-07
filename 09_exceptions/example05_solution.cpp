#include <iostream>

// Custom exception class for tampered messages
class TamperException : public std::exception {
  std::string message;
 public:
  TamperException(const std::string& msg) :
    message("Message integrity check failed: '" + msg + "'") {}
  const char* what() const noexcept override {
    return message.c_str();
  }
};

// Simulated message struct with simple hash-based integrity
struct Message {
  std::string content;
  std::size_t checksum;
  Message(const std::string& text) : content(text),
    checksum(std::hash<std::string>{}(text)) {}
};

// Communication channel
class SecureChannel {
 public:
  void sendMessage(const Message& msg) {
    std::cout << "Sending message: " << msg.content << '\n';
  }
  void receiveMessage(const Message& msg) {
    std::size_t recalculated = std::hash<std::string>{}(msg.content);
    if (recalculated != msg.checksum) {
      throw TamperException(msg.content);
    }
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
