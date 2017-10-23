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
	g++ -std=c++11 -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o

$(OBJ)/pruebacronologia.o: $(OBJ)/fechahistorica.o $(OBJ)/fechahistorica.o
	g++ -c -std=c++11 -o $(OBJ)/pruebacronologia.o $(OBJ)/fechahistorica.o $(OBJ)/fechahistorica.o

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp $(INC)/fechahistorica.h
	g++ -c -std=c++11 -I$(INC) -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/fechahistorica.o: $(SRC)/fechahistorica.cpp $(INC)/fechahistorica.h
	g++ -c -std=c++11 -I$(INC) -o $(OBJ)/fechahistorica.o $(SRC)/fechahistorica.cpp

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
