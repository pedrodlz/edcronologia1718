#ifndef CRONOLOGIA
#define CRONOLOGIA

#include <string>
#include "Vector_Dinamico.h"
#include "fechahistorica.h"

using namespace std;


class Cronologia{

private:

	const int MIN_ANIO = 1900;
	const int MAX_ANIO = 2017;

	Vector_Dinamico<FechaHistorica> fechas;

public:

	Cronologia(void);

  	//Cronologia();

	Cronologia(const Cronologia & otra);

	void AniadeFecha(FechaHistorica una_fecha);

	void EliminaFecha(int anio);

  	void UnionCrono(Cronologia cron_aniadir);
	
	Cronologia CreaSubCronoPalabra(string palabra);
	
	Cronologia CreaSubCronoIntervalo(int min, int max);


private:
	void LiberarMemoria (void);


};


#endif
