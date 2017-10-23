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
	LiberarMemoria();
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

void FechaHistorica::LiberarMemoria(void)
{
	if(sucesos.size()){
		sucesos.~Vector_Dinamico();
		num_sucesos = 0;
	}
}

int main(){return 0 ;}
