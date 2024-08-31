#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include <memory>
#include <string>
#include <unordered_map>

#include "strategy.h"

class Context {
  std::unique_ptr<Strategy> strategy_up_;

public:
  Context(std::unique_ptr<Strategy> strategy_up)
      : strategy_up_(std::move(strategy_up)) {}
  void UpdateStrategy(std::unique_ptr<Strategy> strategy_up) {
    strategy_up_ = std::move(strategy_up);
  }

  void Execute() {
    if (strategy_up_) {
      strategy_up_->Execute();
    }
  }
};

#endif
