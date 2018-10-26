CCX = g++
CFLAGS = -O0 -g -w -Wall -std=c++11
FLTK_FLAGS = --ldflags --use-images
SOURCE = Ex15.6Gistogram
DEPENDENCES = ../../GUI/Graph.cpp ../../GUI/Window.cpp ../../GUI/GUI.cpp ../../GUI/Simple_window.cpp
#OBJECTS = Graph.o Window.o GUI.o Simple_window.o

$(SOURCE):
	$(CCX)	$(CFLAGS)	-o $(SOURCE)	$(DEPENDENCES)	$(SOURCE).cpp	`fltk-config $(FLTK_FLAGS)`	

clean:
	rm -r $(SOURCE) $(SOURCE).dSYM

#g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp 12test.cpp `fltk-config --ldflags --use-images` -o 12test.o
