#ifndef FECHA
#define FECHA

#include <string>
#include "Vector_Dinamico.h"

using namespace std;


class FechaHistorica{


private:

	int anio;

	Vector_Dinamico<string> sucesos;

	int num_sucesos = 0;

public:
	FechaHistorica(void);

	FechaHistorica(const int anio);

	FechaHistorica(const FechaHistorica & otra);

	~FechaHistorica(void);

	int GetAnio(void) const;

	Vector_Dinamico<string> GetSucesos(void) const;

	string GetSuceso(const int i) const;

	int GetNumSucesos(void) const;

	void SetAnio(const int anio);

	void AniadeSuceso(string un_suceso);

	void EliminaSuceso(int indice);

	Vector_Dinamico<bool> BuscaPalabraClave(const string clave);
	
	string toString ();

};




#endif
