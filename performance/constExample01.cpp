/* An example that defines an Item class and a MyItemList class that
   holds a list of Items. It demonstrates const and non-const overloads
   of the operator[], to show how the correct overload is selected,
   depending on the const-ness of the object (list or constList).
   */

#include <iostream>

// Simple Item class
class Item {
  std::string name;
 public:
  Item(const std::string& name = "") : name(name) {}
  void setName(const std::string & newName) { name = newName; }
  std::string getName() const { return name; }
};

// MyItemList class with const and non-const operator[] overloads
class MyItemList {
  std::vector<Item> items_;
 public:
  MyItemList(std::initializer_list<Item> items) : items_(items) {}
  // Non-const version: allows modification of items
  Item & operator[](int index) {
    std::cout << "non-const operator[]\n";
    return items_[index];
  }
  // Const version: read-only access
  const Item & operator[](int index) const {
    std::cout << "const operator[]\n";
    return items_[index];
  }
};

int main() {
  // example for non-const access: items can be modified
  MyItemList list = { Item("Sword"), Item("Shield"), Item("Potion") };
  list[0].setName("Great Sword");
  std::cout << "Item 0: " << list[0].getName() << "\n";

  // example for const access: cannot modify items
  const MyItemList constList = list;
  std::cout << "Item 1 (const access): " << constList[1].getName() << "\n";
  // this would result in compile error:
  // constList[1].setName("Magic Shield");
}
