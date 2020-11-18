#include "Driver.h"
#include "EigenTests.hpp"
#include "GLMTests.hpp"
#include "CMLTests.hpp"
#include "GLKTests.hpp"
#include "KazmathTests.hpp"
#include "BulletTests.hpp"

//const int num_tests = 100000;
const int num_tests = 10000000;

#pragma mark - Test
std::vector<TestResult> testLibraries(int count) {
  std::vector<TestResult> tr;
  tr.push_back(test_eigen(count, num_tests));
  tr.push_back(test_glm(count, num_tests));
  tr.push_back(test_cml(count, num_tests));
  tr.push_back(test_glkmath(count, num_tests));
  tr.push_back(test_kazmath(count, num_tests));
  tr.push_back(test_bullet(count, num_tests));
  return tr;
}
