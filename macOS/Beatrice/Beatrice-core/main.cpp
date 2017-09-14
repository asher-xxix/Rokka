//
//  main.cpp
//  Beatrice
//
//  Created by Charlotte Crossgrove on 9/13/17.
//  Copyright © 2017 Boult Studios. All rights reserved.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include "window.hpp"

const GLint WINDOW_W = 800;
const GLint WINDOW_H = 600;


int main(int argc, const char * argv[]) {
    using namespace Beatrice;
    using namespace graphics;
    
    
    Window window("Beatrice Window", WINDOW_W, WINDOW_H);
    glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
    
 
    while (!window.Closed()) {
        window.Clear();
        
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.0f, 0.5f);
        glVertex2f( 0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        
        
        window.Update();
    }
    
    return 0;
}
























































