# Variables de configuración
CC = g++
CFLAGS = -std=c++11 -Wall -I./librerias -I./fuentes 
LDFLAGS = -L./librerias -lglfw -lGL -lGLU 

# Directorios
SRC_DIR = fuentes
OBJ_DIR = objetos
LIB_DIR = librerias
BIN_DIR = binarios

# Archivos fuente
SRC = $(SRC_DIR)/main.cpp $(LIB_DIR)/renderizador_opengl.cpp
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/renderizador_opengl.o
BIN = $(BIN_DIR)/main

# Objetivo predeterminado
all: $(BIN)

# Regla para compilar el ejecutable
$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Regla para compilar main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar funciones.o
$(OBJ_DIR)/renderizador_opengl.o: $(LIB_DIR)/renderizador_opengl.cpp $(LIB_DIR)/renderizador_opengl.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar los archivos generados
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/main

# Regla para compilar y luego limpiar (útil para depurar)
rebuild: clean all

