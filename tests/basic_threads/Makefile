CXX=g++
CC=$(CXX)

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -g
CXXFLAGS = $(CFLAGS) -std=c++17
LDLIBS = -pthread -lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS = -DDEBUG
CPPFLAGS = -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src

OBJECTS = $(SOURCES_DIR)/basic_threads.cpp


SOURCE = utest.cpp $(OBJECTS)
TARGET = utest

all: $(TARGET)

utest : $(SOURCE)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) *.o out*.jpg


.PHONY : make clean check recheck all

make:
	@echo 'Attend a maker faire'
	@${TRUE}
