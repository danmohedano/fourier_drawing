INC=./includes
SRC=./src
OBJ=./obj
EXE=fourier.exe

CC = g++
CFLAGS = -Wall -g
LIBS =
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs)

.PHONY: clean_obj clean_exe clean

all: clean setup $(EXE)

setup:
	DISPLAY=:0
	export DISPLAY
	mkdir -p obj 

#~~~~~~~~~~~~~ exe ~~~~~~~~~~~~~#

$(EXE): $(OBJ)/main.o $(OBJ)/data.o
	@echo "Building executable..."
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(SDL_CFLAGS) $(SDL_LDFLAGS)

#~~~~~~~~~~~~~ obj ~~~~~~~~~~~~~#
$(OBJ)/main.o: $(SRC)/main.cpp
	@echo "Compiling main module..."
	$(CC) $(CFLAGS) -c $< -o $@ $(SDL_CFLAGS) $(SDL_LDFLAGS)

$(OBJ)/data.o: $(SRC)/data.cpp
	@echo "Compiling data module..."
	$(CC) $(CFLAGS) -c $< -o $@

#~~~~~~~~~~~~~ cleanup ~~~~~~~~~~~~~#
clean: clean_obj clean_exe

clean_obj:
	@echo "Cleaning $(OBJ)/..."
	rm -f $(OBJ)/*.o

clean_exe:
	@echo "Cleaning exe..."
	rm -f $(EXE)

#~~~~~~~~~~~~~ test ~~~~~~~~~~~~~#
test:
	@echo "Testing $(EXE)..."
	./$(EXE)

test_valgrind:
	@echo "Testing with valgrind $(EXE)..."
	valgrind --leak-check=full ./$(EXE)