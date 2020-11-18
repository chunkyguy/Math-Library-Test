//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#ifndef Utils_hpp
#define Utils_hpp
#include <sys/time.h>
#include <iostream>
#include <sstream>
#include <string>

struct TestResult {
  std::string name;
  double additions;
  double multiplications;
};

/**
 * Print the time difference between two timevals in milliseconds.
 */
double difference(clock_t & start, clock_t & end);

/**
 * Create a float array with a size specified by count. Each value is
 * initialised as a random number generated using George Masaliga's 'Mother
 * of All Random Number Generator'.
 */
float* generateRandomNumbers(int count);

#endif /* Utils_hpp */
