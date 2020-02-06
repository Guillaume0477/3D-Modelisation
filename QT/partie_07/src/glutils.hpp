/*****************************************************************************\
 * TP CPE                                                                    *
 * ------
 *
 * Fonctions d'aides pour OpenGL (affichage d'erreur, chargement de shaders, etc)
 * Code repris de David Odin
 *
 *
\*****************************************************************************/

#pragma once
#ifndef GL_UTILS_HPP
#define GL_UTILS_HPP

#define GLEW_STATIC 1
#include <GL/glew.h>
#include <GL/gl.h>

#include <vector>
#include <string>


/** Macro to check for OpenGL error */
#define PRINT_OPENGL_ERROR() print_opengl_error(__FILE__, __LINE__)


/** Print the opengl error */
bool print_opengl_error(char const *file,int line);

/** Get the OpenGL version */
void get_gl_version(int *major, int *minor);

/** Look for a uniform variable within the shader */
GLint get_uni_loc(GLuint program, GLchar const* name);

/** Load a shader
  * 1st parameter: Vertex shader file
  * 2nd parameter: Fragment shader file
  * Note that we can load only one shader in letting the other empty ("") */
GLuint read_shader(std::string const& vertex_filename,
                   std::string const& fragment_filename);

/** Cast an integer into a GLubyte* */
GLubyte* buffer_offset(int offset);

#endif
