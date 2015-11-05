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
    data = value;
  }

};

template <typename T>
class DubLL {
public:

  Node<T> *frnt;
  Node<T> *bak;

  DubLL() {
    frnt = NULL;
    bak = NULL;
  }

  DubLL(const DubLL<T>& original) {
    frnt = NULL;
    bak = NULL;
    Node<T> *temp = original.frnt;
    while (temp != NULL) {
      sendToBack(temp->data);
      temp = temp->next;
    }
  }

  DubLL& operator= (DubLL<T> original){
    swap(original);
    return *this;
  }

  void swap (DubLL<T>& original){
    Node<T> *tempBack = original->frnt;
    Node<T> *tempFront = original->bak;

    original->frnt = frnt;
    original->bak = bak;

    frnt = tempFront;
    bak = tempBack;
  }

  void sendToBack(const T& value) {
    if (frnt == NULL && bak == NULL){
      bak = new Node<T>(value);
      frnt = bak;
    }
    else {
      Node<T> *temp = new Node<T>(value);
      bak->next = temp;
      temp->previous = bak;
      bak = bak->next;
    }
  }

  void sendToFront(const T& value) {
    if (frnt == NULL && bak == NULL){
      frnt = new Node<T>(value);
      bak = frnt;
    }
    else {
      Node<T> *temp = new Node<T>(value);
      frnt->previous = temp;
      temp->next = frnt;
      frnt = frnt->previous;
    }
  }

  T front() {
    return frnt->data;
  }

  T back() {
    return bak->data;
  }

  ~DubLL() {
    while(frnt != NULL) {
      Node<T> *temp = frnt;
      frnt = frnt->next;
      delete temp;
    }
  }
};


int main () {
  DubLL<int> dlist;

  dlist.sendToFront(10);

  std::cout << dlist.front() << "\n";
  std::cout << dlist.back() << "\n";

  dlist.sendToFront(9);
  std::cout << dlist.front() << "\n";
  std::cout << dlist.back() << "\n";

  dlist.sendToBack(11);
  std::cout << dlist.front() << "\n";
  std::cout << dlist.back() << "\n";

  std::cout << dlist.front() << "\n";
  std::cout << dlist.back() << "\n";

  DubLL<int> dlist2(dlist);

  return 0;
}
