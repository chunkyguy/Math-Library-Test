//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "GLKTests.hpp"
#include <GLKit/GLKMath.h>
namespace {

typedef GLKMatrix4 Matrix;

Matrix* generate(int count){
  float* randomNumbers = generateRandomNumbers(count);

  Matrix* mats = new Matrix[count];
  for(int i = 0; i < count; i++) {
    mats[i].m00 = randomNumbers[i];
    mats[i].m11 = randomNumbers[i];
    mats[i].m22 = randomNumbers[i];
    mats[i].m33 = 1.0f;
  }

  delete[] randomNumbers;

  return mats;

}

void test_addition(Matrix* inputA, Matrix* inputB,
                                Matrix* output, int count){
  for(int i = 0; i < count; i++) {
    output[i] = GLKMatrix4Add(inputA[i], inputB[i]);
  }
}

void test_multiplication(Matrix* inputA, Matrix* inputB,
                                      Matrix* output, int count){
  for(int i = 0; i < count; i++) {
    output[i] = GLKMatrix4Multiply(inputA[i], inputB[i]);
  }
}
}

TestResult test_glkmath(int count, int num_tests)
{
  TestResult tr;
  tr.name = "GLKit";

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
    kClockBegin;
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
