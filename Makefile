TARGETS := glut_main
OBJECTS := glut_main.o app.o creature_app.o Creature.o Predator.o
CXXFLAGS := -Wall -Werror
LDFLAGS := -lglut -lGLU -lGL
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
# OS X specific options
LDFLAGS := -framework OpenGL -framework GLUT 
CXXFLAGS := $(CXXFLAGS) -Wno-deprecated
endif

all: $(TARGETS)

check: $(TARGETS)
	./glut_main

glut_main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

glut_main.o: glut_main.cpp glut_app.h
	$(CXX) $(CXXFLAGS) -c $<

app.o: app.cpp glut_app.h
	$(CXX) $(CXXFLAGS) -c $<

creature_app.o: creature_app.cpp creature_app.h
	$(CXX) $(CXXFLAGS) -c $<

Creature.o: Creature.cpp Creature.h
	$(CXX) $(CXXFLAGS) -c $<

Predator.o: Predator.cpp Predator.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	-rm -f *~
	-rm -f $(TARGETS)
	-rm -f *.o

