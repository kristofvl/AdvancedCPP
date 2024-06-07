#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> students;
  students["Aaron"] = 173923;   // insert new map elements
  students["Zachary"] = 183211;
  students.insert( {"Patrick", 172932} );
  students.insert( std::pair<std::string,int>("Arnold", 161010) );

  for (auto const& x : names)  // since C++11
    std::cout << "key:" << x.first << ",val:" << x.second << "\n";

  for (auto const& [key, val] : students)  // since C++17
    std::cout << "key:" << key << ",val:" << val << "\n";

  return 0;
}
