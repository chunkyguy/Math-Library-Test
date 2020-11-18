//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "KazmathTests.hpp"
#include "kazmath/kazmath.h"

namespace {
// since Kazmath does not provide any add function writing this in the style of kmMat4Multiply
kmMat4* kmMat4Add(kmMat4* pOut, const kmMat4* pM1, const kmMat4* pM2)
{
  kmScalar mat[16];
  const kmScalar *m1 = pM1->mat, *m2 = pM2->mat;
  for (int i = 0; i < 16; ++i) {
    mat[i] = m1[i] + m2[i];
  }
  memcpy(pOut->mat, mat, sizeof(kmScalar)*16);
  return pOut;
}
}

namespace {

typedef kmMat4 Matrix;

Matrix* generate(int count){
  float* randomNumbers = generateRandomNumbers(count);

  Matrix* mats = new Matrix[count];
  for(int i = 0; i < count; i++) {
    mats[i].mat[0] = randomNumbers[i];
    mats[i].mat[5] = randomNumbers[i];
    mats[i].mat[10] = randomNumbers[i];
    mats[i].mat[15] = 1.0f;
  }

  delete[] randomNumbers;

  return mats;

}

void test_addition(Matrix* inputA, Matrix* inputB,
                   Matrix* output, int count){
  for(int i = 0; i < count; i++) {
    kmMat4Add(&output[i], &inputA[i], &inputB[i]);
  }
}

void test_multiplication(Matrix* inputA, Matrix* inputB,
                         Matrix* output, int count){
  for(int i = 0; i < count; i++) {
    kmMat4Multiply(&output[i], &inputA[i], &inputB[i]);
  }
}
}

TestResult test_kazmath(int count, int num_tests)
{
  TestResult tr;
  tr.name = "Kazmath";

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
