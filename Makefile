#CODEBLOCKS MINGW
C++ := g++
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := -lsfml-graphics -lsfml-window -lsfml-system
CC_FLAGS := -std=c++11
BIN_FILE := bin/PokemonIluminati
RM := rm

clean:
	$(RM) $(OBJ_FILES)

all: $(OBJ_FILES)
	$(C++) $(LD_FLAGS) $(OBJ_FILES) -o $(BIN_FILE)

obj/%.o: src/%.cpp
	$(C++) $(CC_FLAGS) -c -o $@ $<
