#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> name( {"John", "George", "Paul", "Smith"} );
  
  std::cout << "name size=" << name.size() << " of " << name.max_size();
  std::cout << " capacity=" << name.capacity() << "\n";
  
  for (auto i = name.begin(); i < name.end(); i++)  // use iterators
    std::cout << *i << '\n';
  
  name.insert(name.begin()+2, "Tom");
  
  for (const std::string& i : name)  // use range based (C++11) for loop
    std::cout << i << '\n';
  
  return 0;
}
