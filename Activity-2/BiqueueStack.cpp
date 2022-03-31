#include <queue>

template<class T>
class BQStack {
private:
  std::queue<T> iQueue;
  std::queue<T> oQueue;
  unsigned int size;
public:
  BQStack() : size(0) {}
  void Push(T data) {
    iQueue.push(data);
    size++;
  }
  void Pop() {
    // if oQueue is empty
    if (oQueue.empty()) {
      // fill oQueue with iQueue
      while (!iQueue.empty()) {
        oQueue.push(iQueue.pop());
      }
    }
    // case: size > 0
    if (!oQueue.empty()) {
      size--;
      return oQueue.pop();
    }
    // case: size = 0
    return T();
  }
};