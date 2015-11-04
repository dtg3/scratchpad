// unfinished

#include <string>
#include <iostream>

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
		Node<T> * n = new Node<T>(val, bottom);
		bottom = n;
	}

	void pop() {
		Node<T> * temp = bottom->next;
		delete bottom;
		bottom = temp;
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
		std::cout << temp->val << std::endl;
		temp = temp->next;
	}

	s.pop();
	s.pop();
	Node<int> * temp1 = s.bottom;
	while (temp1 != nullptr) {
		std::cout << temp1->val << std::endl;
		temp1 = temp1->next;
	}

	return 0;
}
