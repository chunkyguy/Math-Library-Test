//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "CMLTests.hpp"
#include "cml/cml.h"
namespace {
cml::matrix44f_c* generateCMLMat4s(int count) {
  float* randomNumbers = generateRandomNumbers(count);

  cml::matrix44f_c* mats = new cml::matrix44f_c[count];
  for(int i = 0; i < count; i++) {
    mats[i].set_basis_element(0, 0, randomNumbers[i]);
    mats[i].set_basis_element(1, 1, randomNumbers[i]);
    mats[i].set_basis_element(2, 2, randomNumbers[i]);
    mats[i].set_basis_element(3, 3, 1.0f);
  }

  delete[] randomNumbers;

  return mats;
}

void test_cml_mat4_addition(cml::matrix44f_c* inputA, cml::matrix44f_c* inputB,
                            cml::matrix44f_c* output, int count) {
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] + inputB[i];
  }
}

void test_cml_mat4_multiplication(cml::matrix44f_c* inputA,
                                  cml::matrix44f_c* inputB,
                                  cml::matrix44f_c* output, int count) {
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] * inputB[i];
  }
}
}

TestResult test_cml(int count, int num_tests)
{
  TestResult tr;

  tr.name = "CML";

  cml::matrix44f_c* inputA = generateCMLMat4s(count);
  cml::matrix44f_c* inputB = generateCMLMat4s(count);
  cml::matrix44f_c* output = generateCMLMat4s(count);

  {
    kClockBegin
    for(int i = 0; i < num_tests; i++) {
      test_cml_mat4_addition(inputA, inputB, output, count);
    }
    kClockEnd(tr.additions);
  }


  {
    kClockBegin
    for(int i = 0; i < num_tests; i++) {
      test_cml_mat4_multiplication(inputA, inputB, output, count);
    }
    kClockEnd(tr.multiplications);
  }

  delete[] inputA;
  delete[] inputB;
  delete[] output;

  return tr;
}
