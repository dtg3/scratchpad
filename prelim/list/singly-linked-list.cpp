// 2014s Problem 1 & 2

#include <iostream>


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
class List {
public:
	Node<T> * beginning;
	Node<T> * ending;

	// default constructor
	List() {
		beginning = nullptr;
		ending = nullptr;
	}

	// destructor
	~List() {
		Node<T> * tmp = beginning;
		while (tmp != nullptr) {
			RemoveFromFront();
			tmp = beginning;
		}
	}

	// copy-constructor
	List(const List<T> & copy) {
		beginning = nullptr;
		ending = nullptr;

		for (Node<T> * tmp = copy.beginning; tmp != nullptr; tmp = tmp->next) {
			AddToBack(tmp->val);
		}
	}

	// assignment operator
	List<T> & operator=(List<T> rhs) {
		/*
		// Same as copy constructor - use when passing by reference
		for (Node<T> * tmp = rhs.beginning; tmp != nullptr; tmp = tmp->next)
			AddToBack(tmp->val);
		*/

		// when passing by value
		swap(rhs);
		return *this;
	}


	// swap
	void swap(List<T> other) {
		Node<T> * tmpB = other.beginning;
		Node<T> * tmpE = other.ending;

		other.beginning = beginning;
		other.ending = ending;

		beginning = tmpB;
		ending = tmpE;
	}


	// length
	int length() {
		int size = 0;
		Node<T> * tmp = beginning;
		while (tmp != nullptr) {
			++size;
			tmp = tmp->next;
		}
		return size;
	}

	// operator[]
	T & operator[](int index) {
		Node<T> * tmp = beginning;
		int i = 0;
		while (tmp != nullptr && i < index) {
			tmp = tmp->next;
			++i;
		}
		return tmp->val;
	}

	// add to back
	void AddToBack(T value) {
		Node<T> * n = new Node<T>(value, nullptr);
		if (ending == nullptr && beginning == nullptr) {
			beginning = n;
			ending = n;
		} else {
			ending->next = n;
			ending = n;
		}
	}

	// remove from front
	T RemoveFromFront() {
		Node<T> * next = beginning->next;
		T value = beginning->val;
		delete beginning;
		beginning = next;
		if (next == nullptr)
			ending = nullptr;
		return value;
	}
};


// Generic free function (Problem 2)
template <typename T>
struct compare {
	bool operator () (T left, T right) {
		return left == right;
	}
};

template <typename T>
List<T> removeDuplicates(List<T>  l, compare<T> comp) {
	List<T> removed;
	for (int i = 0; i < l.length(); ++i) {
		T val = l[i];

		bool found = false;
		for (int j = 0; j < removed.length(); ++j) {

			if (comp(removed[j], val))
				found = true;
		}

		if (!found)
			removed.AddToBack(val);
	}

	return removed;
}

int main() {

	List<int> l;
	l.AddToBack(1);
	l.AddToBack(2);
	l.AddToBack(3);
	l.AddToBack(4);
	l.AddToBack(5);

	std::cerr << "l: ";
	int size = l.length();
	for (int i = 0; i < size; ++i)
		std::cerr << " " << l[i];
	std::cerr << std::endl;

	List<int> copy(l);

	std::cerr << "copy: ";
	size = copy.length();
	for (int i = 0; i < size; ++i)
		std::cerr << copy[i] << " ";
	std::cerr << std::endl;

	List<int> assigned = l;

	std::cerr << "assigned: ";
	size = assigned.length();
	for (int i = 0; i < size; ++i)
		std::cerr << assigned[i] << " ";
	std::cerr << std::endl;

	for (int i = 0; i < 2; ++i) {
		int front = l.RemoveFromFront();
		std::cerr << "removed " << front << " ";
	}
	std::cerr << std::endl;
	

	std::cerr << "l: ";
	for (int i = 0; i < l.length(); ++i)
		std::cerr << l[i] << " ";
	std::cerr << std::endl;

	std::cerr << "copy: ";
	for (int i = 0; i < copy.length(); ++i)
		std::cerr << copy[i] << " ";
	std::cerr << std::endl;

	std::cerr << "assigned: ";
	for (int i = 0; i < assigned.length(); ++i)
		std::cerr << assigned[i] << " ";
	std::cerr << std::endl;


	// =======================================
	// Problem 2
	List<int> dups;
	dups.AddToBack(1);
	dups.AddToBack(2);
	dups.AddToBack(3);
	dups.AddToBack(4);
	dups.AddToBack(2);
	dups.AddToBack(3);
	dups.AddToBack(3);
	compare<int> f;
	List<int> removed = removeDuplicates(dups, f);

	std::cerr << "removed: ";
	for (int i = 0; i < removed.length(); ++i)
		std::cerr << removed[i] << " ";
	std::cerr << std::endl;

	return 0;
}

