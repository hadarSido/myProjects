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

$(TARGET): $(SOURCE) $(INCLUDES_DIR)/inl/generic_utils.hxx $(INCLUDES_DIR)/generic_utils.hpp $(INCLUDES_DIR)/inl/algorithms.hxx $(INCLUDES_DIR)/algorithms.hpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(SOURCE) -o $(TARGET)



check : $(TARGET) 
	@./$(TARGET) -v

recheck: clean check

clean:
	@$(RM) -f ./$(TARGET) *.o


.PHONY : make clean check recheck all

make:
	@echo 'Attend a maker faire'
	@${TRUE}


	