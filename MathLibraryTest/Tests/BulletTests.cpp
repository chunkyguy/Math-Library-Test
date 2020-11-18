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
  TestResult tr;
  tr.name = "Bullet";

  Vectormath::Aos::Matrix4* inputA = generateBulletMat4s(count);
  Vectormath::Aos::Matrix4* inputB = generateBulletMat4s(count);
  Vectormath::Aos::Matrix4* output = generateBulletMat4s(count);

  {
    kClockBegin
    for(int i = 0; i < num_tests; i++) {
      test_bullet_mat4_addition(inputA, inputB, output, count);
    }
    kClockEnd(tr.additions);
  }

  {
    kClockBegin
    for(int i = 0; i < num_tests; i++) {
      test_bullet_mat4_multiplication(inputA, inputB, output, count);
    }
    kClockEnd(tr.multiplications);
  }

  delete[] inputA;
  delete[] inputB;
  delete[] output;

  return tr;
}
