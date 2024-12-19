#include "model.h"
#include <iostream>

Model::Model(const std::string &path) {
  // Load the TorchScript model
  loaded_model = torch::jit::load(path);
}

void Model::run(const Tensor &input) {
  // Ensure no gradients are calculated
  torch::NoGradGuard no_grad;

  // Run the model and return the result
  auto ret = loaded_model.forward({input});
  std::cout << ret << std::endl;
}