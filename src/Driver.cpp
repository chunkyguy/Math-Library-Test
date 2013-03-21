//#include <iostream>

#include <sys/time.h>

#include "Driver.h"
#include "mother.h"

//const int NUM_TESTS = 1000;
const int NUM_TESTS = 1000000;
//const int NUM_TESTS = 10000000;

#ifdef ANDROID
#include <android/log.h>
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))
#endif

TestResults testLibraries(int count) {
	TestResults tr = {-1};
	
    {
		
		std::cout << "Testing Eigen library Matrix4f class." << std::endl;
		
#ifdef ANDROID
		LOGI("Testing Eigen library Matrix4f class.");
#endif
		
		Eigen::Matrix4f* inputA = generateEigenMat4s(count);
		Eigen::Matrix4f* inputB = generateEigenMat4s(count);
		Eigen::Matrix4f* output = generateEigenMat4s(count);
		
		std::cout << "Performing additions." << std::endl;
		
#ifdef ANDROID
		LOGI("Performing additions.");
#endif
		
		// Time how long it takes to add [count] matrices NUM_TESTS times.
		struct timeval start, end;
		gettimeofday(&start, NULL);
		for(int i = 0; i < NUM_TESTS; i++) {
			test_eigen_mat4_addition(inputA, inputB, output, count);
		}
		gettimeofday(&end, NULL);
		tr.eigen.additions = difference(start, end);
		
#ifdef ANDROID
		LOGI("Performing multiplications.");
#endif
		
		std::cout << "Performing multiplications." << std::endl;
		
		// Time how long it takes to multiply [count] matrices NUM_TESTS times.
		gettimeofday(&start, NULL);
		for(int i = 0; i < NUM_TESTS; i++) {
			test_eigen_mat4_multiplication(inputA, inputB, output, count);
		}
		gettimeofday(&end, NULL);
		tr.eigen.multiplications = difference(start, end);
		
		delete[] inputA;
		delete[] inputB;
		delete[] output;
		
    }
	
    {
		
		std::cout << "Testing GLM library Matrix4f class." << std::endl;
		
#ifdef ANDROID
		LOGI("Testing GLM library Matrix4f class.");
#endif
		
		glm::mat4* inputA = generateGLMMat4s(count);
		glm::mat4* inputB = generateGLMMat4s(count);
		glm::mat4* output = generateGLMMat4s(count);
		
		std::cout << "Performing additions." << std::endl;
#ifdef ANDROID
		LOGI("Performing additions.");
#endif
		// Time how long it takes to add [count] matrices NUM_TESTS times.
		struct timeval start, end;
		gettimeofday(&start, NULL);
		for(int i = 0; i < NUM_TESTS; i++) {
			test_glm_mat4_addition(inputA, inputB, output, count);
		}
		gettimeofday(&end, NULL);
		tr.glm.additions = difference(start, end);
		
		std::cout << "Performing multiplications." << std::endl;
#ifdef ANDROID
		LOGI("Performing multiplications.");
#endif
		// Time how long it takes to multiply [count] matrices NUM_TESTS times.
		gettimeofday(&start, NULL);
		for(int i = 0; i < NUM_TESTS; i++) {
			test_glm_mat4_multiplication(inputA, inputB, output, count);
		}
		gettimeofday(&end, NULL);
		tr.glm.multiplications = difference(start, end);
		
		delete[] inputA;
		delete[] inputB;
		delete[] output;
		
    }
    {
		
		std::cout << "Testing CML library Matrix4f class." << std::endl;
#ifdef ANDROID
		LOGI("Testing CML library Matrix4f class.");
#endif
		cml::matrix44f_c* inputA = generateCMLMat4s(count);
		cml::matrix44f_c* inputB = generateCMLMat4s(count);
		cml::matrix44f_c* output = generateCMLMat4s(count);
		
		std::cout << "Performing additions." << std::endl;
#ifdef ANDROID
		LOGI("Performing additions.");
#endif
		// Time how long it takes to add [count] matrices NUM_TESTS times.
		struct timeval start, end;
		gettimeofday(&start, NULL);
		for(int i = 0; i < NUM_TESTS; i++) {
			test_cml_mat4_addition(inputA, inputB, output, count);
		}
		gettimeofday(&end, NULL);
		tr.cml.additions = difference(start, end);
		
		std::cout << "Performing multiplications." << std::endl;
#ifdef ANDROID
		LOGI("Performing multiplications.");
#endif
		// Time how long it takes to multiply [count] matrices NUM_TESTS times.
		gettimeofday(&start, NULL);
		for(int i = 0; i < NUM_TESTS; i++) {
			test_cml_mat4_multiplication(inputA, inputB, output, count);
		}
		gettimeofday(&end, NULL);
		tr.cml.multiplications = difference(start, end);
		
		delete[] inputA;
		delete[] inputB;
		delete[] output;
		
    }
	
    {
		
		std::cout << "Testing GLKMath library GLKMatrix4 class." << std::endl;
				
        GLKMatrix4* inputA = generateGLKMathMat4s(count);
        GLKMatrix4* inputB = generateGLKMathMat4s(count);
        GLKMatrix4* output = generateGLKMathMat4s(count);
		
		std::cout << "Performing additions." << std::endl;

		// Time how long it takes to add [count] matrices NUM_TESTS times.
		struct timeval start, end;
		gettimeofday(&start, NULL);
		for(int i = 0; i < NUM_TESTS; i++) {
            test_glkmath_mat4_addition(inputA, inputB, output, count);
		}
		gettimeofday(&end, NULL);
		tr.glkMath.additions = difference(start, end);
		
		std::cout << "Performing multiplications." << std::endl;
		// Time how long it takes to multiply [count] matrices NUM_TESTS times.
		gettimeofday(&start, NULL);
		for(int i = 0; i < NUM_TESTS; i++) {
            test_glkmath_mat4_multiplication(inputA, inputB, output, count);
		}
		gettimeofday(&end, NULL);
		tr.glkMath.multiplications = difference(start, end);
		
		delete[] inputA;
		delete[] inputB;
		delete[] output;
		
    }
	return tr;
}

