SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o
	g++ -std=c++11 -o programa

$(OBJ)/pruebacronologia.o: $(SRC)/fechahistorica.cpp $(SRC)/Vector_Dinamico.tpp $(INCLUDE)/Vector_Dinamico.h
	g++ -std=c++11 -o $(OBJ)/pruebacronologia.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
