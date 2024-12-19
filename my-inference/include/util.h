#include <torch/script.h> // One-stop header

typedef torch::Tensor Tensor;

Tensor img2tensor(const std::string &path);