#include "MyQueue.h"

template<class T>
MyQueue<T>::MyQueue() {}

template<class T>
void MyQueue<T>::push(T data) {
  q.push_back(data);
}

template<class T>
T MyQueue<T>::pop() {
  T data = q.front();
  q.pop_front();
  return data;
}

template<class T>
T MyQueue<T>::peek() const {
  return q.front();
}

template<class T>
int MyQueue<T>::size() const {
  return q.size;
}

template<class T>
bool MyQueue<T>::isEmpty() const {
  return q.empty();
}