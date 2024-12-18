// src/mylib.cpp
#include "mylib.h"
#include "model.h"
#include <iostream>
#include <torch/torch.h>

void hello() { std::cout << "Hello from the library!" << std::endl; }

void print_tensor() {
  torch::Tensor tensor = torch::rand({2, 3});
  std::cout << tensor << std::endl;
}

Model get_model(const char *path) { return Model(path); }