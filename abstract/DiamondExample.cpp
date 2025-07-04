#include <iostream>

struct Person {  // Person:
   Person() { std::cout << "Person constructed.\n"; };
   void print() { std::cout << "hello\n"; }
};
struct Faculty : public Person {  // Faculty is a Person
  Faculty() { std::cout << "Faculty constructed.\n"; };
};
struct Student : public Person {  // Student is a Person
  Student() { std::cout << "Student constructed.\n"; };
};
struct PhDStudent : public Faculty, public Student {  // PhDStudent is both
  PhDStudent() { std::cout << "PhDStudent constructed.\n"; };
};

int main() {
  PhDStudent phd;  // note: this object will contain two copies of a person
  phd.print();
}
