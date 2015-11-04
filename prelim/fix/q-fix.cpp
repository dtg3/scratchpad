// This algorithm for converting infix to post fix or prefix is only applicable
// if the expression is fully parenthesized.

#include <stack>
#include <string>
#include <iostream>

std::string convert(const std::string& input, const std::string& mode) {
  std::stack<std::string> processStack;
  std::string left, right, oper, token;

  int index = 0;

  while (index < input.length()) {
    token = input[index];
    //std::cerr << "TOKEN: " << token << "\n";
    if (token != "(" && token != ")") {
      processStack.push(token);
    }
    else if (token == ")") {
      right = processStack.top();
      processStack.pop();
      oper = processStack.top();
      processStack.pop();
      left = processStack.top();
      processStack.pop();

      if (mode == "post") {
        processStack.push (left + right + oper);
      }

      if (mode == "pre") {
        processStack.push (oper + left + right);
      }
    }
    ++index;
  }

  return processStack.top();
}

int main(int argc, char* argv[]) {

  if (argc != 3) {
    std::cerr << "requires a mode (post / pre)\n";
    return 1;
  }

  std::string mode(argv[2]);

  std::cout << "infix: " << argv[1] << "\n";
  std::cout << mode + "fix: " << convert(argv[1], mode) << "\n";

  return 0;
}
