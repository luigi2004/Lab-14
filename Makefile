AutomatedMakefile = am
CC = g++

FILES = TableDriver.o
EXECUTABLE = Lab14.exe

PROJECT_PATH = $(PROJECT_DIR)

INC_DIRS = -I$(PROJECT_PATH)/CSC2110/ 
LIB_DIRS = -L$(PROJECT_PATH)/CSC2110/ 
LIBS = -lCSC2110  

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

all: Project

Project: 		$(FILES)
			$(LINK) $(EXECUTABLE) $(FILES) $(LIBS)

TableDriver.o:		TableSortedList.h SortedListDoublyLinked.h TableDriver.cpp
					$(COMPILE) TableDriver.cpp

