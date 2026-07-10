#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> name( {"John", "George", "Paul", "Smith"} );
  std::cout << "name size=" << name.size() << " of " << name.max_size();
  std::cout << " capacity=" << name.capacity() << "\n";
  for (auto i = name.begin(); i < name.end(); i++)  // use iterators
    std::cout << *i << '\n';
  name.insert(name.begin()+2, "Tom");
  for (auto i : name)  // use range based (C++11) for loop
    std::cout << i << '\n';

  // example for insert iterator:
  std::vector<std::string> aVector = {"John", "George"};
  std::vector<std::string> bVector = {"Paul", "Smith"};
  std::copy( aVector.begin(), aVector.end(), std::back_inserter(bVector));
  std::cout << "aVector after insertion:\n";
  for (auto i : bVector) std::cout << i << '\n';

  // example for move iterator:
  std::vector<std::string> hello1 = {"Hello", "World"};
  std::vector<std::string> hello2(
        std::make_move_iterator( hello1.begin() ),
        std::make_move_iterator( hello1.end() )    );
  std::cout << "hello1 after move:\n";
  for (auto i : hello1) std::cout << i << '\n';
  std::cout << "hello2 after move:\n";
  for (auto i : hello2) std::cout << i << '\n';
}
