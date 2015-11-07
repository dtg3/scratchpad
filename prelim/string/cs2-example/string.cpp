// String Dynamic
#include "string.hpp"

String::String(){
  Capacity = DEFAULT_STRING_CAPACITY;
  s = new char[Capacity];
  s[0] = '\0';
}

String::String(char ch){
  Capacity = DEFAULT_STRING_CAPACITY;
  s = new char[Capacity];
  s[0] = ch;

  if (ch != '\0')
    s[1] = '\0';
}

String::String(const char* c_str){
  int size = 0;
  while (c_str[size++] != '\0');

  if (size >= Capacity)
  Capacity = DEFAULT_STRING_CAPACITY;
  s = new char[Capacity];
  for (int i = 0; i < size; ++i){
    s[i] = c_str[i];
  }
}

String::String(int cap, const char* c_str){
  int size = 0;
  while (c_str[size++] != '\0');

  Capacity = cap;
  s = new char[Capacity];
  for (int i = 0; i < size; ++i){
    s[i] = c_str[i];
  }
}

String::String(int cap){
  Capacity = cap;
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
  delete[] s;
  Capacity = right_hand.Capacity;
  s = new char[Capacity];

  for (int i = 0; i < right_hand.length() + 1; ++i){
    s[i] = right_hand.s[i];
  }

  return *this;
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
