CXX=g++
CC=$(CXX)

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -g3
CXXFLAGS = $(CFLAGS) -std=c++17
CXXFLAGS += -I/usr/include/curl
LDLIBS = -pthread

LDLIBS +=  -lcurlpp -lcurl 
LDLIBS += -lgumbo 
LDLIBS += -ljsoncpp

CPPFLAGS += -DDEBUG
CPPFLAGS += -MMD -MP
CPPFLAGS += -I$(INCLUDES_DIR)

INCLUDES_DIR = ../inc
SOURCES_DIR = ../src

OBJECTS = $(SOURCES_DIR)/search.cpp \
		  $(SOURCES_DIR)/ui.cpp \
		  $(SOURCES_DIR)/data_handler.cpp \
		  $(SOURCES_DIR)/term.cpp \
		  $(SOURCES_DIR)/query.cpp \
		  $(SOURCES_DIR)/manager.cpp \
		  $(SOURCES_DIR)/pages_connection.cpp \
		  $(SOURCES_DIR)/url_data.cpp \
		  $(SOURCES_DIR)/crawler.cpp \
		  $(SOURCES_DIR)/url_data_download.cpp \
		  $(SOURCES_DIR)/page_data_analyzer.cpp \
		  $(SOURCES_DIR)/page.cpp \
		  $(SOURCES_DIR)/config_info.cpp \
		  $(SOURCES_DIR)/config_json.cpp \
		  $(SOURCES_DIR)/validator.cpp 

SOURCE = main.cpp $(OBJECTS)  
TARGET = main

all: $(TARGET)

main : $(SOURCE)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

vala: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET) 2> vala.txt

hell: $(TARGET)
	valgrind  --tool=helgrind ./$(TARGET) 2> hell.txt

clean:
	@$(RM) -f ./$(TARGET) *.o 


.PHONY : make clean check recheck vala hell all 

make:
	@echo 'Attend a maker faire'
	@${TRUE}
