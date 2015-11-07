#include <list>
#include <iostream>

template <typename T>
class compare
{
    public:
        bool operator()(T lhs, T rhs) { return lhs == rhs; }
};

template <typename T>
std::list<T> removeDuplicates(std::list<T>& lst, compare<T>& comp){
  std::list<T> nodups;

  for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
    bool found = false;

    for (std::list<int>::iterator it2 = nodups.begin(); it2 != nodups.end(); it2++) {
      if (comp(*it, *it2)) {
        found = true;
        break;
      }
    }

    if (!(found)){
      nodups.push_back(*it);
    }
  }

  return nodups;
}


int main() {
  std::list<int> dupes;
  //{1, 2, 3, 4, 2, 3, 3}
  dupes.push_back(1);
  dupes.push_back(2);
  dupes.push_back(3);
  dupes.push_back(4);
  dupes.push_back(2);
  dupes.push_back(3);
  dupes.push_back(3);

  compare<int> comp;
  std::list<int> nodupes = removeDuplicates(dupes, comp);

  for (std::list<int>::iterator it = nodupes.begin(); it != nodupes.end(); it++) {
    std::cout << *it << ", ";
  }

  std::cout << "\n";
}
