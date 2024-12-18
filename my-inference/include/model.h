#ifndef MYModel_H // 헤더 파일이 여러 번 포함되는 것을 방지
#define MYModel_H

#include <torch/script.h> // One-stop header

class Model {
public:
  Model(const char *path);

private:
  torch::jit::Module module;
};
#endif // MYModel_H