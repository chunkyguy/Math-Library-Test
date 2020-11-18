//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#include "TestResult.hpp"
#include "mother.h"

float* generateRandomNumbers(int count) {
  unsigned long seed = time(NULL);
  float* numbers = new float[count];
  for(int i = 0; i < count; i++) {
    numbers[i] = static_cast<float>(Mother(&seed));
  }

  return numbers;
}
