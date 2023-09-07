$(CXX)=g++
CC=CXX

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -ggdb
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -ljsoncpp
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS += -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src

OBJECTS = $(SOURCES_DIR)/game.cpp \
		  $(SOURCES_DIR)/main_screen.cpp \
		  $(SOURCES_DIR)/game_screen.cpp \
		  $(SOURCES_DIR)/button.cpp \
		  $(SOURCES_DIR)/player.cpp \
		  $(SOURCES_DIR)/brick.cpp \
		  $(SOURCES_DIR)/ball.cpp \
		  $(SOURCES_DIR)/padle.cpp \
		  $(SOURCES_DIR)/ui.cpp \
		  $(SOURCES_DIR)/game_manager.cpp \
		  $(SOURCES_DIR)/winner.cpp \
		  $(SOURCES_DIR)/top10_screen.cpp \
		  $(SOURCES_DIR)/music.cpp \
		   $(SOURCES_DIR)/icon.cpp

SOURCE = main.cpp $(OBJECTS) 
TARGET = main

SOURCE_TEST = utest.cpp $(OBJECTS) 
TARGET_TEST = utest

all: $(TARGET) $(TARGET_TEST)

main : $(SOURCE)

utest : $(SOURCE_TEST)

check : $(TARGET) 
	@./$(TARGET) -v

checkt : $(TARGET_TEST) 
	@./$(TARGET_TEST) -v

recheck: clean check

recheckt: cleant checkt

clean:
	@$(RM) -f ./$(TARGET) *.o

cleant:
	@$(RM) -f ./$(TARGET_TEST) *.o


.PHONY : make clean check recheck cleant checkt recheckt all

make:
	@echo 'Attend a maker faire'
	@${TRUE}
