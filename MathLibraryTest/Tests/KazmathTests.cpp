//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "KazmathTests.hpp"
#include "kazmath/kazmath.h"

namespace {
  kmMat4* generateKazmathMat4s(int count){
      float* randomNumbers = generateRandomNumbers(count);

     kmMat4* mats = new kmMat4[count];
      for(int i = 0; i < count; i++) {
          mats[i].mat[0] = randomNumbers[i];
          mats[i].mat[5] = randomNumbers[i];
          mats[i].mat[10] = randomNumbers[i];
          mats[i].mat[15] = 1.0f;
      }

      delete[] randomNumbers;

      return mats;

  }

  void test_kazmath_mat4_addition(kmMat4* inputA, kmMat4* inputB,
                                  kmMat4* output, int count){
      for(int i = 0; i < count; i++) {
          for (int j = 0; j < 16; ++j) {
              output[i].mat[j] = inputA[i].mat[j] + inputB[i].mat[j];
          }
      }
  }

  void test_kazmath_mat4_multiplication(kmMat4* inputA, kmMat4* inputB,
                                        kmMat4* output, int count){
      for(int i = 0; i < count; i++) {
          kmMat4Multiply(&output[i], &inputA[i], &inputB[i]);
      }
  }
}

TestResult test_kazmath(int count, int num_tests)
{
  clock_t start, end;
  TestResult tr;

  tr.name = "Kazmath";

  std::cout << "Testing kazmath library kmMat4 class." << std::endl;

      kmMat4* inputA = generateKazmathMat4s(count);
      kmMat4* inputB = generateKazmathMat4s(count);
      kmMat4* output = generateKazmathMat4s(count);

  std::cout << "Performing additions." << std::endl;

  // Time how long it takes to add [count] matrices NUM_TESTS times.
      start = clock();
  for(int i = 0; i < num_tests; i++) {
          test_kazmath_mat4_addition(inputA, inputB, output, count);
  }
      end = clock();
  tr.additions = difference(start, end);

  std::cout << "Performing multiplications." << std::endl;
  // Time how long it takes to multiply [count] matrices NUM_TESTS times.
      start = clock();
  for(int i = 0; i < num_tests; i++) {
          test_kazmath_mat4_multiplication(inputA, inputB, output, count);
  }
      end = clock();
  tr.multiplications = difference(start, end);

  delete[] inputA;
  delete[] inputB;
  delete[] output;

  return tr;
}
