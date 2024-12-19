#ifndef MYModel_H // 헤더 파일이 여러 번 포함되는 것을 방지
#define MYModel_H

#include "util.h"
#include <torch/script.h> // One-stop header

class Model {
public:
  Model(const std::string &path);
  void run(const torch::Tensor &input);

private:
  torch::jit::script::Module loaded_model;
};
#endif // MYModel_H