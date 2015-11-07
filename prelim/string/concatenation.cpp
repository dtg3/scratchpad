// 2012s problem 3

#include <iostream>

class String {
public:
	String() {s[0] = 0; };

	String(char a[]) {
		int index = 0;
		while (a[index] != 0) {
			s[index] = a[index];
			++index;
		}
		s[index] = 0;
	}

	String operator+(const String & rhs) const {
		String result;

		int rhslength = rhs.length();
		int lhslength = length();

		for (int i = 0; i < lhslength; ++i) {
			result.s[i] = s[i];
		}
		for (int i = 0; i < rhslength; ++i) {
			if (i >= 256) {
				throw "Too big";
			}

			result.s[lhslength + i] = rhs.s[i];
		}
		result.s[rhslength + lhslength] = 0;

		return result;
	}

	int length() const {
		int l = 0;
		while (s[l] != 0)
			++l;
		return l;
	}

	void print() {
		int l = length();
		for (int i = 0; i < l; ++i) {
			std::cerr << s[i];
		}
	}

private:
	char s[256];
};



int main() {
	String s("hello ");
	String t("world");
	String v = s + t;
	v.print();
	return 0;
}