//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "BulletTests.hpp"
#include "vectormath/scalar/cpp/vectormath_aos.h"

namespace {
Vectormath::Aos::Matrix4 *generateBulletMat4s(int count) {
  float* randomNumbers = generateRandomNumbers(count);

  Vectormath::Aos::Matrix4* mats = new Vectormath::Aos::Matrix4[count];
  for(int i = 0; i < count; i++) {
    mats[i].setElem(0, 0, randomNumbers[i]);
    mats[i].setElem(1, 1, randomNumbers[i]);
    mats[i].setElem(2, 2, randomNumbers[i]);
    mats[i].setElem(3, 3, randomNumbers[i]);
  }

  delete[] randomNumbers;

  return mats;
}

void test_bullet_mat4_addition(Vectormath::Aos::Matrix4* inputA,
                               Vectormath::Aos::Matrix4* inputB,
                               Vectormath::Aos::Matrix4* output,
                               int count){
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] + inputB[i];
  }
}

void test_bullet_mat4_multiplication(Vectormath::Aos::Matrix4* inputA,
                                     Vectormath::Aos::Matrix4* inputB,
                                     Vectormath::Aos::Matrix4* output,
                                     int count){
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] * inputB[i];
  }
}
}

TestResult test_bullet(int count, int num_tests)
{
  clock_t start, end;
  TestResult tr;

  tr.name = "Bullet";

  std::cout << "Testing bullet library scalar::Aos::Matrix4 class." << std::endl;

  Vectormath::Aos::Matrix4* inputA = generateBulletMat4s(count);
  Vectormath::Aos::Matrix4* inputB = generateBulletMat4s(count);
  Vectormath::Aos::Matrix4* output = generateBulletMat4s(count);

  std::cout << "Performing additions." << std::endl;

  // Time how long it takes to add [count] matrices NUM_TESTS times.
  start = clock();
  for(int i = 0; i < num_tests; i++) {
    test_bullet_mat4_addition(inputA, inputB, output, count);
  }
  end = clock();
  tr.additions = difference(start, end);

  std::cout << "Performing multiplications." << std::endl;
  // Time how long it takes to multiply [count] matrices NUM_TESTS times.
  start = clock();
  for(int i = 0; i < num_tests; i++) {
    test_bullet_mat4_multiplication(inputA, inputB, output, count);
  }
  end = clock();
  tr.multiplications = difference(start, end);

  delete[] inputA;
  delete[] inputB;
  delete[] output;

  return tr;
}
