// 2013F Problem 3

#include <iostream>
#include <stack>

// part a - recursion
int g(int m, int n) {
	if (m == 0)
		return n + 1;
	else if (m > 0 && n == 0)
		return g(m-1, 1);
	else if (m > 0 && n > 0)
		return g(m-1, g(m, n-1));
}

// part b - stack
int g_s(int m, int n) {
	std::stack<int> args;
	args.push(m);
	args.push(n);

	while (args.size() >= 2) {
		n = args.top();
		args.pop();
		m = args.top();
		args.pop();

		if (m > 0 && n > 0) {
			args.push(m - 1);
			args.push(m);
			args.push(n - 1);
		}
		else if (m > 0 && n == 0) {
			args.push(m - 1);
			args.push(1);
		}
		else if (m == 0) {
			args.push(n + 1);
		}
	}
	return args.top();
}

int main () {

	std::cout << "g(1,1) = " << g(1,1) << std::endl;
	std::cout << "g_s(1, 1) = " << g_s(1, 1) << std::endl;

	std::cout << "g(2,1) = " << g(2,1) << std::endl;
	std::cout << "g_s(2, 1) = " << g_s(2, 1) << std::endl;

	std::cout << "g(3,1) = " << g(3,1) << std::endl;
	std::cout << "g_s(3, 1) = " << g_s(3, 1) << std::endl;

	std::cout << "g(3,2) = " << g(3,2) << std::endl;
	std::cout << "g_s(3, 2) = " << g_s(3, 2) << std::endl;

	std::cout << "g(3,3) = " << g(3,3) << std::endl;
	std::cout << "g_s(3, 3) = " << g_s(3, 3) << std::endl;

	std::cout << "g(3,4) = " << g(3,4) << std::endl;
	std::cout << "g_s(3, 4) = " << g_s(3, 4) << std::endl;


}