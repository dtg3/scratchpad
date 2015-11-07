// 2012 Fall Problem 1

#include <iostream>
#include <cmath>

using std::min;

template <typename T>
const T MAX_ITEM = T(1000);

template <typename T>
struct Node {
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
	Node<T> * tos;

	Stack() {
		tos = nullptr;
	}

	~Stack() {
		while (tos != nullptr) {
			pop();
		}
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

	T getmin() {
		T m = MAX_ITEM<T>;
		Node<T> * tmp = tos;
		while (tmp != nullptr) {
			m = min(m, tmp->val);
			tmp = tmp->next;
		}
		return m;
	}
};

int main() {
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	for (Node <int> * t1 = s.tos; t1 != nullptr; t1 = t1->next) {
		std::cout << t1->val;
	}
	std::cout << std::endl;

	std::cout << "popped: " << s.pop() << std::endl;
	std::cout << "popped: " << s.pop() << std::endl;

	for (Node <int> * t1 = s.tos; t1 != nullptr; t1 = t1->next) {
		std::cout << t1->val;
	}
	std::cout << std::endl;

	std::cout << "min: " << s.getmin() << std::endl;	

}