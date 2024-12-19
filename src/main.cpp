// main.cpp
#include "model.h"
#include "util.h"

#include <iostream>

int main(int argc, const char *argv[]) {
  if (argc != 3) {
    std::cerr << "usage: <Path of pt> <Path of image>" << std::endl;
    return -1;
  }

  auto model = Model(argv[1]);
  Tensor img = img2tensor(argv[2]);
  model.run(img);

  return 0;
}