#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
  public:
    unsigned int ID;

    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

  private:
    const char *readShaderFile(const char *fileName) const
    {
        std::ifstream handle(fileName);
        std::stringstream buffer;
        buffer << handle.rdbuf();
        handle.close();
        return buffer.str().c_str();
    }

    int createShader(GLenum shaderType, const char *shaderSource)
    {
        int shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &shaderSource, NULL);
        glCompileShader(shader);

        int success;
        char infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
        }

        return shader;
    }

    void createProgram(std::initializer_list<unsigned int> shaders)
    {
        ID = glCreateProgram();
        for (auto shader : shaders)
        {
            glAttachShader(ID, shader);
        }
        glLinkProgram(ID);
        int success;
        char infoLog[512];
        glGetProgramiv(ID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(ID, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                      << infoLog << std::endl;
        }
        for (auto shader : shaders)
        {
            glDeleteShader(shader);
        }
    }
};

#endif