/**
  * @file fechahistorica.h
  * @brief Fichero de cabeceras del TDA FechaHistorica
  *
  */

#ifndef FECHA
#define FECHA

#include <string>
#include "Vector_Dinamico.h"

using namespace std;

/**
  *  @brief T.D.A. FechaHistorica
  *
  * Una instancia @e c del tipo de datos abstracto @c FechaHistorica es un objeto
  * que almacena un año y los sucesos acontecidos en el mismo.
  * Este TDA incluye operaciones para poder administrar la información almacenada
  * de manera sencilla.
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Dario Abad Tarifa
  * @author Pedro Domínguez López
  * @date Octubre 31
  */

class FechaHistorica{


private:

	/**
	  * @page repConjunto Rep del TDA FechaHistorica
	  *
	  * @section invConjunto Invariante de la representación
	  *
	  * El invariante es \e rep.anio>=0
	  *
	  * @section faConjunto Función de abstracción
	  *
	  * Un objeto válido @e rep del TDA FechaHistorica esta representado por
	  *
	  * (anio,sucesos)
	  *
	  */

	int anio; /**< Año relativo a los sucesos*/

	Vector_Dinamico<string> sucesos; /**< Array de sucesos*/

	int num_sucesos = 0; /**< Numero de sucesos acontecidos en anio*/

public:
	/**
	  * @brief Constructor sin argumentos. Crea un objeto FechaHistorica vacío
	  */
	FechaHistorica(void);

	/**
	  * @brief Constructor con un argumento. Inicializa anio
	  * @param anio año con el que iniciar el valor de anio
	  * @pre anio >= 0
	  */
	FechaHistorica(const int anio);

	/**
	  * @brief Constructor de copia.
	  * @param otra referencia al objeto FechaHistorica del que copiar la informacion
	  */
	FechaHistorica(const FechaHistorica & otra);

	/**
	  * @brief Consultor del valor anio
	  * @return Devuelve el valor de anio
	  */
	int GetAnio(void) const;

	/**
	  * @brief Consultor del vector de sucesos
	  * @return Devuelve el vector completo con los sucesos
	  */
	Vector_Dinamico<string> GetSucesos(void) const;

	/**
	  * @brief Consultor de los sucesos
	  * @param indice indice del sucesos a consultar
	  * @return Devuelve el suceso del vector situado en el indice indicado
	  * @pre indice>=0 y indice<numero de sucesos
	  */
	string GetSuceso(const int indice) const;

	/**
	  * @brief Consultor del numero de sucesos
	  * @return Devuelve el numero de sucesos acontecidos en anio
	  */
	int GetNumSucesos(void) const;

	/**
	  * @brief Modificador de anio
	  * @param anio valor de año nuevo
	  * @pre anio >= 0
	  */
	void SetAnio(const int anio);

	/**
	  * @brief Añade un suceso a la fecha
	  * @param un_suceso string que contiene el suceso acontecido
	  * @pre un_suceso debe ser una cadena no vacia
	  */
	void AniadeSuceso(const string un_suceso);

	/**
	  * @brief Elemina un suceso de la fecha
	  * @param indice indice sel suceso a eliminar
	  * @pre indice>=0 y indice<numero de sucesos
	  */
	void EliminaSuceso(const int indice);

	/**
	  * @brief Busca sucesos que contengan una palabra concreta
	  * @param clave palabra clave a buscar en los sucesos
	  * @return Devuelve un vector con los sucesos que contienen la palabra clave
	  */
	Vector_Dinamico<bool> BuscaPalabraClave(const string clave);

	/**
	  * @brief Construye un string con la informacion de la fecha
	  * @return Devuelve el string compuesto por anio y los sucesos
	  * @pre el vector de sucesos no puede ser nulo
	  */
	string toString ();

};




#endif
