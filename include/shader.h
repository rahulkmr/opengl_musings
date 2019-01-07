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
    std::string readShaderFile(const char *fileName) const
    {
        std::ifstream handle;
        std::stringstream buffer;
        handle.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            handle.open(fileName);
            buffer << handle.rdbuf();
            handle.close();
        } catch (std::ifstream::failure ex) {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        return buffer.str();
    }

    int createShader(GLenum shaderType, const char *shaderPath)
    {
        const char* shaderSource = readShaderFile(shaderPath).c_str();
        std::cout << shaderPath << "\n" << shaderSource << std::endl;
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
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
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