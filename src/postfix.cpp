// Copyright NikDemoShow 2020
#include "postfix.h"

std::string infix2postfix(std::string infix) {
  std::string rez;
  MyStack<char> oprtrs(infix.size());
  for (size_t i{ 0 }; i < infix.size(); ++i) {
    if (infix[i] != ' ') {
      if (isnumber(infix[i]) || infix[i] == '.') {
        rez += infix[i];
        if (i == infix.size() - 1 || i != infix.size() - 1 && (!isnumber(infix[i + 1]) && infix[i + 1] != '.')) {
            rez += ' ';
        }
      } else if (oprtrs.isEmpty() ||
          priority(infix[i]) > priority(oprtrs.get()) ||
          !priority(infix[i])) {
        if (infix[i] != ')') {
          oprtrs.push(infix[i]);
        }
      } else {
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

bool isnumber(char el) {
    return el >= 48 && el <= 57;
}
