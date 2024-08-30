#ifndef __HANDLER_H__
#define __HANDLER_H__

#include <iostream>
#include <memory>

class Handler {
protected:
  std::shared_ptr<Handler> next_handler_{nullptr};

public:
  Handler() = default;
  Handler(const std::shared_ptr<Handler> &next_handler)
      : next_handler_(next_handler) {}

  virtual ~Handler() = default;

  void SetNextHandler(const std::shared_ptr<Handler> &next_handler) {
    next_handler_ = next_handler;
  }

  virtual void HandleRequest(int request) = 0;
};

class ConcreteHandler : public Handler {
public:
  ConcreteHandler() = default;
  ConcreteHandler(std::shared_ptr<Handler> next_handler)
      : Handler(next_handler) {}

  void HandleRequest(int request) override {
    if (request >= 0 && request <= 10) {
      std::cout << "Current handler valid in 0 ~ 10" << std::endl;
    } else if (next_handler_) {
      next_handler_->HandleRequest(request);
    } else {
      std::cout << "Invalid request " << request << std::endl;
    }
  }
};

#endif
