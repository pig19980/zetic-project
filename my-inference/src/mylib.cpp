// src/mylib.cpp
#include <torch/torch.h>
#include <iostream>
#include "mylib.h"

void hello() {
    std::cout << "Hello from the library!" << std::endl;
}

void print_tensor() {
  torch::Tensor tensor = torch::rand({2, 3});
  std::cout << tensor << std::endl;
}