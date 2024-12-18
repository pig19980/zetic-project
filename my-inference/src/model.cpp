#include "model.h"

Model::Model(const char *path) { this->module = torch::jit::load(path); }
