#include <iostream>
#include <cstdlib>

class Animal {  // Animal class stores the species and prints this in print()
 protected:
  std::string _species;
 public:
  Animal(std::string species) { _species = species; }
  virtual void print() { std::cout << "I'm " +  _species << '\n'; }
};

class Dog : public Animal {  // Dogs inherit species from Animal and have a name
 protected:
  std::string _name;
 public:
  Dog(std::string name) : Animal("dog"), _name(name) {}
  void print() { std::cout << "I am " << _name << ". Bark!\n"; }
};

class Fish : public Animal {  // Fishes have species and subspecies
 protected:
  std::string _subspecies;
 public:
  Fish(std::string subspecies) : Animal("fish"), _subspecies(subspecies) {}
  void print() { std::cout << "I'm " << _subspecies << " (fish)\n"; }
};

int main() {
  Animal * animals[4] = {new Dog("Snowy"), new Fish("Salmon"),
                         new Dog("Scooby"), new Animal("some animal")};
  for (int i=0; i<15; i++) {
   Animal * a = animals[rand() % 4];  // a is a polymorph variable: its
   a->print();                        // print's behavior depends on the
  }                                   // object that a points to
}
