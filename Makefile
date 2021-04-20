
# Configuration
CC  = g++
APP = MultTable
BINDIR = bin/

# Common flags and lids dir
COMMON_FLAGS = -Wall -Wextra -std=c++17 -O3

ifeq ($(OS),Windows_NT)
# Windows flags
FLAGS = 
else
# Linux flags
FLAGS = -lpthread
endif

SRC = src/Source.cpp src/MultTable.cpp
OBJ = $(SRC:*.c=.o)

all: $(APP)
$(APP): $(OBJ)
	$(CC) -o $(BINDIR)$(APP) $(SRC) $(FLAGS) $(COMMON_FLAGS)

clean:
	rm -rf $(OBJS)
	rm -rf $(APP).exe
	rm -rf $(APP).out
	rm -rf $(APP)