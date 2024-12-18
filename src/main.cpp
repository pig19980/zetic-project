// main.cpp
#include "model.h"
#include "mylib.h"

#include <iostream>
#include <memory>

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    std::cerr << "path to the model not mentioned!!" << std::endl;
    return -1;
  }

  auto module = get_model(argv[1]);

  //   std::vector<torch::jit::IValue> inputs;
  //   inputs.push_back(torch::ones({1, 1, 29, 22, 22}));

  //   for (int i = 0; i < COUNT; ++i) {
  //     auto output = at::argmax(module->forward(inputs).toTensor());
  //   }

  return 0;
}