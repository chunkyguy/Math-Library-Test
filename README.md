C++ Math Library Test
=====================

Introduction
------------
This repository contains some simple tests between different C++ math
libraries that I wrote during the process of selecting a math library to use for
game development.

At the time of writing, the libraries tested are:

* [Eigen](http://eigen.tuxfamily.org)
* [GLM](http://glm.g-truc.net/)
* [CML](http://cmldev.net/)
* [GLKMath](http://developer.apple.com/library/mac/#documentation/GLkit/Reference/GLKit_Collection/_index.html)
* [kazmath](https://github.com/Kazade/kazmath)
  
These choices are largely influenced by reading their websites and posts at
the [Game Development StackExchange](http://gamedev.stackexchange.com/) site:

* [Best C Math Library for Game
  Engine?](http://gamedev.stackexchange.com/questions/9924/best-c-math-library-for-game-engine)
* [High Performance Math Library for Vector And Matrix
  Calculations](http://stackoverflow.com/questions/5935075/high-performance-math-library-for-vector-and-matrix-calculations)
* [Complete Math Library for use in OpenGL ES 2.0
  Game?](http://gamedev.stackexchange.com/questions/8234/complete-math-library-for-use-in-opengl-es-2-0-game)

This project uses CMake and has been tested on Mac OS X Lion and Android
(android-9 platform version, including armeabi, armeabi-v7a and armeabi-v7a
with NEON).

Requirements
------------
My requirements are:

* C++
* Matrix operations
* Vector operations
* Complex number support
* Quarternian operations
* Cross-platform, easy to compile on different platforms with different
  compilers.
* Fast. SIMD instruction support is preferred.
* Easy to use and understand.
* Permissive license. Accreditation is perfectly fine. Forcing distribution of
  source code isn't.

Libraries Overview
------------------
This section contains my notes to help understand the design choices and
advantages and disadvantages of each library. It is fairly long so has been
moved to `LIBRARIES.md`. This section also contains licensing information for
each library.

Things Tested
-------------
* Matrix operations - addition, multiplication

Things Yet To Test
------------------
This is for gaming applications. Features that I can think of that need testing
are:

* Matrix operations - including addition, subtraction, multiplication,
  inversion, transposition, translation, rotation, scale
* Vector operations - cross/dot product, normalisation, zeroing, magnitude,
  length2, scalar operands, normal calculation
* Euler angle + Quarternion operations - rotation, interpolation,
  conversion, inversion, multiplication
* Coordinate system conversion (Cartesian, spherical)
* Random numbers - generator speed, period, [statistical
  randomness](http://en.wikipedia.org/wiki/Diehard_tests)
* Possibly noise generation
* Ease of integration with gl functions like glTranslate()

Running the tests
-----------------
    git clone git@github.com:mfoo/Math-Library-Test.git MathTest
    cd MathTest
    mkdir build
    cd build
    cmake ..
    make

To run the tests on Android you will need the
[Android NDK](http://developer.android.com/sdk/ndk/index.html) and
[android-cmake](http://code.google.com/p/android-cmake/). For Ant you will need
to specify your Android SDK location in `android/local.properties`. I have
included prebuilt libraries for armeabi and armeabi-v7a so if you don't want to
compile them yourself you can skip straight to the ant commants.

    git clone git@github.com:mfoo/Math-Library-Test.git MathTest
    cd MathTest
    mkdir build
    cd build
    cmake-android ..
    make
    cd ../android
    ant debug
    ant installd

Results
-------
So far I've tested matrix addition and multiplication. `src/Main.cpp` contains
code that will generate two lists of 1 million 4x4 float matrices for each
library, populate them with random float values, and then add each one from the
first column to the second. It will then do the same for multiplication. It
will repeat this step 10 times and print out how long it took for each library.

Results for each library vary greatly with architecture and optimisation level.
I have tested standard GCC build on Mac OS X Lion as well as an SSE enabled
build, and armeabi, armeabi-v7a and armeabi-v7a with NEON instructions for
Android.

Note that all tests use the `-O2` GCC optimisation flag except the non-SSE
laptop build which uses `-O0`.

Results for addition and multiplication are shown below. Note that the
laptop I'm using is an i7 2.2ghz early 2011 MacBook Pro and the Android device is a
Stock HTC Desire (2.2) with a 1 GHz Qualcomm QSD8250. All times are in milliseconds.

                            laptop  laptop (SSE)  armeabi  armeabi-v7a  armeabi-v7a with neon
    Eigen additions         8065    30            9944     2181         2145
    Eigen multiplications   22404   86            59460    5143         5113
    GLM additions           2375    76            10256    1506         1407
    GLM multiplications     7337    400           59008    2189         3108
    CML additions           12336   96            9587     2885         2996
    CML multiplications     21603   551           58399    5306         5280

The first column for the laptop doesn't have any compile-time optimisations
and is included purely for interest. From the other results, Eigen seems to be
the fastest for these operations, but GLM is the fastest on the HTC Desire with
both ABIs.

Despite GLM being faster on the mobile devices, I am more inclined to use Eigen
due to its speed on the tested Intel CPU and its much better documentation and
more active community.

Results: iPhone 5s + iOS 7.1.1 + Release mode
----------------------------------------------

```
Eigen:
Additions: 3441.08 milliseconds.
Multiplications: 13001.98 milliseconds.

GLM:
Additions: 690.06 milliseconds.
Multiplications: 2067.56 milliseconds.

CML:
Additions: 3593.36 milliseconds.
Multiplications: 12799.92 milliseconds.

GLKMath:
Additions: 485.10 milliseconds.
Multiplications: 1308.01 milliseconds.

kazmath:
Additions: 938.89 milliseconds.
Multiplications: 1830.91 milliseconds.

```

Change Log
-----------

- Added GLKMath library.
- Added kazmath library.
- Modified the time calculation. Now based on the clock() function.
