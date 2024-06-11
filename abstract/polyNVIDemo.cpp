#include <iostream>
#include <cstdlib>

class Animal {  // Animal class stores the species and prints this in print()
 protected:
  std::string _species;
 public:
  Animal(std::string species) { _species = species; }
  void print() const { std::cout << getSound() << std::endl; }
 private:
  virtual std::string getSound() const { return "I'm " + _species; };
};

class Dog : public Animal {  // Dogs inherit species from Animal and have a name
 protected:
  std::string _name;
 public:
  Dog(std::string name) : Animal("dog"), _name(name) {}
 private:
  std::string getSound() const { return "I am " + _name + ". Bark!"; }
};

class Fish : public Animal {  // Fishes have species and subspecies
 protected:
  std::string _subspecies;
 public:
  Fish(std::string subspecies) : Animal("fish"), _subspecies(subspecies) {}
 private:
  std::string getSound() const { return "I'm " + _subspecies + " (fish)"; }
};

int main() {
  Animal * animals[4];
  animals[0] = new Dog("Snowy");      // animals[] has pointers
  animals[1] = new Fish("Salmon");    // to objects of different
  animals[2] = new Dog("Scooby");     // subclasses (Dog, Fish, etc.)
  animals[3] = new Animal("some animal");  // or the animal base class
  for (int i=0; i<15; i++) {
   Animal * a = animals[rand() % 4];  // a is a polymorph variable: its
   a->print();                        // print's behavior depends on the 
  }                                   // object that a points to
  return 0;
}
