//
//  window.cpp
//  Beatrice-core
//
//  Created by Charlotte Crossgrove on 9/13/17.
//  Copyright © 2017 Boult Studios. All rights reserved.
//

#include "window.hpp"
#include <iostream>


namespace Beatrice {
    namespace graphics {
        
        Window::Window(const char *title, int width, int height) {
            _title = title;
            _width = width;
            _height = height;
            if (!Init()) glfwTerminate();
        }
            
        Window::~Window() {
            glfwTerminate();
        }
        
        void Window::Update() {
            glfwPollEvents();
            int screenWidth;
            int screenHeight;
            glfwGetFramebufferSize(_window, &screenWidth, &screenHeight);    // needed for mac retina display
            
            glfwSwapBuffers(_window);
        }
        
        bool Window::Closed() const {
            return glfwWindowShouldClose(_window);
        }
        
        void Window::Clear() const {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        
        bool Window::Init() {
            if (!glfwInit()) {
                std::cout << "Error initializing!\n";
                return false;
            }
            else std::cout << "Successfully created!\n";
            
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);    // this line is needed for mac!
//            glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
            
            
            _window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
            
            
            
            if (!_window) {
                std::cout << "The glfw window failed to be created!\n";
                glfwTerminate();
                return false;
            }
            
            
            glfwMakeContextCurrent(_window);
            // glewExperimental = GL_TRUE;     // allows newer opengl features to be used
            
            glfwSetWindowSizeCallback(_window, WindowResize);
            
            return true;
        }
        
        void WindowResize(GLFWwindow *_window, int _width, int _height) {
            glViewport(0, 0, _width, _height);
        }
    }
}



































