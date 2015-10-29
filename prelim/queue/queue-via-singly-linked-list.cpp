// 2011 spring data structures prelims problem 1
// generic queue class uses single linked list
#include <iostream>

template <class T>
class Node {
public:
	Node() {
		next = 0;
	}
	Node(T val) {
		next = 0;
		value = val;
	}

	Node<T> * next;
	T value;
};

template <class T>
class Queue {
public:
	Node<T> * back;
	Node<T> * front;

	// default constructor
	Queue() {
		back = 0;
		front = 0;
	}

	// destructor
	~Queue() {
		while (front != NULL)
			dequeue();
	}

	// copy-constructor
	Queue(const Queue<T> & copy) {
		front = 0;
		back = 0;

		Node<T> * pos = copy.front;
		while (pos != 0) {
			enqueue(pos->value);
			pos = pos->next;
		}
	}

	// assignment operator
	Queue & operator=(const Queue & rhs) {
		Node<T> * pos = rhs.front;
		while (pos != 0) {
			enqueue(pos->value);
			pos = pos->next;
		}

		return *this;
	}

	// enqueue
	void enqueue(T val) {
		Node<T> * n = new Node<T>(val);

		// front element
		if (front == 0) {
			front = n;
			back = n;
		}
		// any other element
		else {
			back->next = n;
			back = n;
		}
	}

	// dequeue
	T dequeue() {
		Node<T> * remove = front;
		front = front->next;
		T val = remove->value;
		delete remove;
		return val;
	}
};


// test
int main() {
	Queue<int> q;

	for (int i = 0; i < 10; ++i)
		q.enqueue(i);

	Queue<int> assigned = q;
	Queue<int> copied(q);

	for (int i = 0; i < 10; ++i)
		std::cout << q.dequeue();
	std::cout << std::endl;

	for (int i = 0; i < 10; ++i)
		std::cout << assigned.dequeue();
	std::cout << std::endl;	

	for (int i = 0; i < 10; ++i)
		std::cout << copied.dequeue();
	std::cout << std::endl;	

	return 0;
}
