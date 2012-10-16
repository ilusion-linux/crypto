#include <iostream>
#include <cmath>
#include "encriptador.h"

using std::cout;
using std::endl;

Encriptador::Encriptador(char * pass, struct Buscador::directorio * dir,
	int operacion)
{
	llaves=NULL;
	temporalLlaves=NULL;
	
	chrPassword=pass;
	generarLlave();
	elementos=(struct directorio *)dir;
	
	while(elementos!=NULL)
	{
		cout<<elementos->objeto<<endl;
		elementos=elementos->siguiente;
	}
}
//Funciones publicas----------------------------------------------------
bool Encriptador::iniciarProceso()
{
	return true;
}
//Funciones privadas----------------------------------------------------
void Encriptador::generarLlave()
{
	int x=0;
	int tempA=0;
	int tamanio=strlen(chrPassword);
	
	while(x<tamanio)
	{
		tempA=tempA+(((int)chrPassword[x])-((int)chrPassword[++x]));
		cout<<chrPassword[x];
		++x;
	}
	
	x=0;
	int tempB=0;
	int y=tamanio;
	int mitad=tamanio/2;
	
	while(x<=mitad)
	{
		tempB=tempB+(chrPassword[x]-chrPassword[tamanio]);
		++x;
		--tamanio;
	}
	
	agregarLlave(fabs(tempA));
	agregarLlave(fabs(tempB));
	agregarLlave(fabs(tempA)+fabs(tempB));
	agregarLlave(fabs(fabs(tempA)-fabs(tempB)));
	
	/*temporalLlaves=inicioLlaves;
	int aux=0;
	
	while(temporalLlaves!=NULL)
	{
		cout<<temporalLlaves->intLlave<<endl;
		temporalLlaves=temporalLlaves->siguiente;
		++aux;
		if(aux==10)
		{
			temporalLlaves=NULL;
		}
	}*/
}

void Encriptador::agregarLlave(int elemento)
{
	llaves=new struct llave;
	llaves->intLlave=elemento;
	
	if(temporalLlaves==NULL)
	{
		inicioLlaves=llaves;
	}
	else
	{
		temporalLlaves->siguiente=llaves;
	}
	
	llaves->siguiente=inicioLlaves;
	temporalLlaves=llaves;
}

void Encriptador::encriptar()
{
}

void Encriptador::desencriptar()
{
}
