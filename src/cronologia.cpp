#include <iostream>
#include <fstream>
#include "cronologia.h"

using namespace std;

Cronologia::Cronologia(void){}

Cronologia::Cronologia(const char * nombre)
{
	LeerCronologia(nombre);
}

Cronologia::Cronologia(const Cronologia & otra)
{
	this->fechas = otra.fechas;
}

int Cronologia::BuscaFecha(const int anio)
{
	int indice = -1;

	if(anio >= MIN_ANIO && anio <= MAX_ANIO){

		bool no_encontrado = true;

		for(int i = 0; i < fechas.size() && no_encontrado; i++){
			if(fechas[i].GetAnio() == anio){
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

		if(fechas.size() == 0){
			fechas.resize(1);
			fechas[0] = una_fecha;
		}
		else{

			int indice = BuscaFecha(anio);

			if(indice != -1){

				for(int p = 0; p < una_fecha.GetNumSucesos(); p ++)
					fechas[indice].AniadeSuceso(una_fecha.GetSuceso(p));
			}
			else{

				fechas.resize(fechas.size() + 1);

				if(anio < fechas[0].GetAnio()){

					for(int i = fechas.size(); i > 0; i--)
						fechas[i] = fechas[i - 1];

					fechas[0] = una_fecha;

				}
				else if (anio > fechas[fechas.size() - 1].GetAnio()){

					fechas[fechas.size()-1] = una_fecha;

				}
				else{

					bool no_encontrado = true;

					for(int i = 0; i < fechas.size()-1 && no_encontrado; i++){
						if(fechas[i].GetAnio() < anio && fechas[i+1].GetAnio() > anio){

							for(int p = fechas.size(); p > i-1; p--)
								fechas[p] = fechas[p-1];

							fechas[i+1] = una_fecha;
							no_encontrado = false;
						}
					}
				}
			}
		}
	}
}

void Cronologia::EliminaFecha(int anio)
{
	if(anio >= MIN_ANIO && anio <= MAX_ANIO){

		int indice = BuscaFecha(anio);

		if(indice != -1){

			for(int p = indice; p < fechas.size() - 1; p++)
				fechas[p] = fechas[p+1];

			fechas.resize(fechas.size() - 1);
		}
	}
}

void Cronologia::UnionCrono(Cronologia cron_aniadir)
{
	for(int i = 0; i < cron_aniadir.fechas.size(); i++)
		AniadeFecha(cron_aniadir.fechas[i]);
}

Cronologia Cronologia::CreaSubCronoPalabra(string palabra)
{
	Vector_Dinamico<bool> sucesos_clave;
	bool todos_false = true;
	Cronologia sub_cron;
	FechaHistorica fecha_aniadir;
	int p;

	for(int i = 0; i < fechas.size(); i++){
		sucesos_clave = fechas[i].BuscaPalabraClave(palabra);
		for(p = 0; p < sucesos_clave.size() && todos_false; p++)
			if(sucesos_clave[p])
				todos_false = false;
		if(!todos_false){
			fecha_aniadir.SetAnio(fechas[i].GetAnio());
			for(p = 0; p < sucesos_clave.size(); p++)
				if(sucesos_clave[p])
					fecha_aniadir.AniadeSuceso(fechas[i].GetSuceso(p));
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

			int indice_i = BuscaFecha(min_anio),
				indice_f = BuscaFecha(max_anio);

			if (indice_i != -1 && indice_f != -1){
				for(int i = indice_i; i <= indice_f; i++)
					sub_cron.AniadeFecha(fechas[i]);
			}
	}

	return sub_cron;
}

void Cronologia::LeerCronologia(const char * nombre)
{
	ifstream fi (nombre);

	int num;

	string suceso;

	while(fi >> num){
		FechaHistorica fecha (num);
		char c = fi.get();
		suceso = "";
		while(c != '\n'){
			c = fi.get();
			if(c != '#' || c != '\n'){
				suceso += c;
			}else{
				fecha.AniadeSuceso(suceso);
			}
		}
		AniadeFecha(fecha);
	}

	fi.close();

}

string Cronologia::toString()
{
	string resultado = "";

	for(int i = 0; i < fechas.size(); i++)
		resultado += fechas[i].toString() + "\n";

	return resultado;
}
