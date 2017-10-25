#include <iostream>
#include "cronologia.h"

using namespace std;

Cronologia::Cronologia(void){}

//Cronologia::Cronologia(){}

Cronologia::Cronologia(const Cronologia & otra)
{
	this.fechas = otra.fechas;
}

int Cronologia::BuscaFecha(int anio)
{
	int indice = -1;

	if(anio >= MIN_ANIO && anio <= MAX_ANIO){

		bool no_encontrado = true;

		for(int i = 0; i < this.fechas.size() && no_encontrado; i++){
			if(this.fechas[i] == anio){
				indice = i;
				no_encontrado = false;
			}
		}
	}

	return indice;
}

void Cronologia::AniadeFecha(FechaHistorica una_fecha)
{
	int anio = una_fecha.GetAnio();

	if(anio >= MIN_ANIO && anio <= MAX_ANIO){

		indice = this.BuscaFecha(anio);

		if(indice != -1)

			for(int p = 0; p < una_fecha.sucesos.size(); p ++)
				this.fechas[indice].AniadeSuceso(una_fecha.sucesos[p]);

		else{

			this.fechas.resize(fechas.size() + 1);

			if(anio < this.fechas[0].GetAnio()){

				for(int i = this.fechas.size(); i > 0; i--)
					this.fechas[i] = this.fechas[i - 1];

				this.fechas[0] = una_fecha;

			}
			else if (anio > this.fechas[this.fechas.size() - 1].GetAnio()){

				this.fechas[this.fechas.size()] = una_fecha;

			}
			else{

				bool no_encontrado = true;

				for(int i = 0; i < this.fechas.size()-1 && no_encontrado; i++){
					if(this.fechas[i].GetAnio() < anio && this.fechas[i+1].GetAnio() > anio){

						for(int p = this.fechas.size(); p > i-1; p--)
							this.fechas[p] = this.fechas[p-1];

						this.fechas[i+1] = una_fecha;
						no_encontrado = false;
					}
				}
			}
		}
	}
}

void Cronologia::EliminaFecha(int anio)
{
	if(anio >= MIN_ANIO && anio <= MAX_ANIO){

		int indice = this.BuscaFecha(anio);

		if(indice != -1){}

			for(int p = indice; p < this.fechas.size() - 1; p++)
				this.fechas[p] = this.fechas[p+1];

			this.fechas.resize(this.fechas.size() - 1);
		}
	}
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

Cronologia Cronologia::CreaSubCronoIntervalo(int min_anio, int max_anio)
{
	Cronologia sub_cron;

	if(min_anio > max_anio){
		int aux;
		aux = min_anio;
		min_anio = max_anio;
		max_anio = aux;
	}

	if((min_anio >= MIN_ANIO && min_anio <= MAX_ANIO) &&
		(max_anio >= MIN_ANIO && max_anio <= MAX_ANIO)){

			int indice_i, indice_f;

			while(this.fechas[indice_i] !=)

	}

	return sub_cron;
}
