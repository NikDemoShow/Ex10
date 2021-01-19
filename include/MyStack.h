// Copyright NikDemoShow 2020
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 private:
  unsigned int size;
  unsigned int top;
  T* arr;

 public:
  explicit MyStack(const unsigned int n_size): size(n_size), top(0) {
    arr = new T[size];
  }
  MyStack(const MyStack& n_MyStack) : size(n_MyStack.size), top(n_MyStack.top) {
    arr = new T[size];
    for (unsigned int i{ 0 }; i < size; ++i) {
      arr[i] = n_MyStack.arr[i];
    }
  }
  ~MyStack() {
    delete[] arr;
  }
  T get() const {
    if (!(*this).isEmpty()) {
      return arr[top - 1];
    }
    return 0;
  }
  T pop() {
    if (!(*this).isEmpty()) {
      top--;
      return arr[top];
    }
    return 0;
  }
  void push(T el) {
    if (!(*this).isFull()) {
      top++;
      arr[top - 1] = el;
    }
  }
  bool isFull() const {
    return top == size;
  }
  bool isEmpty() const {
    return !top;
  }
};

#endif  // INCLUDE_MYSTACK_H_
