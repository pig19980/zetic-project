#include "util.h"
#include <iostream>
#include <opencv2/opencv.hpp> // For image processing (OpenCV)
#include <torch/script.h>     // For TorchScript module

Tensor img2tensor(const std::string &path) {
  // Load the image using OpenCV
  cv::Mat img = cv::imread(path, cv::IMREAD_COLOR); // Read image in color

  if (img.empty()) {
    std::cerr << "Could not open or find the image at " << path << std::endl;
    exit(-1);
  }

  // Resize image to 224x224 using OpenCV
  cv::Mat resized_img;
  cv::resize(img, resized_img, cv::Size(224, 224));

  // Convert the image from BGR to RGB (OpenCV loads images in BGR by default)
  cv::cvtColor(resized_img, resized_img, cv::COLOR_BGR2RGB);

  // Convert the OpenCV Mat to a float tensor
  Tensor tensor_img =
      torch::from_blob(resized_img.data, {224, 224, 3}, torch::kByte);

  // Convert to float and normalize the image
  tensor_img = tensor_img.to(torch::kFloat32).div(255.0);

  // Normalize: mean = [0.485, 0.456, 0.406], std = [0.229, 0.224, 0.225]
  tensor_img = tensor_img.permute({2, 0, 1}); // Change to CxHxW format
  tensor_img[0] = tensor_img[0].sub(0.485).div(0.229);
  tensor_img[1] = tensor_img[1].sub(0.456).div(0.224);
  tensor_img[2] = tensor_img[2].sub(0.406).div(0.225);

  // Add batch dimension: [1, 3, 224, 224]
  tensor_img = tensor_img.unsqueeze(0);
  tensor_img = tensor_img.contiguous();

  std::cout << "Tensor size: " << tensor_img.sizes() << std::endl;

  return tensor_img;
}
