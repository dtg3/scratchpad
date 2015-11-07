// 2013s problem 1
#include <iostream>
#include <cmath>

using std::max;

template <typename item>
const item MIN_ITEM = item(0);

template <typename item>
class Node {
public:
	Node<item> * next;
	item val;

	Node(item v, Node<item> * n) {
		val = v;
		next = n;
	}
};

template <typename item>
class Queue {
public:
	Node<item> * hoq;

	Queue() {
		hoq = nullptr;
	}

	~Queue() {
		while (hoq != nullptr)
			remove();
	}

	void insert(item i) {
		Node<item> * n = new Node<item>(i, nullptr);

		// first item
		if (hoq == nullptr) {
			hoq = n;
		}

		// remaining items
		else {
			Node<item> * t = hoq;
			while (t->next != nullptr) {
				t = t->next;
			}
			t->next = n;
		}
	}

	item remove() {
		Node<item> * tmp = hoq->next;
		item v = hoq->val;
		delete hoq;
		hoq = tmp;
		return v;
	}

	item getmax() {
		item m = MIN_ITEM<item>;
		Node<item> * t = hoq;
		while (t->next != nullptr) {
			m = max(t->val, m);
			t = t->next;
		}
		return m;
	}
};

int main () {
	Queue<int> q;
	q.insert(1);
	q.insert(2);
	q.insert(3);
	q.insert(4);
	q.insert(5);

	std::cerr << "removed: " << q.remove() << std::endl;
	std::cerr << "removed: " << q.remove() << std::endl;

	std::cerr << "max: " << q.getmax() << std::endl;

}