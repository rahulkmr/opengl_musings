#ifndef UTILS_H
#define UTILS_H

#include <GLFW/glfw3.h>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

void initAndSetHints();
GLFWwindow* createWindow(int width, int height);

unsigned int createShader(GLenum shaderType, const char* shaderSource);

unsigned int createProgram(std::initializer_list<unsigned int> shaders);

void createTexture(unsigned int* texture, const char* textureFileName,
    bool flipVerticallyOnLoad = true, bool hasAlpha = false);

#endif