#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <iostream>
#include <type_traits>

struct Strategy {
  virtual ~Strategy() = default;
  virtual void Execute() = 0;
};

struct ConcreteStrategy : public Strategy {
  void Execute() override { std::cout << typeid(*this).name() << std::endl; }
};

#endif