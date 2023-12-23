# Compiler and linker flags
CC 			:= g++
SRC_DIR 	:= src
BIN_DIR 	:= bin
BIN_EXE 	:= $(BIN_DIR)/tennis
OUTPUT 		:= $(if $(findstring Windows_NT, $(OS)), $(BIN_EXE).exe, $(BIN_EXE))
OBJ_DIR 	:= $(BIN_DIR)/obj
INC_DIRS 	:= -I$(SRC_DIR) -I$(SDL_DIR)/include
LIB_DIRS	:= -L$(SDL_DIR)/lib
SRC_FILES 	:= $(wildcard $(SRC_DIR)/*.cpp)
H_FILES 	:= $(wildcard $(SRC_DIR)/*.h)
OBJ_FILES 	:= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
CPP_FLAGS 	:= -std=c++17
LD_FLAGS	:= -lSDL2
# MAKEFLAGS 	+= -j8

# Compile the object files and place them in their own directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(H_FILES)
	$(CC) $(CPP_FLAGS) $(INC_DIRS) -c -o $@ $<

# Link the object files together to create the final executable
$(OUTPUT): $(OBJ_FILES) Makefile
	$(CC) $(LIB_DIRS) $(LD_FLAGS) $(OBJ_FILES) -o $(OUTPUT)

# Compile and link the executable
all: $(OUTPUT)

# Build and run the executable
run: $(OUTPUT)
	$(if $(findstring Windows_NT, $(OS)), cd bin && tennis.exe && cd .., cd bin && ./tennis && cd ..)

# Clean up all the object files and the executable
clean:
	$(if $(findstring Windows_NT, $(OS)), del bin\obj\*.o && del bin\tennis.exe, rm $(OBJ_DIR)/*.o && rm $(OUTPUT))
