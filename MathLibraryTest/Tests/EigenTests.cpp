//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "EigenTests.hpp"
#include "Eigen/Dense"

namespace {
Eigen::Matrix4f* generateEigenMat4s(int count) {
  float* randomNumbers = generateRandomNumbers(count);

  Eigen::Matrix4f* eigenmats = new Eigen::Matrix4f[count];
  for(int i = 0; i < count; i++) {
    eigenmats[i](0,0) = randomNumbers[i];
    eigenmats[i](1,1) = randomNumbers[i];
    eigenmats[i](2,2) = randomNumbers[i];
    eigenmats[i](3,3) = 1.0f;
  }

  delete[] randomNumbers;

  return eigenmats;
}

void test_eigen_mat4_addition(Eigen::Matrix4f* inputA,
                              Eigen::Matrix4f* inputB,
                              Eigen::Matrix4f* output,
                              int count) {
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] + inputB[i];
  }
}

void test_eigen_mat4_multiplication(Eigen::Matrix4f* inputA,
                                    Eigen::Matrix4f* inputB,
                                    Eigen::Matrix4f* output,
                                    int count) {
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] * inputB[i];
  }
}
}

TestResult test_eigen(int count, int num_tests)
{
  clock_t start, end;
  TestResult tr;

  tr.name = "Eigen";

  std::cout << "Testing Eigen library Matrix4f class." << std::endl;

  Eigen::Matrix4f* inputA = generateEigenMat4s(count);
  Eigen::Matrix4f* inputB = generateEigenMat4s(count);
  Eigen::Matrix4f* output = generateEigenMat4s(count);

  std::cout << "Performing additions." << std::endl;

  // Time how long it takes to add [count] matrices NUM_TESTS times.
  start = clock();
  for(int i = 0; i < num_tests; i++) {
    test_eigen_mat4_addition(inputA, inputB, output, count);
  }
  end = clock();
  tr.additions = difference(start, end);

  std::cout << "Performing multiplications." << std::endl;

  // Time how long it takes to multiply [count] matrices NUM_TESTS times.
  start = clock();
  for(int i = 0; i < num_tests; i++) {
    test_eigen_mat4_multiplication(inputA, inputB, output, count);
  }
  end = clock();
  tr.multiplications = difference(start, end);

  delete[] inputA;
  delete[] inputB;
  delete[] output;

  return tr;
}
