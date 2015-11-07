// 2013F problem 1
// Not another queue
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
class Queue {
public:
	Node<T> * head;

	Queue() {
		head = nullptr;
	}

	~Queue() {
		while (head != nullptr)
			dequeue();
	}

	Queue(const Queue<T> & copy) {
		head = nullptr;

		Node<T> * tmp = copy.head;
		while (tmp != nullptr) {
			enqueue(tmp->val);
			tmp = tmp->next;
		}
	}

	Queue<T> & operator=(Queue<T> rhs) {
		Node<T> * tmp = rhs.head;
		rhs.head = head;
		head = tmp;

		return *this;
	}

	void enqueue(T item) {
		Node<T> * n = new Node<T>(item, nullptr);

		// first item
		if (head == nullptr) {
			head = n;
		}

		// other items
		else {
			Node<T> * tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = n;
		}
	}

	T dequeue() {
		Node<T> * tmp = head->next;
		T v = head->val;
		delete head;
		head = tmp;
		return v;
	}
};

int main() {
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	std::cerr << "q: ";
	Node<int> *tmp = q.head;
	while (tmp !=  nullptr) {
		std::cerr << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cerr << std::endl;

	Queue<int> copy(q);
	Queue<int> assigned = q;

	std::cerr << "dequeued: " << q.dequeue() << std::endl;
	std::cerr << "dequeued: " << q.dequeue() << std::endl;

	std::cerr << "q: ";
	Node<int> *dmp = q.head;
	while (dmp !=  nullptr) {
		std::cerr << dmp->val << " ";
		dmp = dmp->next;
	}
	std::cerr << std::endl;

	std::cerr << "copy: ";
	Node<int> *dmp1 = copy.head;
	while (dmp1 !=  nullptr) {
		std::cerr << dmp1->val << " ";
		dmp1 = dmp1->next;
	}
	std::cerr << std::endl;

	std::cerr << "assigned: ";
	Node<int> *dmp2 = assigned.head;
	while (dmp2 !=  nullptr) {
		std::cerr << dmp2->val << " ";
		dmp2 = dmp2->next;
	}
	std::cerr << std::endl;

}