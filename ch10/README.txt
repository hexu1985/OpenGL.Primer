Shader directories for Chapter 10

There are three folders, each of which contains an application and the shader files.

VERTEX: the twisting teapot example

FRAG1: teapot with time-varying shading

FRAG2: teapot with texture

Notes:

Check the README in the parent directory if you plan to run these programs under Windows.
The difficulty is that Windows hasn't kept up with OpenGL even though the Windows drivers
have from Nvidia, ATI, and Intel. To get around this problem without hardcoding the entry
points for recent functions, including all the GLSL support, you can use the OpenGL
Extension Wrangler (glew) library which is available from sourceforge.com and other sites.

The code that reads a shader file can also be written using the standard C file functions
and not the UNIX sys library. See the examples from my textbook Interactive Computer Graphics at
www.cs.unm.edu/~angel/BOOK/INTERACTIVE_COMPUTER_GRAPHICS/FIFTH_EDITION/PROGRAMS/CHAPTER09

You might also want to add in some error checking as is included in the examples at the
above website.


