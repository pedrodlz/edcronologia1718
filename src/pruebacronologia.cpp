#include "cronologia.h"
#include "fechahistorica.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
/*
  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
*/
   Cronologia mi_cronologia;
   //f>>mi_cronologia; //Cargamos en memoria la cronología.

   FechaHistorica fecha (1998);
   fecha.AniadeSuceso("Prueba");
   fecha.AniadeSuceso("Prueba2");

   cout << fecha.GetAnio() << "  " << fecha.GetNumSucesos() << "  "
            << fecha.GetSuceso(0) << "  " << fecha.GetSuceso(1) << endl;

    fecha.EliminaSuceso(0);

    cout << fecha.GetAnio() << "  " << fecha.GetNumSucesos() << "  "
             << fecha.GetSuceso(0) << endl;


   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */

   // Algunas sugerencias:
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés


}
