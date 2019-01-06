#include <iostream>

#include <GLFW/glfw3.h>

#include "utils.h"


void initAndSetHints() {
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}


static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


GLFWwindow* createWindow(int width, int height) {
    GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGl", NULL, NULL);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    return window;
}


int createShader(GLenum shaderType, const char* shaderSource) {
    int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    return shader;
}

int createProgram(std::initializer_list<int> shaders) {
    int program = glCreateProgram();
    for (auto shader : shaders) {
        glAttachShader(program, shader);
    }
    glLinkProgram(program);
    return program;
}