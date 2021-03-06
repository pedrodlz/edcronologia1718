#include <iostream>
#include <fstream>
#include <string>
#include "cronologia.h"

using namespace std;

// Constructor sin argumentos
Cronologia::Cronologia(void){}

// Constructor a partir del nombre de un fichero
Cronologia::Cronologia(const char * nombre)
{
	LeerCronologia(nombre);
}

// Constructor de copia
Cronologia::Cronologia(const Cronologia & otra)
{
	this->fechas = otra.fechas;
}

// Consultor de fechas
Vector_Dinamico<FechaHistorica> Cronologia::GetFechas(void)
{
	return(fechas);
}

// Consultor de fechas
FechaHistorica Cronologia::GetFecha(const int indice)
{
	return(fechas[indice]);
}

// Metodo para obtener el indice de una fecha dentro de una cronologia
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

// Metodo para obtener la primera fecha menor a la indicada como argumento
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

// Metodo para obtener la primera fecha mayor a la indicada como argumento
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

// Metodo para añadir una fecha a la cronologia de forma ordenada
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

// Metodo para eliminar una fecha de la cronologia
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

// Metodo para la union de dos cronologias
void Cronologia::UnionCrono(Cronologia cron_aniadir)
{

	for(int i = 0; i < cron_aniadir.fechas.size(); i++)
		this->AniadeFecha(cron_aniadir.fechas[i]);

}

// Metodo para crear una cronologia con sucesos que contienen una palabra clave
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

// Metodo para crear una cronologia dado un intervalo de años
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

// Metodo para pasar una cronologia a un fichero
void Cronologia::EscribirCronologia(const char * nombre)
{
	ofstream fo (nombre);

	if (!fo) {
		cerr << "Error: no pudo crearse " << nombre << endl;
		exit (1);
	}

	fo << *this;

	fo.close();
}

// Sobrecarga del operador <<
ostream & operator << (ostream & out, Cronologia & crono)
{
	if(crono.GetFechas().size() > 0){
		for(int i = 0; i < crono.GetFechas().size(); i++){
			out << crono.GetFecha(i).GetAnio();
			for(int j = 0; j < crono.GetFecha(i).GetSucesos().size(); j++){
				out << "#" << crono.GetFecha(i).GetSuceso(j);
			}
			out << '\n';
		}

	}
	return (out);
}

// Metodo para leer una cronologia de un fichero
void Cronologia::LeerCronologia(const char * nombre)
{
	ifstream fi (nombre);
	if (!fi){
	 cout<<"No puedo abrir el fichero "<<nombre<<endl;
	 exit(1);
	}

	fi >> *this;

	fi.close();
}

// Sobrecarga del operador >>
istream & operator >> (istream & in, Cronologia & crono)
{
	char caracter;
	string anio;
	string suceso;

	while(!in.eof()){
		FechaHistorica fecha;
		anio = "";

		for (int i = 0; i < 4; i++)
			anio += in.get();

		if(!in.eof()){
			fecha.SetAnio(stoi(anio));

			caracter = in.get();

			suceso = "";

			while(caracter != '\n' && caracter != EOF){

				caracter = in.get();

				if(caracter == '#' || caracter == '\n' || caracter == EOF){
					fecha.AniadeSuceso(suceso);
					suceso = "";
				}
				if(caracter != '#')
					suceso += caracter;
			}

			crono.AniadeFecha(fecha);
		}
	}
	return (in);
}

// Operador =
Cronologia& Cronologia::operator=(const Cronologia & otra)
{
	if(this != &otra){
		fechas = otra.fechas;
	}
	return *this;
}

// Operador + para la union de dos cronologias
Cronologia Cronologia::operator+(const Cronologia & otra)
{
	Cronologia tmp (*this);

	tmp.UnionCrono(otra);

	return tmp;
}

// Metodo para construir un string con la informacion de la cronologia
string Cronologia::toString()
{
	string resultado = "";

	for(int i = 0; i < fechas.size(); i++)
		resultado += fechas[i].toString() + "\n";

	return resultado;
}
