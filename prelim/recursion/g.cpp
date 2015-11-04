#include <iostream>
#include <stack>

int G(int m, int n) {

  if (m == 0)
    return n+1;
  if (m > 0 && n == 0)
    return G(m-1,1);

  return G(m-1, G(m, n-1));
}

int GS(int m, int n) {
  std::stack<int> stk;   

  bool didPop;
  do {
    didPop = false;

    if (m == 0) { 
      ++n;
      if (!(stk.empty())) {
        m = stk.top();
	stk.pop();
	didPop = true;
      }
    }

    if (m > 0 && n == 0){
      --m;
      n = 1;
    }
    
    if (m > 0 && n > 0){
      stk.push(m-1);
      --n;
    }

  } while(!(stk.empty()) || didPop);

  return n;

}

int main () {
  int m, n;
  std::cout << "M: ";
  std::cin >> m;
  std::cout << "N: ";
  std::cin >> n;

  std::cout << "RECURSIVE: " << G(m,n) << "\n";
  std::cout << "STACK: " << GS(m,n) << "\n";

}
