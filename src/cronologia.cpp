#include <iostream>
#include <fstream>
#include <string>
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

int Cronologia::SigFechaMenor(const int anio)
{
	int sig_menor = anio;
	bool mayor = false;

	for(int i = 1; i < fechas.size() && !mayor; i++){
		if(anio < fechas[i].GetAnio()){
			mayor = true;
		}
		sig_menor = fechas[i-1].GetAnio();
	}
	return sig_menor;
}

int Cronologia::SigFechaMayor(const int anio)
{
	int sig_mayor = anio;
	bool menor = false;

	for(int i = 0; i < fechas.size() && !menor; i++){
		if(anio < fechas[i].GetAnio()){
			menor = true;
			sig_mayor = fechas[i].GetAnio();
		}
	}

	return sig_mayor;
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

				if(anio < fechas[0].GetAnio()){
					fechas.resize(fechas.size()+1);
					for(int i = fechas.size()-1; i > 0; i--)
						fechas[i] = fechas[i-1];

					fechas[0] = una_fecha;

				}
				else if (anio > fechas[fechas.size()-1].GetAnio()){
					fechas.resize(fechas.size()+1);
					fechas[fechas.size()-1] = una_fecha;
				}
				else{
					fechas.resize(fechas.size()+1);
					int indice = BuscaFecha(SigFechaMayor(anio));

					for(int i = fechas.size()-1; i > indice; i--)
						fechas[i] = fechas[i-1];
					fechas[indice] = una_fecha;
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
		this->AniadeFecha(cron_aniadir.fechas[i]);

}

Cronologia Cronologia::CreaSubCronoPalabra(string palabra)
{
	Vector_Dinamico<bool> sucesos_clave;
	bool todos_false = true;
	Cronologia sub_cron;

	for(int i = 0; i < fechas.size(); i++){

		FechaHistorica fecha_aniadir;

		sucesos_clave = fechas[i].BuscaPalabraClave(palabra);

		for(int p = 0; p < sucesos_clave.size() && todos_false; p++){
			if(sucesos_clave[p])
				todos_false = false;
		}

		if(!todos_false){
			fecha_aniadir.SetAnio(fechas[i].GetAnio());

			for(int p = 0; p < sucesos_clave.size(); p++){
				if(sucesos_clave[p])
					fecha_aniadir.AniadeSuceso(fechas[i].GetSuceso(p));
			}

			sub_cron.AniadeFecha(fecha_aniadir);

			todos_false = true;
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

			/*if (indice_i != -1 && indice_f != -1){
				for(int i = indice_i; i <= indice_f; i++)
					sub_cron.AniadeFecha(fechas[i]);
			}else{*/

			if(indice_i == -1){
				indice_i = BuscaFecha(SigFechaMayor(min_anio));
			}

			if(indice_f == -1){
				indice_f = BuscaFecha(SigFechaMenor(max_anio));
			}

			for(int i = indice_i; i <= indice_f; i++)
				sub_cron.AniadeFecha(fechas[i]);
	}

	return sub_cron;
}

void Cronologia::LeerCronologia(const char * nombre)
{
	ifstream fi (nombre);

	int num;
	char caracter;
	string anio;
	string suceso;

	while(!fi.eof()){
		FechaHistorica fecha;
		anio = "";
		for (int i = 0; i < 4; i++)
			anio += fi.get();

		fecha.SetAnio(stoi(anio));

		caracter = fi.get();

		suceso = "";

		while(caracter != '\n' && caracter != EOF){

			caracter = fi.get();

			if(caracter == '#' || caracter == '\n' || caracter == EOF){
				fecha.AniadeSuceso(suceso);
				suceso = "";
			}
			if(caracter != '#')
				suceso += caracter;
		}

		AniadeFecha(fecha);
	}

	fi.close();
}

Cronologia& Cronologia::operator=(const Cronologia & otra)
{
	if(this != &otra){
		fechas = otra.fechas;
	}
	return *this;
}

Cronologia Cronologia::operator+(const Cronologia & otra)
{
	Cronologia tmp (*this);

	tmp.UnionCrono(otra);

	return tmp;
}

string Cronologia::toString()
{
	string resultado = "";

	for(int i = 0; i < fechas.size(); i++)
		resultado += fechas[i].toString() + "\n";

	return resultado;
}
