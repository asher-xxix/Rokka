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
        
        bool Window::_keys[MAX_KEYS];
        bool Window::_buttons[MAX_BUTTONS];
        double Window::_mouseX;
        double Window::_mouseY;
        
        void WindowResize(GLFWwindow *_window, int _width, int _height);
        void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        
        
        Window::Window(const char *title, int width, int height) {
            _title = title;
            _width = width;
            _height = height;
            if (!Init()) glfwTerminate();
            
            for (int i = 0; i < MAX_KEYS; ++i) {
                _keys[i] = false;
            }
            for (int i = 0; i < MAX_BUTTONS; ++i) {
                _buttons[i] = false;
            }
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
        
        bool Window::IsKeyPressed(unsigned int keycode) {
            if (keycode >= MAX_KEYS) {
                
                return false;
            }
            return _keys[keycode];
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
            glfwSetWindowUserPointer(_window, this);
            // glewExperimental = GL_TRUE;     // allows newer opengl features to be used
            
            glfwSetWindowSizeCallback(_window, WindowResize);
            glfwSetKeyCallback(_window, KeyCallback);
            return true;
        }
        
        
        
        void WindowResize(GLFWwindow *_window, int _width, int _height) {
            glViewport(0, 0, _width, _height);
        }
        
        void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
            Window *win = (Window *)glfwGetWindowUserPointer(window);
            win->_keys[key] = (action != GLFW_RELEASE);
        }
    }
}



































