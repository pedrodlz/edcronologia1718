SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(LIB)/libcronolo.a
	$(CXX) -std=c++11 -L./$(LIB) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o -lcronolo

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp $(INC)/cronologia.h
	$(CXX) -c -std=c++11 -I$(INC) -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/fechahistorica.o: $(SRC)/fechahistorica.cpp $(INC)/fechahistorica.h
	$(CXX) -c -std=c++11 -I$(INC) -o $(OBJ)/fechahistorica.o $(SRC)/fechahistorica.cpp

$(OBJ)/pruebacronologia.o: $(SRC)/pruebacronologia.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h
	$(CXX) -c -std=c++11 -I$(INC) -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(LIB)/libcronolo.a: $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o
	ar rvs $(LIB)/libcronolo.a $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/* $(LIB)/* doc/html/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
