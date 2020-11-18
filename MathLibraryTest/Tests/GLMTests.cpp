//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "GLMTests.hpp"
#include "glm/glm.hpp"

namespace  {
glm::mat4* generateGLMMat4s(int count) {
  float* randomNumbers = generateRandomNumbers(count);
  
  glm::mat4* mats = new glm::mat4[count];
  for(int i = 0; i < count; i++) {
    mats[i][0][0] = randomNumbers[i];
    mats[i][1][1] = randomNumbers[i];
    mats[i][2][2] = randomNumbers[i];
    mats[i][3][3] = 1.0f;
  }
  
  delete[] randomNumbers;
  
  return mats;
}

void test_glm_mat4_addition(glm::mat4* inputA, glm::mat4* inputB,
                            glm::mat4* output, int count) {
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] + inputB[i];
  }
}

void test_glm_mat4_multiplication(glm::mat4* inputA, glm::mat4* inputB,
                                  glm::mat4* output, int count){
  for(int i = 0; i < count; i++) {
    output[i] = inputA[i] * inputB[i];
  }
}
}

TestResult test_glm(int count, int num_tests)
{
  clock_t start, end;
  TestResult tr;

  tr.name = "GLM";

  std::cout << "Testing GLM library Matrix4f class." << std::endl;
  
  glm::mat4* inputA = generateGLMMat4s(count);
  glm::mat4* inputB = generateGLMMat4s(count);
  glm::mat4* output = generateGLMMat4s(count);
  
  std::cout << "Performing additions." << std::endl;
  // Time how long it takes to add [count] matrices NUM_TESTS times.
  start = clock();
  for(int i = 0; i < num_tests; i++) {
    test_glm_mat4_addition(inputA, inputB, output, count);
  }
  end = clock();
  tr.additions = difference(start, end);
  
  std::cout << "Performing multiplications." << std::endl;
  // Time how long it takes to multiply [count] matrices NUM_TESTS times.
  start = clock();
  for(int i = 0; i < num_tests; i++) {
    test_glm_mat4_multiplication(inputA, inputB, output, count);
  }
  end = clock();
  tr.multiplications = difference(start, end);
  
  delete[] inputA;
  delete[] inputB;
  delete[] output;
  
  return tr;
}
