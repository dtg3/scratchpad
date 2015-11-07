// 2013F problem 2

#include <iostream>
#include <string>
#include <stack>


std::string infixToPostfix(std::string infix) {
	std::stack<std::string> s;
	std::string left, right, optr, num, c = "";

	for (int i = 0; i < infix.length(); ++i) {
		c = infix[i];

		// if found non-number
		if (c.find_first_of("*/-+()") != std::string::npos) {

			// push current number
			if (num != "")
				s.push(" " + num + " ");
			num = "";

			// push current characters (unless parenthesis)
			if (c != "(" && c != ")")
				s.push(c);

		}
		// found number
		else {
			num += c;
		}
		
		// end parens is time to pop
		if (c == ")") {
			right = s.top(); s.pop();
			optr = s.top(); s.pop();
			left = s.top(); s.pop();

			s.push(left + right + optr);
		}
	}

	return s.top();
}

int main () {
	char expr1[] = "(2*((3+7)-10))";
	std::string expr2 = "(16*((4+23)-7))";

	std::cerr << infixToPostfix(expr1) << std::endl;
	std::cerr << infixToPostfix(expr2) << std::endl;
}
