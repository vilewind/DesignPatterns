#include <iostream>
#include <memory>

#include "context.h"
#include "strategy.h"

int main() {
  auto strategy = std::make_unique<ConcreteStrategy>();
  Context context(std::move(strategy));
  context.Execute();
  return 0;
}
