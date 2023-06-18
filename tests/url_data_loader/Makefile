CXX=g++
CC=$(CXX)

CFLAGS = -pedantic -Wall -Werror -pthread
CFLAGS += -ggdb
CXXFLAGS = $(CFLAGS) -std=c++17
CXXFLAGS += -I/usr/include/curl


LDLIBS =  -lcurlpp -lcurl

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src

OBJECTS = $(SOURCES_DIR)/url_data_loader.o 
	
									
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