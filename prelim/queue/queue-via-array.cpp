#include <iostream>

template <typename T>
class Queue {
public:
	T * array;
	int beginIndex;
	int endIndex;
	int size;

	Queue() {
		size = 7;
		beginIndex = 0;
		endIndex = 0;
		array = new T[size];
	}

	void push(T item) {
		array[endIndex] = item;
		endIndex++;

		if (endIndex == size)
			endIndex = 0;
	}

	T pop() {
		T item = array[beginIndex];
		beginIndex++;
		if (beginIndex == size)
			beginIndex = 0;


		return item;
	}

	bool isEmpty() {
		return beginIndex == endIndex;
	}

	bool isFull() {
		return beginIndex + 1 == endIndex;
	}
};



int main() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	std::cout << "popped: " << q.pop() << std::endl;
	std::cout << "popped: " << q.pop() << std::endl;
	std::cout << "popped: " << q.pop() << std::endl;

	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	q.push(10);

	std::cout << "popped: " << q.pop() << std::endl;
	std::cout << "popped: " << q.pop() << std::endl;
	std::cout << "popped: " << q.pop() << std::endl;
	std::cout << "popped: " << q.pop() << std::endl;
	std::cout << "popped: " << q.pop() << std::endl;
	std::cout << "popped: " << q.pop() << std::endl;
	std::cout << "popped: " << q.pop() << std::endl;


}