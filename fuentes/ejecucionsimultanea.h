#ifndef EJECUCIONSIMULTANEA_H
#define EJECUCIONSIMULTANEA_H
#include <pthread.h>                                                    //Biblioteca pthread para soporte de thread posix
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
		EjecucionSimultanea();                                          //Constructor de la clase
		void ejecutarHilo(void * par[]);                                //Funcion para lanzar la ejecucion de los hilos
		
	private:
		int intOperacion;												//Variable que contiene la operacion a relaizar
																			//0  --> Encriptar
																			//1  --> Desencriptar
			
		Funciones funcion;												//Objeto con funciones utiles para conversiones
		
		static const int intTamanio;   									//Definicion del tamanio de la variable int, segun cada plataforma y sistema operativo
		static const int intComparador;      							//Asignacion del juego de bits del numero 1 a intComparados  1000 0000 0000 0000
		static const int intLimitePositivo;            					//Definicion de limites para el diccionario positivo
		static const int intLimiteNegativo;           					//Definicion de limites para el diccionario negativo
		static const int intAjuste;                    					//Ajuste a aplicar para combinacion que pasen los limites de los diccionarios
		
		struct llaves
		{
			int intLlave;
			struct llaves * siguiente;
		};         														//Estructura para almacenar copia de llaves
		
		typedef void * (*ptrGenerica)(void *);                          //tipo puntero para funcion generica, para usarse en creacion de thread
		
		void iniciar(void * []);                                        //Funcion para iniciar el proceso de encriptacion
		
		int encriptar(int, int, int, int, struct llaves *);
		int desencriptar(int, int, int, int, struct llaves *);
		
		static void * ejecutar(void * []);								//Funcion estatica para creacion de thread y llamar al mismo objeto
};
#endif
