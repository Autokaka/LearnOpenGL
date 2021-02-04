//
//  draw_triangle.cpp
//  openGLPractice
//
//  Created by luao on 2021/2/4.
//
#include "draw_triangle.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


const char *vertexShaderSource = "#version 330 core \n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";
unsigned int triangleShaderProgram;
unsigned int TRIANGLE_VBO, TRIANGLE_VAO;

void loadTriangleShader() {
    // build and compile our shader program
    // ------------------------------------
    
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    // link shaders
    triangleShaderProgram = glCreateProgram();
    glAttachShader(triangleShaderProgram, vertexShader);
    glAttachShader(triangleShaderProgram, fragmentShader);
    glLinkProgram(triangleShaderProgram);
    glGetProgramiv(triangleShaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(triangleShaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    // set up vertex data (and buffer(s))
    // and configure vertex attributes
    // ----------------------------------
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left
         0.5f, -0.5f, 0.0f, // right
         0.0f,  0.5f, 0.0f  // top
    };
    glGenVertexArrays(1, &TRIANGLE_VAO);
    glGenBuffers(1, &TRIANGLE_VBO);
    // bind the Vertex Array Object first,
    // then bind and set vertex buffer(s),
    // and then configure vertex attributes(s).
    glBindVertexArray(TRIANGLE_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, TRIANGLE_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
}

void drawTriangle() {
    glUseProgram(triangleShaderProgram);
    glBindVertexArray(TRIANGLE_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void removeTriangleShader() {
    glDeleteVertexArrays(1, &TRIANGLE_VAO);
    glDeleteBuffers(1, &TRIANGLE_VBO);
    glDeleteProgram(triangleShaderProgram);
}
