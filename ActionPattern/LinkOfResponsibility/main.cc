#include "handler.h"

int main() {
  Handler *base = new ConcreteHandler(nullptr);
  base->HandleRequest(10);
  base->HandleRequest(11);
  delete base;
  return 0;
}
