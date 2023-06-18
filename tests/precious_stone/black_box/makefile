$(CXX)=g++
CC=CXX

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -ggdb
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR) -I$(TEST_DIR) -I$(COMMUNICATION_DIR_HPP)

INCLUDES_DIR = ../../../inc/precious_stone
SOURCES_DIR = ../../../src/precious_stone
TEST_DIR = ../../../inc
COMMUNICATION_DIR = ../../../src/communication
COMMUNICATION_DIR_HPP = ../../../inc/communication

OBJECTS = $(SOURCES_DIR)/black_box.cpp \
		  $(SOURCES_DIR)/console_destination.cpp \
		  $(SOURCES_DIR)/console_source.cpp \
		  $(SOURCES_DIR)/encoder_vowel.cpp \
		  $(SOURCES_DIR)/encoder_title.cpp \
		  $(SOURCES_DIR)/encoder_caesar.cpp \
		  $(COMMUNICATION_DIR)/udp_server.cpp \
		  $(SOURCES_DIR)/udp_source.cpp \
		  $(SOURCES_DIR)/file_source.cpp\
		  $(SOURCES_DIR)/file_destination.cpp\
		  $(SOURCES_DIR)/message.cpp

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



