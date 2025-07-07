#include <iostream>

template <class T> class MyClass;

template <class T>
std::ostream & operator<<(std::ostream & out, const MyClass<T> & classObj);

template <class T> class MyClass {  // a very basic template class with a friend operator
  T c;
 public:
  MyClass(T c) : c(c) {}
  // <> tells C++ this is a friend declaration of a function template instantiated for type T:
  friend std::ostream & operator<< <>(std::ostream & out, const MyClass<T> & classObj);
};

// operator << uses template U, which is used on the MyClass parameter:
template <class T>
std::ostream & operator<<(std::ostream & out, const MyClass<T> & classObj) {
  out.put(classObj.c);
  return out;
}

int main() {
  MyClass<char> t('?');
  std::cout << t << '\n';
}
