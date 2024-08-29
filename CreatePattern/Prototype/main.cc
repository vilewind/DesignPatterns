#include "client.h"
#include "prototype.h"

struct Demo {
  int num{0};
};

int main() {
  std::string name("Prototype");
  int *id = new int(1);
  std::shared_ptr<Base> base = std::make_shared<Derive>(name, id);

  std::cout << "No prototype" << std::endl;
  if (Client<Base>::Create() == nullptr) {
    std::cerr << "Client Create failed" << std::endl;
  }

  Client<Base>::SetPrototype(base);
  base->Print();

  auto clone_obj = Client<Base>::Create();
  clone_obj->Print();

  std::cout << "No clone" << std::endl;
  std::shared_ptr<Demo> demo = std::make_shared<Demo>();
  Client<Demo>::SetPrototype(demo);
  if (Client<Demo>::Create() == nullptr) {
    std::cout << "Client Create failed" << std::endl;
  }

  delete id;
}
