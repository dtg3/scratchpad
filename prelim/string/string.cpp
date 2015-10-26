// String Dynamic
#include "string.hpp"

String::String(){
  Capacity = DEFAULT_STRING_CAPACITY - 1;
  s = new char[Capacity];
  s[0] = '\0';
}

String::String(char ch){
  Capacity = DEFAULT_STRING_CAPACITY - 2;
  s = new char[Capacity];
  s[0] = ch;

  if (ch != '\0')
    s[1] = '\0';
}

String::String(const char* c_str){
  int size = 0;
  while (c_str[size++] != '\0');
  
  Capacity = DEFAULT_STRING_CAPACITY - size;
  s = new char[Capacity];
  for (int i = 0; i < size; ++i){
    s[i] = c_str[i];
  }
}

String::String(int cap, const char* c_str){
  int size = 0;
  while (c_str[size++] != '\0');
  
  Capacity = cap - size;
  s = new char[Capacity];
  for (int i = 0; i < size; ++i){
    s[i] = c_str[i];
  }
}

String::String(int cap){
  Capacity = cap - 1;
  s = new char[Capacity];
  s[0] = '\0';
}

String::String(const String& copy){
  Capacity = copy.Capacity;
  s = new char[Capacity];
  // Want to capture the '\0' character so we go one past length
  for (int i = 0; i < copy.length() + 1; ++i){
    s[i] = copy.s[i];
  }
}

String::~String() {
  delete[] s;
}

String& String::operator= (String right_hand) {
  
}

int String::length() const{
  int length = 0;
  while (s[length] != '\0') {
    ++length;
  }
  return length;
}

bool String::operator==(const String& left_hand) const {
  if (length() != left_hand.length())
    return false;

  for (int i = 0; i < length(); ++i){
    if (s[i] != left_hand.s[i])
      return false;
  }

  return true;
}

bool operator== (const char right_hand[], const String& left_hand) {
  return ((String) right_hand) == left_hand;
}

bool operator== (char right_hand, const String& left_hand) {
  return ((String) right_hand) == left_hand;
}
