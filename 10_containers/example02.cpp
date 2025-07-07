#include <iostream>  // std::cout, std::runtime_error, std::exception, std::cerr

template <class Data> class QueueElement;  // declaration of the element class

template <class Data> class UQueue {  // Class for an unlimited queue of QueueElements
 public:
  UQueue() { head = tail = nullptr; }
  ~UQueue() { clear(); };
  void put(Data data);
  Data get();
  bool isEmpty() const;
  void clear();
 private:
  QueueElement<Data> * head;  // pointer to element to put
  QueueElement<Data> * tail;  // pointer to element to get from
};

template <class Data> class QueueElement {  // element class, hidden from users
 public:
  QueueElement(Data data) : data(data) , next(nullptr) {}
  Data data;
  QueueElement * next;
};

/*********************************************/

template <class Data>
void UQueue<Data>::clear() {  // iteratively clear the queue of all elements
  QueueElement<Data> * elem, * elem_next;
  for (elem = head; elem != nullptr; elem = elem_next) {
    elem_next = elem->next;
    delete elem;
  }
  head = tail = nullptr;
}

template <class Data>
bool UQueue<Data>::isEmpty() const {  // check whether the queue is empty
  return head == nullptr;
}

template <class Data>
void UQueue<Data>::put(Data data) {  // put in new data element at tail
  QueueElement<Data> *node = new QueueElement<Data>(data);
  if (isEmpty()) {
    head = tail = node;
  } else {
    tail = tail->next = node;  // tail is guaranteed to be valid
  }
}

template <class Data>
Data UQueue<Data>::get() {  // get and remove element from head
  int retVal;
  if (!isEmpty()) {
    retVal = head->data;
    QueueElement<Data> *second = head->next;
    delete head;
    head = second;
  } else {
    throw std::runtime_error("uqueue: empty on get");
  }
  return retVal;
}

int main() {
  UQueue<int> q;
  for (auto i = 0; i < 128; i++) {
    q.put(i);
  }
  try { while (true) std::cout << q.get() << " "; }
  catch (...) { std::cout << "\n"; }
}
