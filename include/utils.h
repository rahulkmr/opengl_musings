#ifndef UTILS_H
#define UTILS_H

#include <GLFW/glfw3.h>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

void initAndSetHints();
GLFWwindow* createWindow(int width, int height);

int createShader(GLenum shaderType, const char* shaderSource);

int createProgram(std::initializer_list<int> shaders);

#endif