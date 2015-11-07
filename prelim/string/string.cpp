// 2012S problem 1
#include <iostream>

class String {
public:
	String() : cap(128) {
		str = new char[cap];
		str[0] = '\0';
	}

	String(int c) : cap(c) {
		str = new char[cap];
		str[0] = '\0';
	}

	String(const char a[], int c) : cap(c) {
		str = new char[cap];

		int index = 0;
		while (a[index] != '\0') {
			str[index] = a[index];
			++index;
		}
		str[index] = '\0';
	}

	String(String & copy) {
		cap = copy.cap;
		str = new char[cap];

		for (int i = 0; i < copy.length(); ++i) {
			str[i] = copy.str[i];
		}
		str[copy.length()] = '\0';
	}

	~String() {
		delete [] str;
	}

	void reallocate(int newCapacity) {
		cap = newCapacity;
		char *tmpStr = new char[newCapacity];
		for (int i = 0; i < newCapacity && i < cap; ++i)
			tmpStr[i] = str[i];

		if (length() < newCapacity)
			tmpStr[length()] = '\0';
		else
			tmpStr[newCapacity] = '\0';

		delete [] str;
		str = tmpStr;
	}

	String & operator=(String rhs) {
		swap(rhs);
		return *this;
	}

	void swap(String &rhs) {
		int tmpC = rhs.cap;
		rhs.cap = cap;
		cap = tmpC;

		char * tmpStr = rhs.str;
		rhs.str = str;
		str = tmpStr;
	}

	int length() {
		int l = 0;
		while (str[l] != '\0')
			++l;
		return l;
	}

	int capacity() {
		return cap;
	}

	// for testing only
	void print() {
		int l = 0;
		while (str[l] != '\0')
			std::cerr << str[l++];
		std::cerr << std::endl;
	}

private:
	int cap;
	char * str;
};


// test
int main() {
	char c[] = "hello";
	String s(c, 10);
	std::cerr << "length: " << s.length() << std::endl;
	std::cerr << "capacity: " << s.capacity() << std::endl;
	s.print();

	String r(s);
	std::cerr << "length: " << r.length() << std::endl;
	std::cerr << "capacity: " << r.capacity() << std::endl;
	r.print();

	String t = s;
	std::cerr << "length: " << t.length() << std::endl;
	std::cerr << "capacity: " << t.capacity() << std::endl;
	t.print();

	s.reallocate(20);
	std::cerr << "length: " << s.length() << std::endl;
	std::cerr << "capacity: " << s.capacity() << std::endl;
	s.print();


}