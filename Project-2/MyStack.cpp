#include "MyStack.h"

template<class T>
MyStack<T>::MyStack() {}

template<class T>
void MyStack<T>::push(T data) {
  v.push_back(data);
}

template<class T>
T MyStack<T>::pop() {
  T data = v.back();
  v.pop_back();
  return data;
}

template<class T>
T MyStack<T>::peek() const {
  return v.back();
}

template<class T>
int MyStack<T>::size() const {
  return v.size();
}

template<class T>
bool MyStack<T>::isEmpty() const {
  return v.empty();
}