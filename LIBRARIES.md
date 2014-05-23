Configurable Math Library (CML)
===============================
This is a free library designed for games, graphics, and computational geometry
applications. Listed [features](http://cmldev.net/?page_id=8) include:

* Vector, matrix, and quarternion classes
* Templated headers so can be used for arbitrary types
* Arbitrary sized vectors and matrices (fixed or dynamically resizable)
* Conversions between polar, cylindrical, spherical, and Cartesian coordinates
* A large library of functions for the construction and manipulation of
  transforms in 2D and 3D

CML's [design notes](http://cmldev.net/?page_id=594) state that it is meant to
be cross-platform and portable and therefore doesn't contain any platform
specific optimisations, but it is possible to include them in the future if
there is specific interest.

There's only one header file to include, `cml/cml.h`.

CML contains quite a nice way of creating an abstraction layer between existing
math library objects and CML objects, allowing the use of other math library
data types in CML library functions. See [here](http://cmldev.net/?p=424).

CML only has a few [examples](http://cmldev.net/?p=402). Hasn't been updated in
a while.  Contains useful functions for working with OpenGL or DirectX though,
including replacements for things like gluLookAt().

CML is released under the [Boost Software License](http://cmldev.net/?p=430).
This means that you're allowed to use and profit from the library as long as
when distributing CML or any modifications you have made to CML, you keep the
Boost Software License text in each file.

Eigen
=====

This library has by far the most detailed and descriptive tutorial section with
many code samples. It is also worth noting that it seems to be the most
frequently updated and the most up-to-date (at the time of writing the most
recent release, 3.0.4, was 3.5 weeks ago).

Like GLM, it is very easy to pass the class objects directly to OpenGL,
although in Eigen this is performed by an [unsupported OpenGL
module](http://eigen.tuxfamily.org/dox-devel/unsupported/group__OpenGLSUpport__Module.html)
which provides a few functions such as glTranslate and glRotate.

    // You need to add path_to_eigen/unsupported to your include path.
    #include <Eigen/OpenGLSupport>
    // ...
    Vector3f x, y; Matrix3f rot;
    glVertex(y + x * rot);
    
    Quaternion q;
    glRotate(q);

Provides a large number of array, matrix, and vector types with [many
operators](http://eigen.tuxfamily.org/dox/QuickRefPage.html#QuickRef_Types). 



Eigen is licensed under the LGPL which is quite restrictive and usually would
exclude a library based on my requirements. However, Eigen has a large
[Licensing FAQ](http://eigen.tuxfamily.org/index.php?title=Licensing_FAQ) which
tries to answer any licensing questions people might have. Their main point is
that as Eigen is a header only library, it does not count as a "Combined Work"
under the LGPL it can be therefore used entirely under Section 3. This states
that to use Eigen you must:

* Give prominent notice with each copy of the object code that the Library is
  used in it and that the Library and its use are covered by this License. The
  Eigen FAQ states that 'the bottom of a README file or of a website would be
  prominent enough for us'.
* Accompany the object code with a copy of the GNU GPL and this license
  document.

This assumes that you're using Eigen unmodified. If you are planning to make
changes to Eigen and release it, then you must also make the modifications
available under the LGPL.

OpenGL Math Library (GLM)
=========================

GLM's main design to be very familiar to those who know GLSL as it uses classes
and functions that use the GLSL naming conventions. It also seems to provide
all of the functionality that I might need in the future.

Includes several code samples, more than CML. Many more located in the manual.

Includes features such as:

* Math for splines
* Math for colour spaces
* Random numbers
* Simplex noise generation
* Conversion of Euler angles

There's only one header file to include, `glm/glm.hpp`. `glm/ext.hpp` can be
included to add extended features (non GLSL features).

The design choice to follow GLSL conventions allows the library to be intuitive
and easy to use, especially given that data alignment is compatible with gl
functions. E.g:

    glm::vec4 v(0);
    glm::mat4 m(0);
    glVertex3fv(glm::value_ptr(v))
    glLoadMatrixfv(glm::value_ptr(m));

The manual pdf file link is broken but a slightly out of date version can be
found
[here](https://bitbucket.org/alfonse/gltut/src/6332c7f79903/glm-0.9.0.0/doc/glm-manual.pdf).
I've sent the maintainer an email and hopefully this will be fixed shortly. 

GLM is licensed under the [MIT
License](http://en.wikipedia.org/wiki/MIT_License) (Expat License) which is
very permissive and means GLM is a good candidate for any project requiring a
math library.

GLKMath
========

GLKMath is a C based library provided with the GLKit framework. It is designed
to work with iOS and OS X. Most of the functions are overloaded with NEON 
instruction set for ARM devices and SSE for x86 hardware.

Most of the code is inlined in header files, except for functions that couldn't be 
inlined for obvious reasons like matrix invert.

GLKMath supports vectors, matrices of dimension 2, 3, 4 and quaternions. GLKMath
also provides matrix operations from the OpenGL fixed function pipeline days.

As GLKMath is C based library so no operator overloading is possible. Most of the 
operations take input as function parameters and return a struct.

    GLKVector3 c = GLKVector3Add(a, b);

With modern hardwares returning structs shouldn't be a big deal. Still, for hardcore
operator overloading fans can checkout the [GLKitMathCPP repository](https://github.com/darknoon/GLKitMathCPP) which adds operator overloadings for major operations.

Kazmath
========

[Kazmath](https://github.com/Kazade/kazmath) is a C based library that was popularized by the Cocos2d engine. 
Like GLKMath it is a very small library. I don't have much experience with Kazmath, but I guess being C based it should just run on all platforms without any issues.

Kazmath is licensed under [Modified BSD License](https://github.com/Kazade/kazmath/blob/master/LICENSE.md).

Bullet Vectormath
=================

[Vectormath](http://bullet.svn.sourceforge.net/viewvc/bullet/trunk/Extras/vectormathlibrary/) is a 3D math library.

Vectormath's license can be found [here](http://bullet.svn.sourceforge.net/viewvc/bullet/trunk/Extras/vectormathlibrary/LICENSE?revision=1066&view=markup).
