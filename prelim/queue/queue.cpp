#include <iostream>

template <typename T>
class Node {
  public:
    T value;
    Node<T> *next;

    Node() {
      next = NULL;
    }

    Node(const T& val, Node<T>* n) {
      value = val;
      next = n;
    }
};

template <typename T>
class Queue {
  public:
    Queue(){
      front = NULL;
      back = NULL;
    }

    Queue(const Queue<T>& q) {
      front = NULL;
      back = NULL;

      Node<T>* pos = q.front;
      while (pos != NULL) {
        enqueue(pos->value);
        pos = pos->next;
      }
    }

    ~Queue(){
      while(front != NULL) {
        std::cerr << "EXTERMINATE\n";
        dequeue();
      }
    }

    void enqueue(const T& value) {
      if (front == NULL) {
        front = new Node<T>(value, NULL);
        back = front;
      }
      else {
        back->next = new Node<T>(value, NULL);
        back = back->next;
      }
    }

    void dequeue() {
      Node<T> *temp = front;
      T val = temp->value;
      front = front->next;
      delete temp;
    }

    T top() {
      return front->value;
    }

    T bottom() {
      return back->value;
    }

    bool empty() {
      return (front == NULL);
    }

  private:
    Node<T>* front;
    Node<T>* back;
};


int main(){
  Queue<int> q;

  std::cerr << "Enqueue / Dequeue\n";
  q.enqueue(19);
  q.enqueue(20);
  q.enqueue(40);

  while(!(q.empty())) {
    std::cout << q.top() << "\n";
    q.dequeue();
  }

  std::cerr << "Enqueue Existing\n";
  q.enqueue(1);
  q.enqueue(2);

  std::cerr << "COPY CTOR\n";
  Queue<int> q2 = q;

  std::cerr << "SHOW\n";
  while(!(q.empty())) {
    std::cout << "Q: " << q.top() << "\n";
    std::cout << "Q2: " << q2.top() << "\n";
    q.dequeue();
    q2.dequeue();
  }

  std::cerr << "DESTRUCTOR\n";
  Queue<int> q3;
  q3.enqueue(40000);
  q3.enqueue(50000);
  q3.enqueue(10000);
  q3.enqueue(10000);
  q3.enqueue(10000);
  q3.enqueue(10000);
  q3.enqueue(10000);
  q3.enqueue(10000);

}
