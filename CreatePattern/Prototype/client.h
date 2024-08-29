#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <memory>
#include <type_traits>

#define DEFINE_TYPE_TRAIT(name, func)                                          \
  template <typename T> struct name {                                          \
    template <typename Class>                                                  \
    static constexpr bool Test(decltype(&Class::func) *) {                     \
      return true;                                                             \
    }                                                                          \
    template <typename> static constexpr bool Test(...) { return false; }      \
    static constexpr bool value = Test<T>(nullptr);                            \
  };                                                                           \
  template <typename T> constexpr bool name<T>::value;

DEFINE_TYPE_TRAIT(HasClone, Clone)

/// @question client是否可以理解为一个工厂
template <typename T> class Client {
public:
  static void SetPrototype(std::shared_ptr<T> sp) { prototype_ = sp; }

  /// @note enable_if_t = enable_if<bool, T>::type
  /// @note enable_if在模版函数中生效，因此需要加上 template <typename U = T>
  /// @brief 没有定义clone函数的创建函数
  template <typename U = T>
  static std::enable_if_t<!HasClone<U>::value, std::shared_ptr<T>> Create() {
    if (!prototype_)
      return nullptr;
    return std::make_shared<T>(*prototype_);
  }

  /// @brief 定义了clone函数的创建函数
  template <typename U = T>
  static std::enable_if_t<HasClone<U>::value, std::shared_ptr<T>> Create(...) {
    if (prototype_) {
      return prototype_->Clone();
    }
    return nullptr;
  }

private:
  static std::shared_ptr<T> prototype_;
};

template <typename T> std::shared_ptr<T> Client<T>::prototype_ = nullptr;

#endif
