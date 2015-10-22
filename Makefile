#CODEBLOCKS MINGW
C++ := g++
CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS :=
CC_FLAGS := -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system
BIN_FILE := bin/PokemonIluminati
RM := rm

clean:
	$(RM) $(OBJ_FILES)

all: $(OBJ_FILES)
	$(C++) $(LD_FLAGS) $(OBJ_FILES) -o $(BIN_FILE)

obj/%.o: %.cpp
	$(C++) $(CC_FLAGS) -c -o $@ $<
