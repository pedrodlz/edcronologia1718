#include <iostream>
#include "fechahistorica.h"

using namespace std;

// Constructor sin argumentos
FechaHistorica::FechaHistorica(void)
{
	anio = 0;
	num_sucesos = 0;
}

// Constructor con un argumento
FechaHistorica::FechaHistorica(const int anio)
{
	this->anio = anio;
	num_sucesos = 0;
}

// Constructor de copia
FechaHistorica::FechaHistorica(const FechaHistorica & otra)
{
	anio = otra.anio;

	sucesos = otra.sucesos;

	num_sucesos = otra.num_sucesos;
}

// Consultor de anio
int FechaHistorica::GetAnio(void) const
{
	return(anio);
}

// Consultor del vector de sucesos
Vector_Dinamico<string> FechaHistorica::GetSucesos(void) const
{
	return(sucesos);
}

// Consultor de suscesos concretos dentro del vector
string FechaHistorica::GetSuceso(const int indice) const
{
	return(sucesos[indice]);
}

// Consultor del numero de sucesos
int FechaHistorica::GetNumSucesos(void) const
{
	return(sucesos.size());
}

// Modificador de anio
void FechaHistorica::SetAnio(const int anio)
{
	this->anio = anio;
}

// Metodo para añadir un suceso a la fecha
void FechaHistorica::AniadeSuceso(const string suceso)
{
	if(num_sucesos == sucesos.size())
		sucesos.resize(sucesos.size()+1);
	sucesos[num_sucesos] = suceso;
	num_sucesos++;
}

// Metodo para eliminar un sucesos de la fecha
void FechaHistorica::EliminaSuceso(const int indice)
{
	int p;

	for(p = indice; p < sucesos.size() - 1; p++)
		sucesos[p] = sucesos[p + 1];
	num_sucesos--;
	sucesos.resize(p);
}

// Metodo para buscar una palabra clave en los sucesos
Vector_Dinamico<bool> FechaHistorica::BuscaPalabraClave(const string clave)
{
	Vector_Dinamico<bool> encontrada (num_sucesos);
	for(int i = 0; i < num_sucesos; i++){
		if(sucesos[i].find(clave) == -1){
			encontrada[i] = false;
		}else{
			encontrada[i] = true;
		}
	}
	return (encontrada);
}

// Metodo para construir un string con la informacion de la fecha
string FechaHistorica::toString()
{
	string resultado = "";

	resultado = to_string(anio) + ": ";

	for(int i = 0; i < sucesos.size(); i ++)
		resultado += sucesos[i] + "\n";

	return resultado;
}
