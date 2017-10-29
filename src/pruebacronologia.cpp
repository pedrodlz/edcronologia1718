#include "cronologia.h"
#include "fechahistorica.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

   if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   f.close();

   Cronologia mi_cronologia;
   mi_cronologia.LeerCronologia(argv[1]);

   cout << "\n---------------------------------------------------------------------" <<
	endl << "Contenido de la Cronologia: " << argv[1] << endl;
	cout << "---------------------------------------------------------------------" <<
	endl << endl;
   cout << mi_cronologia.toString();

	int min_anio,max_anio;

	do{
		cout << "Introduzca el año minimo del intervalo a crear: ";
		cin >> min_anio;
	}while(min_anio < 1900 || min_anio > 2017);

	do{
		cout << "Introduzca el año maximo del intervalo a crear: ";
		cin >> max_anio;
	}while(max_anio < min_anio || max_anio > 2017);

   Cronologia cronologia_2 = mi_cronologia.CreaSubCronoIntervalo(min_anio,max_anio);
   Cronologia cronologia_3 = mi_cronologia.CreaSubCronoIntervalo(1923,1940);

   cout << "\n----------------------------------------------------------------------" << endl;
   cout << "Contenido de la cronologia creada a partir del intervalo: " << min_anio
	<< " - " << max_anio << endl;
   cout << "----------------------------------------------------------------------" << endl << endl;
	cout << cronologia_2.toString();
   cout << "\n----------------------------------------------------------------------" << endl;
   cout << "Contenido de la cronologia creada a partir del intervalo: " << "1923"
	<< " - 1940" << endl;
   cout << "----------------------------------------------------------------------" << endl << endl;
   cout << cronologia_3.toString();

   Cronologia cronologia_4 = cronologia_2 + (cronologia_3);

   cout << "\n----------------------------------------------------------------------" << endl;
   cout << "Contenido de la union de las dos cronologias anteriores" << endl;
   cout << "----------------------------------------------------------------------" << endl << endl;
	cout << cronologia_4.toString();

   cout << "\n----------------------------------------------------------------------" << endl;
   cout << "Creacion de un fichero con el contenido de una cronologia" << endl;
   cout << "----------------------------------------------------------------------" << endl << endl;

   char nombre[100];
   string clave;

   cout << "Indique nombre del fichero en el que guardar la cronologia: ";
   cin >> nombre;

   cronologia_4.EscribirCronologia(nombre);
   cout << "\n----------------------------------------------------------------------" << endl;
   cout << "Creacion de una cronologia a partir de una palabra clave" << endl;
   cout << "----------------------------------------------------------------------" << endl << endl;

   cout << "Indique palabra clave: ";
   cin >> clave;

   cout << endl;
   cout << "Buscando palabra clave '" << clave << "' en la cronologia.... " << endl << endl;

	cout << "Contenido de la cronologia creada a partir de la palabra clave '" << clave << "': "
	<< endl << "****************************************************************************" <<
	endl << endl;

   Cronologia cronologia_5 = mi_cronologia.CreaSubCronoPalabra(clave);

   cout << cronologia_5.toString();
   cout << "----------------------------------------------------------" << endl;


}
