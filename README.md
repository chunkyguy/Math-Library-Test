C++ Math Library Test (Apple Devices)
=====================

Introduction
------------
This repository contains some simple tests between different C++ math libraries that I wrote during the process of selecting a math library to use for game development.

At the time of writing, the libraries tested are:

* [Eigen](http://eigen.tuxfamily.org)
* [GLM](http://glm.g-truc.net/)
* [CML](http://cmldev.net/)
* [GLKMath](http://developer.apple.com/library/mac/#documentation/GLkit/Reference/GLKit_Collection/_index.html)
* [kazmath](https://github.com/Kazade/kazmath)
* [bullet-vectormath](http://bullet.svn.sourceforge.net/viewvc/bullet/trunk/Extras/vectormathlibrary/)
  
Results:
----------------------------------------------

So far I've tested matrix addition and multiplication. `src/Main.cpp` contains
code that will generate two lists of 1 million 4x4 float matrices for each
library, populate them with random float values, and then add each one from the
first column to the second. It will then do the same for multiplication. It
will repeat this step 10 times and print out how long it took for each library.

Results for each library vary greatly with architecture and optimisation level.

**Mac - 2.3 GHz 8-Core Intel Core i9 - 32 GB RAM**

| Library | Additions (ms) | Multiplications (ms) |
|---------|----------------|----------------------|
| Eigen   | 0056378.55     | 0217075.68           |
| GLM     | 0017431.80     | 0235920.92           |
| CML     | 0156321.33     | 0254889.30           |
| GLKMath | 0004813.98     | 0073646.90           |
| kazmath | 0008278.54     | 0133849.60           |
| bullet  | 0019107.55     | 0339817.13           |

Requirements
------------

These choices are largely influenced by reading their websites and posts at
the [Game Development StackExchange](http://gamedev.stackexchange.com/) site:

* [Best C Math Library for Game
  Engine?](http://gamedev.stackexchange.com/questions/9924/best-c-math-library-for-game-engine)
* [High Performance Math Library for Vector And Matrix
  Calculations](http://stackoverflow.com/questions/5935075/high-performance-math-library-for-vector-and-matrix-calculations)
* [Complete Math Library for use in OpenGL ES 2.0
  Game?](http://gamedev.stackexchange.com/questions/8234/complete-math-library-for-use-in-opengl-es-2-0-game)

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

Change Log
-----------

- Remove Android tests
- Add GLKMath library.
- Add kazmath library.
- Modify the time calculation. Now based on the clock() function.
- Add bullet vectormath library.
