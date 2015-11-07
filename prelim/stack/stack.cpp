#include <iostream>

template <typename T>
class Node {
public:
	Node<T> * next;
	T val;

	Node(T v, Node<T> * n) {
		val = v;
		next = n;
	}
};

template <typename T>
class Stack {
public:
	Node <T> * tos;

	Stack () {
		tos = nullptr;
	}

	~Stack () {
		while (tos != nullptr)
			pop();
	}

	Stack(const Stack<T> & copy) {
		tos = nullptr;

		Node<T> * tmp = copy.tos;
		while (tmp != nullptr) {
			push(tmp->val);
			tmp = tmp->next;
		}
	}

	void swap(Stack<T> & s) {
		Node<T> *tmp = s.tos;
		s.tos = tos;
		tos = tmp;
	}

	Stack<T> & operator=(Stack<T> rhs) {
		swap(rhs);
		return *this;
	}

	void push(T item) {
		Node<T> * n = new Node<T>(item, tos);
		tos = n;
	}

	T pop() {
		T r = tos->val;
		Node<T> * tmp = tos->next;
		delete tos;
		tos = tmp;
		return r;
	}
};

int main() {
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	std::cout << "s: ";
	for (Node <int> * t1 = s.tos; t1 != nullptr; t1 = t1->next) {
		std::cout << t1->val;
	}
	std::cout << std::endl;

	Stack<int> copy(s);
	Stack<int> assigned = s;

	std::cout << std::endl;

	std::cout << "popped: " << s.pop() << std::endl;
	std::cout << "popped: " << s.pop() << std::endl;

	std::cout << "s: ";
	for (Node <int> * t1 = s.tos; t1 != nullptr; t1 = t1->next) {
		std::cout << t1->val;
	}
	std::cout << std::endl;

	std::cout << "copy: ";
	for (Node <int> * t1 = copy.tos; t1 != nullptr; t1 = t1->next) {
		std::cout << t1->val;
	}
	std::cout << std::endl;

	std::cout << "assigned: ";
	for (Node <int> * t1 = assigned.tos; t1 != nullptr; t1 = t1->next) {
		std::cout << t1->val;
	}
	std::cout << std::endl;


}