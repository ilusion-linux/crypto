#ifndef EJECUCIONSIMULTANEA_H
#define EJECUCIONSIMULTANEA_H
#include <pthread.h>

class EjecucionSimultanea
{
	public:
		EjecucionSimultanea(int);
		void ejecutarHilo(void * par[]);
		
		void establecerEstado(bool);
		bool obtenerEstado();
		
	private:
		bool ocupado;
		int intIndice;
		pthread_t idThread;
		
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
		struct llaves * llaves;
		
		typedef void * (*ptrGenerica)(void *);                          //tipo puntero para funcion generica, para usarse en creacion de thread
		
		void iniciar(void * []);                                        //Funcion para iniciar el proceso de encriptacion
		
		int (EjecucionSimultanea::*accion)(int, int, int, int);  		//Puntero a funcion que puede almacenar la funcion encriptar o desencriptar
		int encriptar(int, int, int, int);
		int desencriptar(int, int, int, int);
		
		static void * ejecutar(void * []);								//Funcion estatica para creacion de thread y llamar al mismo objeto
};
#endif
