#include <iostream>
#include "fechahistorica.h"

using namespace std;

FechaHistorica::FechaHistorica(void)
{
	anio = 0;
	num_sucesos = 0;
}

FechaHistorica::FechaHistorica(const int anio)
{
	this->anio = anio;
	num_sucesos = 0;
}

FechaHistorica::FechaHistorica(const FechaHistorica & otra)
{
	anio = otra.anio;

	sucesos = otra.sucesos;

	num_sucesos = otra.num_sucesos;
}

int FechaHistorica::GetAnio(void) const
{
	return(anio);
}

Vector_Dinamico<string> FechaHistorica::GetSucesos(void) const
{
	return(sucesos);
}

string FechaHistorica::GetSuceso(const int indice) const
{
	return(sucesos[indice]);
}

int FechaHistorica::GetNumSucesos(void) const
{
	return(sucesos.size());
}

void FechaHistorica::SetAnio(const int anio)
{
	this->anio = anio;
}

void FechaHistorica::AniadeSuceso(const string suceso)
{
	if(num_sucesos == sucesos.size())
		sucesos.resize(sucesos.size()+1);
	sucesos[num_sucesos] = suceso;
	num_sucesos++;
}

void FechaHistorica::EliminaSuceso(const int indice)
{
	int p;

	for(p = indice; p < sucesos.size() - 1; p++)
		sucesos[p] = sucesos[p + 1];
	num_sucesos--;
	sucesos.resize(p);
}

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

string FechaHistorica::toString()
{
	string resultado = "";

	resultado = to_string(anio) + ": ";

	for(int i = 0; i < sucesos.size(); i ++)
		resultado += sucesos[i] + "\n";

	return resultado;
}
