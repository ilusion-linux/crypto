#ifndef EJECUCIONSIMULTANEA_H
#define EJECUCIONSIMULTANEA_H
#include <pthread.h>

class EjecucionSimultanea
{
	public:
		
		
		EjecucionSimultanea(int);
		void ejecutarHilo(void *(*funcionGenercia)(void *), void * par[]);
		void ejecutarHilo(void * par[], pthread_t);
		
		void establecerEstado(bool);
		bool obtenerEstado();
		//pthread_t darIdThread();
		
	private:
		
		//typedef void (*ptrGenerica)(void * []);                           //Puntero para funcion generica
		//typedef void *(*ptrGenerica)(void *);                           //Puntero para funcion generica
		                                   //Puntero para funcion generica
		//ptrGenerica ptrFunGen;                                          //Puntero para funcion generica
		
		int intIndice;
		bool ocupado;
		
		typedef void * (*ptrGenerica)(void *);                          //Puntero para funcion generica
		
		
		
		void encriptar(void * parametros[]);
		void desencriptar(void * parametros[]);
		
		static void * ejecutar(void * []);
		
};
#endif
