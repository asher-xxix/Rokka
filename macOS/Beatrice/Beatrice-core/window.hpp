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
        
        void WindowResize(GLFWwindow *_window, int _width, int _height);
        
        class Window {
        private:
            int _width;
            int _height;
            const char *_title;
            bool _closed;
            GLFWwindow *_window;
            
            bool Init();
            
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
        };
    }
}





#endif /* window_hpp */
