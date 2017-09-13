//
//  main.cpp
//  Beatrice
//
//  Created by Charlotte Crossgrove on 9/13/17.
//  Copyright © 2017 Boult Studios. All rights reserved.
//

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>



const GLint WINDOW_W = 800;
const GLint WINDOW_H = 600;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // this line is needed for mac!
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    GLFWwindow *window = glfwCreateWindow(WINDOW_W, WINDOW_H, "Beatrice Window", nullptr, nullptr);
    
    
    int screenWidth;
    int screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);    // needed for mac retina display
    if (!window) {
        std::cout << " The glfw window failed to be created!\n";
        glfwTerminate();
        return -1;
    }
    
    
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;     // allows newer opengl features to be used
    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialize glew!\n";
        return -1;
    }
    
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    
    // game loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        
        
        
        
        
        
    }
    
    glfwTerminate();
    
    
    
    
    
    return 0;
}
























































