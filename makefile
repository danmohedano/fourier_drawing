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

$(EXE): $(OBJ)/main.o $(OBJ)/data.o $(OBJ)/computation.o $(OBJ)/io.o
	@echo "Building executable..."
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(SDL_CFLAGS) $(SDL_LDFLAGS)

#~~~~~~~~~~~~~ obj ~~~~~~~~~~~~~#
$(OBJ)/main.o: $(SRC)/main.cpp
	@echo "Compiling main module..."
	$(CC) $(CFLAGS) -c $< -o $@ $(SDL_CFLAGS) $(SDL_LDFLAGS)

$(OBJ)/data.o: $(SRC)/data.cpp $(INC)/data.h
	@echo "Compiling data module..."
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/computation.o: $(SRC)/computation.cpp $(INC)/computation.h $(INC)/data.h
	@echo "Compiling computation module..."
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/io.o: $(SRC)/io.cpp $(INC)/io.h $(INC)/data.h
	@echo "Compiling io module..."
	$(CC) $(CFLAGS) -c $< -o $@ $(SDL_CFLAGS) $(SDL_LDFLAGS)

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