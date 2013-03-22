#ifndef EJECUCIONSIMULTANEA_H
#define EJECUCIONSIMULTANEA_H
#include <pthread.h>
#include <iostream>                                                     //Biblioteca iostream para funciones de entrada y salida estandard
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas
#include <cstdlib>                                                      //Biblioteca cstdlib para funciones de llamadas al sistema operativo
#include <fstream>                                                      //Biblioteca fstream para funciones de lectura y escritura de archivos
#include "funciones.h"

using std::string;
using std::cout;
using std::endl;
using std::ios;
using std::ofstream;
using std::ifstream;

class EjecucionSimultanea
{
	public:
		EjecucionSimultanea(int);
		void ejecutarHilo(void * par[]);
		
	private:
		
		int intIndice;
		int intOperacion;
		
		Funciones funcion;
		
		static const int intTamanio;   									//Definicion del tamanio de la variable int, segun cada plataforma y sistema operativo
		static const int intComparador;      							//Asignacion del juego de bits del numero 1 a intComparados  1000 0000 0000 0000
		static const int intLimitePositivo;            					//Definicion de limites para el diccionario positivo
		static const int intLimiteNegativo;           					//Definicion de limites para el diccionario negativo
		static const int intAjuste;                    					//Ajuste a aplicar para combinacion que pasen los limites de los diccionarios
		
		struct llaves
		{
			int intLlave;
			struct llaves * siguiente;
		};         														//Para almacenar copia de llaves
		
		typedef void * (*ptrGenerica)(void *);                          //tipo puntero para funcion generica, para usarse en creacion de thread
		
		void iniciar(void * []);                                        //Funcion para iniciar el proceso de encriptacion
		
		//int (EjecucionSimultanea::*accion)(int, int, int, int, struct llaves *);  		//Puntero a funcion que puede almacenar la funcion encriptar o desencriptar
		int encriptar(int, int, int, int, struct llaves *);
		int desencriptar(int, int, int, int, struct llaves *);
		
		static void * ejecutar(void * []);								//Funcion estatica para creacion de thread y llamar al mismo objeto
};
#endif
