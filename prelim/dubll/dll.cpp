#include <iostream>

template <typename T>
class Node {
public:
  T data;
  Node<T> *next;
  Node<T> *previous;

  Node(): data() {
    next = NULL;
    previous = NULL;
  }

  Node(const T& value) {
    data = valuel
  }

};

template <typename T>
class DubLL {
private:
  Node<T> *front;
  Node<T> *back;

public:
  DubLL() {
    front = NULL;
    back = NULL;
  }

  DubLL(const DubLL<T>& original) {

  }

}


int main () {
  return 0;
}
