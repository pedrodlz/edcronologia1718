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

void Cronologia::UnionCrono(Cronologia cron_aniadir)
{
	for(int i = 0; i < cron_aniadir.fechas.size(); i++)
		this.AniadeFecha(cron_aniadir.fechas[i]);
}

Cronologia Cronologia::CreaSubCronoPalabra(string palabra)
{
	Vector_Dinamico<bool> sucesos_clave;
	bool algun_false = true;
	Cronologia sub_cron;
	FechaHistorica fecha_aniadir;
	int p;
	
	for(int i = 0; i < this.fechas.size(); i++){
		sucesos_clave = this.fechas[i].BuscaPalabraClave(palabra);
		for(p = 0; p < sucesos_clave.size() && algun_false; p++)
			if(sucesos_clave[p]) 
				algun_false = false;
		if(!algun_false){
			fecha_aniadir.SetAnio(this.fechas[i].GetAnio());
			for(p = 0; p < sucesos_clave.size() && algun_false; p++)
				if(sucesos_clave[p]) 
					fecha_aniadir.AniadeSuceso(sucesos_clave[p]);
			sub_cron.AniadeFecha(fecha_aniadir);
		}
	}
	
	return sub_cron;	
}

Cronologia Cronologia::CreaSubCronIntervalo(int min_anio, int max_anio)
{
	Cronologia sub_cron;

	return sub_cron;
}
