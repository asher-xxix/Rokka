# Rokka

Rokka is a hobby project to create a 3d game engine.

If you're on Linux like me, to install glfw, do this
```
cd dir/to/glfw-3.X.X
cmake -G "Unix Makefiles"
make
sudo make install
```


The main.cpp can be compiled with

`g++ main.cpp -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -o exe-name`

But to execute a window now, window.cpp needs to be compiled
first so the linker can find the definition of the functions.

`g++ graphics/window.cpp main.cpp -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -o exe-name`