float* generateRandomNumbers(int count) {
    unsigned long seed = time(NULL);
    float* numbers = new float[count];
    for(int i = 0; i < count; i++) {
        numbers[i] = static_cast<float>(Mother(&seed));
    }
	
    return numbers;
}

long difference(timeval& start, timeval& end) {
    long mtime, seconds, useconds;
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;
    std::stringstream ss;
    ss << "Took " << mtime << " milliseconds.";
    std::cout << ss.str() << std::endl;
#ifdef ANDROID
    LOGI(ss.str().c_str());
#endif
	
	return mtime;
}

Eigen::Matrix4f* generateEigenMat4s(int count) {
    float* randomNumbers = generateRandomNumbers(count);
	
    Eigen::Matrix4f* eigenmats = new Eigen::Matrix4f[count];
    for(int i = 0; i < count; i++) {
        eigenmats[i](0,0) = randomNumbers[i];
        eigenmats[i](1,1) = randomNumbers[i];
        eigenmats[i](2,2) = randomNumbers[i];
        eigenmats[i](3,3) = 1.0f;
    }
	
    delete[] randomNumbers;
	
    return eigenmats;
}

void test_eigen_mat4_addition(Eigen::Matrix4f* inputA,
                              Eigen::Matrix4f* inputB,
                              Eigen::Matrix4f* output,
                              int count) {
    for(int i = 0; i < count; i++) {
        output[i] = inputA[i] + inputB[i];
    }
}

void test_eigen_mat4_multiplication(Eigen::Matrix4f* inputA,
                                    Eigen::Matrix4f* inputB,
                                    Eigen::Matrix4f* output,
                                    int count) {
    for(int i = 0; i < count; i++) {
        output[i] = inputA[i] * inputB[i];
    }
}

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

