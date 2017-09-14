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
            void Update() const;
            bool Closed() const;
            void Clear() const;
        };
    }
}





#endif /* window_hpp */
