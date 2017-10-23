#include <iostream>
#include "fechahistorica.h"

using namespace std;

FechaHistorica::FechaHistorica(void)
{
	anio = 0;
	sucesos = 0;
	num_sucesos = 0;
}

FechaHistorica::FechaHistorica(const int anio)
{
	this->anio = anio;
}

FechaHistorica::FechaHistorica(const FechaHistorica & otra)
{
	anio = otra.anio;

	sucesos = otra.sucesos;

	num_sucesos = otra.num_sucesos;
}

FechaHistorica::~FechaHistorica(void)
{
	anio = 0;
	num_sucesos = 0;
}

int FechaHistorica::GetAnio(void) const
{
	return(anio);
}

Vector_Dinamico<string> FechaHistorica::GetSucesos(void) const
{
	return(sucesos);
}

int FechaHistorica::GetNumSucesos(void) const
{
	return(num_sucesos);
}

void FechaHistorica::SetAnio(int anio)
{
	this->anio = anio;
}

void FechaHistorica::AniadeSuceso(string suceso)
{
	sucesos.resize(sucesos.size()+1);
	
	sucesos[sucesos.size()] = suceso;
}

void FechaHistorica::EliminaSuceso(int i)
{
	int p;
	
	for(p = i; p < sucesos.size() - 1; p++)
		sucesos[p] = sucesos[p + 1];
	
	sucesos.resize(p);
}

void FechaHistorica::LiberarMemoria(void)
{
	if(sucesos.size()){
		sucesos.~Vector_Dinamico();
		num_sucesos = 0;
	}
}

