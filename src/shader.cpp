#include "shader.h"

Shader::Shader(const GLchar *vertexShaderPath, const GLchar *fragmentShaderPath) {
    unsigned int vertex = createShader(GL_VERTEX_SHADER, vertexShaderPath);
    unsigned int fragment = createShader(GL_FRAGMENT_SHADER, fragmentShaderPath);
    createProgram({vertex, fragment});
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}