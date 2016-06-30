# Rokka     六花

### Rokka is a hobby project to create a 3d game engine.

If anyone wants to work on this with me, please make a pull request.

If you're on Linux, to install glfw, do this
```
cd dir/to/glfw-3.X.X
cmake -G "Unix Makefiles"
make
sudo make install
```


The main.cpp can be compiled with

```
g++ main.cpp -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -o exe-name
```

But to execute a window now, window.cpp needs to be compiled
first so the linker can find the definition of the functions.

```
g++ graphics/window.cpp main.cpp -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -o exe-name
```




To install glew, just do `sudo make install` in the libs/glew-1.13.0 directory. It might take a little while don't worry. **If on OS X**, you could use Homebrew with `brew install glew` As far as glfw is concerned, do `brew install homebrew/homebrew-versions/glfw3` make sure you have cmake installed  .

You should also compile like this now (in the src directory like always, or just use the Makefile)
```
g++ graphics/shader.cpp graphics/window.cpp main.cpp -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -o ../bin/exe-name -lGLEW
```
Notice the `lGLEW` at the very end. And we now place our executables in the bin/directory.


I have yet to make a reliable way to build this on OS X.

A side note, Vec4 was made because it is useful for colors.
Also, I am aware "Rokka" is a misreading of 六花, but hey, it's the name now.
