CXX = g++
CXXFLAGS = -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -lGLEW


output: shader.o window.o main.o
	$(CXX) $(CXXFLAGS) shader.o window.o main.o -o yuki

main.o: Rokka-core/src/main.cpp
	$(CXX) -c Rokka-core/src/main.cpp

shader.o: Rokka-core/src/graphics/shader.cpp Rokka-core/src/graphics/shader.h
	$(CXX) -c Rokka-core/src/graphics/shader.cpp

window.o: Rokka-core/src/graphics/window.cpp Rokka-core/src/graphics/window.h
	$(CXX) -c Rokka-core/src/graphics/window.cpp

clean:
	rm *.o yuki

# all: Rokka-core/src/graphics/shader.cpp Rokka-core/src/graphics/window.cpp Rokka-core/src/main.cpp -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -lGLEW -o Rokka-core/bin/exe-name
