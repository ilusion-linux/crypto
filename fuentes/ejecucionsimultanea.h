#ifndef EJECUCIONSIMULTANEA_H
#define EJECUCIONSIMULTANEA_H
#include <pthread.h>

class EjecucionSimultanea
{
	public:
		bool ocupado;
	
		EjecucionSimultanea();
		void ejecutarHilo(void *(*funcionGenercia)(void *));
		pthread_t darIdThread();
		
	private:
		pthread_t idThread;
};
#endif
