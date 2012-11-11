#include "ejecucionsimultanea.h"

EjecucionSimultanea::EjecucionSimultanea()
{
	ocupado=false;
	idThread=pthread_self();
}
//Funciones publicas----------------------------------------------------
void EjecucionSimultanea::ejecutarHilo(void *(*funcionGenerica)(void *))
{
	ocupado=true;
	
	pthread_create(&idThread, NULL, funcionGenerica, NULL);
	pthread_join(idThread, NULL);
	
	ocupado=false;
}
pthread_t EjecucionSimultanea::darIdThread()
{
	return idThread;
}
//Funciones privadas----------------------------------------------------
