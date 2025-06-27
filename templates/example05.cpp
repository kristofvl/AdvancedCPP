#include <iostream>

template <class T> class MyClass {  // a very basic template class
 public:
  MyClass(T c) : c(c) {}
  T c;
};

// operator << uses template U, which is used on the MyClass parameter:
template <class U>
std::ostream & operator<<(std::ostream & out, const MyClass<U> & classObj) {
  out.put(classObj.c);
  return out;
}

int main() {
  MyClass<char> t('?');
  std::cout << t << '\n';
}
