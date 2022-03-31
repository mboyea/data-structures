#include <stack>

template<class T>
class BSQueue {
private:
  std::stack<T> iStack;
  std::stack<T> oStack;
  unsigned int size;
public:
  BSQueue() : size(0) {}
  void Enqueue(T data) {
    iStack.push(data);
    size++;
  }
  T Dequeue() {
    // if oStack is empty
    if (oStack.empty()) {
      //  fill oStack with iStack
      while(!iStack.empty()) {
        oStack.push(iStack.pop());
      }
    }
    // case: size > 0
    if (!oStack.empty()) {
      size--;
      return oStack.pop();
    }
    // case: size = 0
    return T();
  }
};