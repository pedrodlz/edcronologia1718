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

   cout << "----------------------------------------------------------" << endl;
   cout << mi_cronologia.toString();

   Cronologia cronologia_2 = mi_cronologia.CreaSubCronoIntervalo(1958,1963);
   Cronologia cronologia_3 = mi_cronologia.CreaSubCronoIntervalo(1923,1950);

   cout << "----------------------------------------------------------" << endl;
   cout << cronologia_2.toString();
   cout << "----------------------------------------------------------" << endl;
   cout << cronologia_3.toString();
   cout << "----------------------------------------------------------" << endl;

   Cronologia cronologia_4 = cronologia_2 + (cronologia_3);

   cout << cronologia_4.toString();
   cout << "----------------------------------------------------------" << endl;

   cronologia_4.EscribirCronologia("prueba2");

   cout << "Buscando palabra clave 'Einstein' en la cronologia.... " << endl << endl;

   Cronologia cronologia_5 = mi_cronologia.CreaSubCronoPalabra("Einstein");

   cout << cronologia_5.toString();
   cout << "----------------------------------------------------------" << endl;


   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */

   // Algunas sugerencias:
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés


}
