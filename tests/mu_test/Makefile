$(CXX)=g++
$(CC)=$(CXX)

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -g
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS = -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src


SOURCE := utest.cpp
TARGET := utest

all: $(TARGET)

$(SOURCE) : classes_under_test.hpp $(INCLUDES_DIR)/mu_test.h

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) *.o


.PHONY : make clean check recheck all 

make:
	@echo 'Attend a maker faire'
	@${TRUE}
