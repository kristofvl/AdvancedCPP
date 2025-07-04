/* Example of the Visitor Pattern, using std::variant and std::visit */

#include <iostream>
#include <variant>
#include <string>

// Define different event types
struct ClickEvent { int x, y; };
struct KeyEvent { char key; };
struct ResizeEvent { int width, height; };
// An Event is a variant of all possible events
using Event = std::variant<ClickEvent, KeyEvent, ResizeEvent>;

// Handle Events with a Visitor:
void handleEvent( const Event & event ) {
  // We use std::visit and a lambda function on event:
  std::visit( [](auto&& e) {
      using T = std::decay_t<decltype(e)>;  // see explanations below
      if constexpr (std::is_same_v<T, ClickEvent>) {
        std::cout << "Click at " << e.x << ',' << e.y;
      } else if constexpr (std::is_same_v<T, KeyEvent>) {
        std::cout << "Key pressed: " << e.key;
      } else if constexpr (std::is_same_v<T, ResizeEvent>) {
        std::cout << "Window now " << e.width << "x" << e.height;
      } else std::cout << "Unknown event.";
      std::cout << '\n';
    }, event);
  // find out the type of event e (ClickEvent, Key Event, ResizeEvent):
  // - auto && e is a 'forwarding reference', which means:
  //   "bind e to whatever type and value category is passed"
  // - std::decay<T> is a type trait that transforms a type T into
  //   the form it would have, if passed by value to a function.
  // - decltype(expression) inspects an expression and deduces its
  //   exact type, without evaluating the expression.
}

int main() {
  // Create different events, and afterwards handle them through Visitor:
  Event e[] = { ClickEvent{10,20}, KeyEvent{'A'}, ResizeEvent{800,600} };
  for (auto event : e) handleEvent(event);
}
