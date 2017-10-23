#include <iostream>
#include "cronologia.h"

using namespace std;

Cronologia::Cronologia(void){}

//Cronologia::Cronologia(){}

Cronologia::Cronologia(const Cronologia & otra)
{
	fechas = otra.fechas;
}

void Cronologia::AniadeFecha(FechaHistorica una_fecha)
{
  int anio = una_fecha.GetAnio();
  bool no_encontrado = true;

	for(int i = 0; i<MAX_ANIO && no_encontrado; i++){
	    if(i == anio){
	      no_encontrado = false;
		}
	}
}

void Cronologia::EliminaFecha(int anio)
{
/*	int p;

	for(p = i; p < sucesos.size() - 1; p++)
		sucesos[p] = sucesos[p + 1];

	sucesos.resize(p);
	*/
}

void Cronologia::UnionCrono(Cronologia cron1,Cronologia cron2)
{

}
