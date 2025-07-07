#include <iostream>
#include <set>
int main() {
  std::multiset<double> grades;  // the multiset to record grades:
  // inserting student grades in any order, with duplicates:
  grades.insert(1.7); grades.insert(2.3);  grades.insert(1.0);
  grades.insert(2.3); grades.insert(5.0);  grades.insert(2.3);
  grades.insert(4.0); grades.insert(1.0);  grades.insert(5.0);
  std::cout << "all grades sorted:\n";
  for (auto grade : grades) std::cout << grade << ' ';
  // count how often certain grades occured:
  std::cout << "\ngrade 5.0 was given " << grades.count(5.0) << " times.";
  std::cout << "\ngrade 2.3 was given " << grades.count(2.3) << " times.";
  // erase all 5.0 grades:
  grades.erase(5.0);
  std::cout << "\nall passing grades:\n";
  for (auto grade : grades) std::cout << grade << ' ';
  std::cout << '\n';
}
