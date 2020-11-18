//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#ifndef Utils_hpp
#define Utils_hpp
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

#define kClockBegin auto start = std::chrono::high_resolution_clock::now();

#define kClockEnd(var) do { \
  auto end = std::chrono::high_resolution_clock::now(); \
  double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); \
  var = time/num_tests; \
} while(0)

typedef double TestTime;

struct TestResult {
  std::string name;
  TestTime additions;
  TestTime multiplications;
};

/**
 * Create a float array with a size specified by count. Each value is
 * initialised as a random number generated using George Masaliga's 'Mother
 * of All Random Number Generator'.
 */
float* generateRandomNumbers(int count);

#endif /* Utils_hpp */
