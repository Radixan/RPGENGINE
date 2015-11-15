OS=$(shell uname)

# LINUX OS
ifneq (,$(findstring Linux, $(OS)))

C++ := g++
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := -lsfml-graphics -lsfml-window -lsfml-system
CC_FLAGS := -std=c++11 -Werror -Wall -g
BIN_FILE := bin/PokemonIluminati
RM := rm

all: $(OBJ_FILES)
	$(C++) $(LD_FLAGS) $(OBJ_FILES) -o $(BIN_FILE)

obj/%.o: src/%.cpp
	$(C++) $(CC_FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_FILES)

# WINDOWS OS
else

C++ := mingw32-g++
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system
CC_FLAGS := -std=c++11 -Isfml/include
BIN_FILE := bin/PokemonIluminati.exe
RM := del
OBJ_FILES_DEL := $(addprefix obj\,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(OBJ_FILES)
	$(C++) $(LD_FLAGS) $(OBJ_FILES) -o $(BIN_FILE)

obj/%.o: src/%.cpp
	$(C++) $(CC_FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_FILES_DEL)

endif
