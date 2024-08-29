#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

#include <iostream>
#include <string>

class Base {
public:
  virtual std::shared_ptr<Base> Clone() = 0;
  virtual ~Base() = default;
  virtual void Print() = 0;
};

class Derive : public Base {
  std::string name_;
  int *id_{nullptr};

public:
  Derive() = default;
  Derive(const Derive &rhs) {
    if (&rhs != this) {
      this->name_ = rhs.name_;
      this->id_ = new int;
      *(this->id_) = *(rhs.id_);
    }
  }
  Derive(const std::string &name, int *const id)
      : Base(), name_(name), id_(id) {}
  std::shared_ptr<Base> Clone() override {
    std::shared_ptr<Base> clone = std::make_shared<Derive>(*this);
    return clone;
  }

  void Print() override { std::cout << name_ << " " << *id_ << std::endl; }
};

#endif
