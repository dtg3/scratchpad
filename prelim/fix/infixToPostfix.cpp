// 2011S Problem 3

#include <string>
#include <iostream>
#include <stack>


std::string infixToPostfix(const std::string & infix) {
	std::stack<std::string> s;
	std::string left, right, optr, c;

	for(int i = 0; i < infix.size(); ++i) {
		c = infix[i];

		// character or operand
		if (c != "(" && c != ")")
			s.push(c);
		
		// end expression
		else if (c == ")") {
			right = s.top(); s.pop();
			optr = s.top();  s.pop();
			left = s.top();  s.pop();

			// add in post-fix order
			s.push(left + right + optr);
		}
	}
	return s.top();
}


int main() {

	std::cout << infixToPostfix("(A*((B+C)-D))") << std::endl;
	std::cout << infixToPostfix("(A+(B*(C+D)))") << std::endl;

	return 0;
}
