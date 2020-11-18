//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "BulletTests.hpp"
#include "vectormath/scalar/cpp/vectormath_aos.h"

namespace {

typedef Vectormath::Aos::Matrix4 Matrix;

Matrix *generate(int count) {
  float* randomNumbers = generateRandomNumbers(count);

  Matrix* mats = new Matrix[count];
  for(int i = 0; i < count; i++) {
    mats[i].setElem(0, 0, randomNumbers[i]);
    mats[i].setElem(1, 1, randomNumbers[i]);
    mats[i].setElem(2, 2, randomNumbers[i]);
    mats[i].setElem(3, 3, randomNumbers[i]);
  }

  delete[] randomNumbers;

  return mats;
}

void test_addition(Matrix* inputA,
                               Matrix* inputB,
                               Matrix* output,
                               int count){
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] + inputB[i];
  }
}

void test_multiplication(Matrix* inputA,
                                     Matrix* inputB,
                                     Matrix* output,
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

  Matrix* inputA = generate(count);
  Matrix* inputB = generate(count);
  Matrix* output = generate(count);

  {
    kClockBegin
    for(int i = 0; i < num_tests; i++) {
      test_addition(inputA, inputB, output, count);
    }
    kClockEnd(tr.additions);
  }

  {
    kClockBegin
    for(int i = 0; i < num_tests; i++) {
      test_multiplication(inputA, inputB, output, count);
    }
    kClockEnd(tr.multiplications);
  }

  delete[] inputA;
  delete[] inputB;
  delete[] output;

  return tr;
}
