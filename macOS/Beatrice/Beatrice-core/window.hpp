//
//  window.hpp
//  Beatrice-core
//
//  Created by Charlotte Crossgrove on 9/13/17.
//  Copyright © 2017 Boult Studios. All rights reserved.
//

#ifndef window_hpp
#define window_hpp

#include <GLFW/glfw3.h>

namespace Beatrice {
    namespace graphics {
        
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
        
        void WindowResize(GLFWwindow *_window, int _width, int _height);
        
        class Window {
        private:
            int _width;
            int _height;
            const char *_title;
            bool _closed;
            GLFWwindow *_window;
            
            static bool _keys[MAX_KEYS];
            static bool _buttons[MAX_BUTTONS];
            static double _mouseX;
            static double _mouseY;
            
            bool Init();
            
    
            friend void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        public:
            Window(const char *title, int width, int height);
            ~Window();
            void Update();
            bool Closed() const;
            void Clear() const;
            inline int GetWidth() const {
                return _width;
            }
            inline int GetHeight() const {
                return _height;
            }
            
            static bool IsKeyPressed(unsigned int keycode);
        };
    }
}





#endif /* window_hpp */
