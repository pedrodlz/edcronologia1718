/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA Cronología
  *
  */

#ifndef CRONOLOGIA
#define CRONOLOGIA

#include <string>
#include "Vector_Dinamico.h"
#include "fechahistorica.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto
  * que almacena la informacion de un conjunto de fechas ordenadas cronologicamente
  * a partir de un tema. Este TDA incluye operaciones para poder operar con
  * muchas fechas facilmente
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Dario Abad Tarifa
  * @author Pedro Domínguez López
  * @date Octubre 31
  */


class Cronologia{

private:
/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.anio>=0
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Cronologia representa al valor
  *
  * (rep.num,rep.den)
  *
  */

	const int MIN_ANIO = 1900; /**< Año minimo */
	const int MAX_ANIO = 2017; /**< Año maximo */

	Vector_Dinamico<FechaHistorica> fechas; /**< Array de fechas*/

public:

	/**
	  * @brief Constructor por defecto de la clase. Crea una cronologia vacía
	  */
	Cronologia(void);

	/**
	  * @brief Constructor a partir de fichero
	  * @param nombre nombre del fichero de texto a partir del cual se construye la cronologia
	  * @pre
	  */
  	Cronologia(const char * nombre);

	/**
	  * @brief Constructor de copias de la clase
	  * @param otra otro objeto de la cronologia
	  * @pre
	  */
  	Cronologia(const Cronologia & otra);

	/**
	  * @brief Consultor del atributo fechas
	  */
  	Vector_Dinamico<FechaHistorica> GetFechas(void);

	/**
	  * @brief Consultor de fechas concretas
	  * @param indice indice de la fecha a consultar
	  * @pre indice >=0 && indice<num_fechas
	  */
  	FechaHistorica GetFecha(const int indice);

	/**
	  * @brief Busca un año en una cronologia
	  * @param anio año a buscar
	  * @return Devuelve el indice de la cronologia donde se encuentra el año
	  * @pre
	  */
	int BuscaFecha(const int anio);

	/**
	  * @brief Si un año no se encuentra en la cronologia busca el siguiente menor
	  * @param anio año del que se busca otro año inferior
	  * @return Devuelve el indice de la cronologia donde se encuentra el año inferior
	  * @pre
	  */
	int SigFechaMenor(const int anio);

	/**
	  * @brief Si un año no se encuentra en la cronologia busca el siguiente mayor
	  * @param anio año del que se busca otro año superior
	  * @return Devuelve el indice de la cronologia donde se encuentra el año superior
	  * @pre
	  */
	int SigFechaMayor(const int anio);

	/**
	  * @brief Añade una fecha a la cronología
	  * @param fecha Fecha a añadir
	  * @pre
	  */
	void AniadeFecha(FechaHistorica una_fecha);

	/**
	  * @brief Elimina una fecha de la cronología
	  * @param anio año de la fecha a eliminar
	  * @pre
	  */
	void EliminaFecha(int anio);

	/**
	  * @brief Une dos cronologias
	  * @param cron_aniadir cronologia a añadir
	  * @return No devuelve nada pero la union de ambas se guarda en la cronologia implicita
	  * @pre
	  */
  	void UnionCrono(Cronologia cron_aniadir);

	/**
	  * @brief Crea una subcronologia a partir de una palabra clave
	  * @param palabra palabra clave a buscar
	  * @return Devuelve una nueva cronologia con las fechas y solo con los sucesos donde aparce la palabra
	  * @pre
	  */
	Cronologia CreaSubCronoPalabra(string palabra);

	/**
	  * @brief Crea una cronologia a partir de dos años, o si dichos años no estan, de sus años mas proximos
	  * @param min año minimo del intervalo
	  * @param max año maximo del intervalo
	  * @return Devuelve una nueva cronologia con las fechas del intervalo
	  * @pre
	  */
	Cronologia CreaSubCronoIntervalo(int min, int max);

	/**
	  * @brief Escribe la cronologia en un fichero de texto
	  * @param nombre nombre del fichero donde se escribe
	  * @pre
	  */
	void EscribirCronologia(const char * nombre);

	/**
	  * @brief Sobrecarga del operador <<
	  * @param ostream & flujo de salida
	  * @param Cronologia & Cronologia sobre la que se va a trabajar
	  */
	friend ostream & operator << (ostream &, Cronologia &);

	/**
	  * @brief Lee una cronologia a partir de un fichero
	  * @param nombre nombre del fichero de donde se lee
	  * @pre
	  */
	void LeerCronologia(const char * nombre);

	/**
	  * @brief Sobrecarga del operador >>
	  * @param ostream & flujo de entrada
	  * @param Cronologia & Cronologia sobre la que se va a trabajar
	  */
	friend istream & operator >> (istream &, Cronologia &);

	/**
	  * @brief Sobrecarga del operador =, iguala una cronologia a otra
	  * @param otra cronologia de la que se copia
	  * @pre
	  */
	Cronologia& operator=(const Cronologia & otra);

	/**
	  * @brief Suma dos cronologias usando el operador +
	  * @param otra cronologia a sumar con el objeto implicito
	  * @pre
	  */
	Cronologia operator + (const Cronologia & otra);

	/**
	  * @brief Pasa la informacion de la cronología a un string
	  * @return Devuelve un string con toda la cronologia
	  * @pre
	  */
	string toString();
};


#endif
