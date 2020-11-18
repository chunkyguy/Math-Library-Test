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
  TestResult tr;

  tr.name = "Eigen";

  Eigen::Matrix4f* inputA = generateEigenMat4s(count);
  Eigen::Matrix4f* inputB = generateEigenMat4s(count);
  Eigen::Matrix4f* output = generateEigenMat4s(count);

  {
    kClockBegin
    for(int i = 0; i < num_tests; i++) {
      test_eigen_mat4_addition(inputA, inputB, output, count);
    }
    kClockEnd(tr.additions);
  }

  {
    kClockBegin
    for(int i = 0; i < num_tests; i++) {
      test_eigen_mat4_multiplication(inputA, inputB, output, count);
    }
    kClockEnd(tr.multiplications);
  }

  delete[] inputA;
  delete[] inputB;
  delete[] output;

  return tr;
}
