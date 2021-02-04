//
//  main.cpp
//  learnOpenGL
//
//  Created by 鲁澳 on 2021/2/3.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "draw_triangle.h"

void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
    
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    loadTriangleShader();
    
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        // input
        // -----
        processInput(window);
        
        // custom render commands
        // ----------------------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        drawTriangle();
        
        // glfw: swap buffers and
        // poll IO events (keys
        // pressed/released, mouse moved etc.)
        // -----------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    removeTriangleShader();
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether
// relevant keys are pressed/released this
// frame and react accordingly
// ---------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

// glfw: whenever the window size changed
// (by OS or user resize) this callback
// function executes
// --------------------------------------
void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the
    // new window dimensions; note that width and
    // height will be significantly larger
    // than specified on retina displays.
    glViewport(0, 0, width, height);
}
