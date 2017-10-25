#include <iostream>
#include "cronologia.h"

using namespace std;

Cronologia::Cronologia(void){}

//Cronologia::Cronologia(){}

Cronologia::Cronologia(const Cronologia & otra)
{
	this.fechas = otra.fechas;
}

void Cronologia::AniadeFecha(FechaHistorica una_fecha)
{
	int anio = una_fecha.GetAnio();
	bool no_encontrado = true;
	
	for(int i = 0; i < this.fechas.size() && no_encontrado; i++){
		if(this.fechas[i].GetAnio == anio){
			for(int p = 0; p < this.fechas[i].sucesos.size(); p ++)
				this.fechas[i].AniadeSuceso(this.fechas[i].sucesos[p]);
			no_encontrado = false;
		}
		else if(this.fechas[i].GetAnio < anio && this.fechas[i+1].GetAnio > anio){
			this.fechas.resize(fechas.size() + 1);
			for(int p = this.fechas.size(); p > i-1; p--)
				this.fechas[p] = this.echas[p-1];
			this.fechas[i+1] = una_fecha;
		}
	}
}

void Cronologia::EliminaFecha(int anio)
{
	bool no_encontrado = true;
	int p;
	
	for(int i = 0; i < this.fechas.size() && no_encontrado; i++)
		if(this.fechas[i].GetAnio == anio){
			for(p = i; p < this.fechas.size() - 1; p++)
				this.fechas[p] = this.fechas[p+1];
			no_encontrado = false;
		}
	
	this.fechas.resize(p);	
}

void Cronologia::UnionCrono(Cronologia cron1,Cronologia cron2)
{

}
