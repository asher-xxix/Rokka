# CC=g++
# CFLAGS=-lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -lGLEW
# LDFLAGS=
# SOURCES=Rokka-core/src/graphics/shader.cpp Rokka-core/src/graphics/window.cpp Rokka-core/src/main.cpp
# OBJECTS=$(SOURCES:.cpp=.o)
# EXECUTABLE=Rokka-core/bin/exe-name
#
# all: $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)

#.cpp.o: $(CC) $(CFLAGS) $< -o $@

all: Rokka-core/src/graphics/shader.cpp Rokka-core/src/graphics/window.cpp Rokka-core/src/main.cpp -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lm -ldl -lXinerama -lXcursor -lGLEW -o Rokka-core/bin/exe-name
