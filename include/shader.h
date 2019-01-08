#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>

class Shader
{
  public:
    unsigned int ID;

    Shader(const GLchar *vertexShaderPath, const GLchar *fragmentShaderPath)
    {
        unsigned int vertex = createShader(GL_VERTEX_SHADER, vertexShaderPath);
        unsigned int fragment = createShader(GL_FRAGMENT_SHADER, fragmentShaderPath);
        createProgram({vertex, fragment});
    }

    void use() {
        glUseProgram(ID);
    }

    void setBool(const std::string &name, bool value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void setInt(const std::string &name, int value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setFloat(const std::string &name, float value) const {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
    
    void setVec2(const std::string &name, const glm::vec2 &value) const {
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setVec2(const std::string &name, float x, float y) const {
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
    }

    void setVec3(const std::string &name, const glm::vec3 &value) const {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setVec3(const std::string &name, float x, float y, float z) const {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }

    void setVec4(const std::string &name, const glm::vec4 &value) const {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setVec4(const std::string &name, float x, float y, float z, float w) {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }

    void setMat2(const std::string &name, const glm::mat2 &mat) const {
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void setMat3(const std::string &name, const glm::mat3 &mat) const {
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void setMat4(const std::string &name, const glm::mat4 &mat) const {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

  private:
    const char* readShaderFile(const char *fileName) const {
        char* buffer = nullptr;
        long length;
        FILE* fp = fopen(fileName, "rb");
        if (fp) {
            fseek(fp, 0, SEEK_END);
            length = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            buffer = new char[length + 1];
            fread(buffer, 1, length, fp);
            buffer[length] = '\0';
            fclose(fp);
        } else {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ " << fileName << std::endl;
        }
        return buffer;
    }

    int createShader(GLenum shaderType, const char *shaderPath)
    {
        const char *shaderSource = readShaderFile(shaderPath);
        std::cout << shaderPath << "\n" << shaderSource << "\n\n" << std::endl;
        int shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &shaderSource, NULL);
        glCompileShader(shader);
        delete[] shaderSource;

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            GLint logLength;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
            char* infoLog = new char[logLength + 1];
            glGetShaderInfoLog(shader, logLength, nullptr, infoLog);
            std::cout << "ERROR::SHADER::COMPILATION_FAILED\n"
                << shaderPath << "\n" << infoLog;
            delete[] infoLog;
            glDeleteShader(shader);
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
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            GLint logLength;
            glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &logLength);
            char *infoLog = new char[logLength + 1];
            glGetProgramInfoLog(ID, logLength, nullptr, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                    << infoLog << "\n";
            delete[] infoLog;
            cleanupProgram(ID, shaders);
        }
        cleanupProgram(ID, shaders);
    }

    void cleanupProgram(int programId, std::initializer_list<unsigned int> shaders) {
        for (auto shader : shaders) {
            glDeleteShader(shader);
        }
    }
};

#endif