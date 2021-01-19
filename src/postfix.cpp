// Copyright NikDemoShow 2020
#include "postfix.h"

std::string infix2postfix(std::string infix) {
  std::string rez;
  MyStack<char> oprtrs(infix.size());
  for (size_t i{ 0 }; i < infix.size(); ++i) {
    if (infix[i] != ' ') {
      if (infix[i] >= 48 && infix[i] <= 57) {
        rez += infix[i];
        rez +=  ' ';
      } else if (oprtrs.isEmpty() ||
          priority(infix[i]) > priority(oprtrs.get()) ||
          !priority(infix[i])) {
        if (infix[i] != ')') {
          oprtrs.push(infix[i]);
        }
      }
      else {
        while (priority(oprtrs.get()) >= priority(infix[i])) {
          rez += oprtrs.pop();
          rez += ' ';
        }
        if (oprtrs.get() == '(') {
          oprtrs.pop();
        }
        if (infix[i] != ')') {
          oprtrs.push(infix[i]);
        }
      }
    }
  }
  while (!oprtrs.isEmpty()) {
    rez += oprtrs.pop();
    rez += ' ';
  }
  return rez;
}

int16_t priority(char el) {
  switch (el) {
  case '(':
    return 0;
  case ')':
    return 1;
  case '+':
    return 2;
  case '-':
    return 2;
  case '*':
    return 3;
  case '/':
    return 3;
  }
}
