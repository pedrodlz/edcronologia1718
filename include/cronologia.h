#ifndef CRONOLOGIA
#define CRONOLOGIA

#include <string>
#include "Vector_Dinamico.h"
#include "fechahistorica.h"

using namespace std;


class Cronologia{

private:
	
	Vector_Dinamico<FechaHistorica> fechas;

public:
  
	Cronologia(void);
  
  	Cronologia();

	Cronologia(const Cronologia & otra);	

	void AniadeFecha(FechaHistorica una_fecha);
	
	void EliminaFecha(int anio);
  
  	void UnionCrono(Cronologia cron1, Cronologia cron2);


private:
	void LiberarMemoria (void);


};


#endif
