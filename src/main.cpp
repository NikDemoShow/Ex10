// Copyright NikDemoShow 2020
#include"postfix.h"

int main() {
  std::string infix{ "(1 + 2) / (3 + 4 * 6) - 5 * 4" };
  std::cout << infix2postfix(infix);
  return 0;
}
