//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "GLKTests.hpp"
#include <GLKit/GLKMath.h>
namespace {
GLKMatrix4* generateGLKMathMat4s(int count){
    float* randomNumbers = generateRandomNumbers(count);

    GLKMatrix4* mats = new GLKMatrix4[count];
    for(int i = 0; i < count; i++) {
        mats[i].m00 = randomNumbers[i];
        mats[i].m11 = randomNumbers[i];
        mats[i].m22 = randomNumbers[i];
        mats[i].m33 = 1.0f;
    }

    delete[] randomNumbers;

    return mats;

}

void test_glkmath_mat4_addition(GLKMatrix4* inputA, GLKMatrix4* inputB,
                                GLKMatrix4* output, int count){
    for(int i = 0; i < count; i++) {
        output[i] = GLKMatrix4Add(inputA[i], inputB[i]);
    }
}

void test_glkmath_mat4_multiplication(GLKMatrix4* inputA, GLKMatrix4* inputB,
                                      GLKMatrix4* output, int count){
        for(int i = 0; i < count; i++) {
            output[i] = GLKMatrix4Multiply(inputA[i], inputB[i]);
        }
}
}

TestResult test_glkmath(int count, int num_tests)
{
  clock_t start, end;
  TestResult tr;

  tr.name = "GLKit";

  std::cout << "Testing GLKMath library GLKMatrix4 class." << std::endl;

      GLKMatrix4* inputA = generateGLKMathMat4s(count);
      GLKMatrix4* inputB = generateGLKMathMat4s(count);
      GLKMatrix4* output = generateGLKMathMat4s(count);

  std::cout << "Performing additions." << std::endl;

  // Time how long it takes to add [count] matrices NUM_TESTS times.
      start = clock();
  for(int i = 0; i < num_tests; i++) {
          test_glkmath_mat4_addition(inputA, inputB, output, count);
  }
      end = clock();
  tr.additions = difference(start, end);

  std::cout << "Performing multiplications." << std::endl;
  // Time how long it takes to multiply [count] matrices NUM_TESTS times.
      start = clock();
  for(int i = 0; i < num_tests; i++) {
          test_glkmath_mat4_multiplication(inputA, inputB, output, count);
  }
      end = clock();
  tr.multiplications = difference(start, end);

  delete[] inputA;
  delete[] inputB;
  delete[] output;


  return tr;
}
