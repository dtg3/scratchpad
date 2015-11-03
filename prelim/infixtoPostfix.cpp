// unfinished

#include <string>

template <typename T>
class Node {
public:
	Node<T> * next;
	T val;

	Node(T v, Node<T> * n) {
		next = n;
		val = v;
	}

	~Node() { }
};

template <typename T>
class Stack {
public:
	Node<T> * bottom;
	Stack() {
		bottom = nullptr;
	}

	void push(T val) {
		if (bottom == nullptr
			bottom = n;

		Node<T> * n = new Node(val, bottom);
	}

	void pop() {
		Node<T> current = bottom;
		while (current.next != nullptr) {
			current = current.next;
		}
		delete current;
	}
};


int main() {

	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	Node<int> * temp = s.bottom;
	while (temp != nullptr) {

	}

	return 0;
}
