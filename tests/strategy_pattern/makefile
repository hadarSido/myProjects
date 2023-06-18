$(CXX)=g++
CC=CXX

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -ggdb
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR) -I$(INCLUDES_DIR)/strategy_pattern

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src/strategy_pattern

OBJECTS = $(SOURCES_DIR)/selection_sort.cpp \
	      $(SOURCES_DIR)/shake_sort.cpp \
		  $(SOURCES_DIR)/quick_sort.cpp \
		   $(SOURCES_DIR)/sorting_manager.cpp   

SOURCE = utest.cpp $(OBJECTS)
TARGET = utest

all: $(TARGET)

utest : $(SOURCE)

check : $(TARGET) 
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) *.o


.PHONY : make clean check recheck all

make:
	@echo 'Attend a maker faire'
	@${TRUE}



