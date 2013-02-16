#ifndef EJECUCIONSIMULTANEA_H
#define EJECUCIONSIMULTANEA_H
#include <pthread.h>

class EjecucionSimultanea
{
	public:
		bool ocupado;
		
		EjecucionSimultanea();
		void ejecutarHilo(void *(*funcionGenercia)(void *), void * par[]);
		void ejecutarHilo(void * par[]);
		pthread_t darIdThread();
		
	private:
		const int intTamanio=((sizeof(int)*8)-1);                       //Definicion del tamanio de la variable int, segun cada plataforma y sistema operativo
		const int intComparador=1<<intTamanio;                          //Asignacion del juego de bits del numero 1 a intComparados  1000 0000 0000 0000
		const int intLimitePositivo=127;                                //Definicion de limites para el diccionario positivo
		const int intLimiteNegativo=-127;                               //Definicion de limites para el diccionario negativo
		const int intAjuste=127;                                        //Ajuste a aplicar para combinacion que pasen los limites de los diccionarios
		
		pthread_t idThread;
		
		void encriptar(void * parametros[]);
		void desencriptar(void * parametros[]);
		
		struct llaves{int intLlave;struct llaves * siguiente;};         //Para almacenar copia de llaves
		struct llaves * llaves;
};
#endif
