#include <iostream>
#include <cmath>
#include <fstream>
#include "encriptador.h"

using std::cout;
using std::endl;
using std::ios;
using std::ofstream;
using std::ifstream;

const int Encriptador::intTamanio=((sizeof(char)*8)-1);                 //Definicion del tamanio de la variable char, segun cada plataforma y sistema operativo

Encriptador::Encriptador(char * pass, struct Buscador::directorio * dir,
	int operacion)
{
	llaves=NULL;
	temporalLlaves=NULL;
	
	chrPassword=pass;
	generarLlave();
	intOperacion=operacion;
	elementos=(struct directorio *)dir;
	inicioElementos=elementos;
}
//Funciones publicas----------------------------------------------------
void Encriptador::iniciarProceso()
{
	switch(intOperacion)
	{
		case 0:
			encriptar();
		break;
		case 1:
			desencriptar();
		break;
	}
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
	int intRecorrido=0;
	llaves=inicioLlaves;
	
	while(elementos!=NULL)
	{
		char chrLectura;		
		ifstream lectura(elementos->objeto.c_str(), ios::binary);
		string strLectura="temp/buffer"+elementos->objeto;
		
		ofstream escritura(strLectura.c_str(), ios::out);
		
		while(lectura>>chrLectura)
		{
			
			int intEscritura;
			
			if((intRecorrido%2)==0)
			{
				
			}
			else
			{
				
			}
			
			intEscritura=((int)chrLectura)+(llaves->intLlave);
			
			intEscritura=((int)chrLectura)-(llaves->intLlave);
			
			if(intRecorrido==intTamanio)
			{
				intRecorrido=0;
				llaves=llaves->siguiente;
			}
			
			++intRecorrido;
		}
		
		elementos=elementos->siguiente;
	}
}

void Encriptador::desencriptar()
{
	llaves=inicioLlaves;
	
	while(elementos!=NULL)
	{
		
		
		
		elementos=elementos->siguiente;
	}
}

void Encriptador::leer()
{
}

void Encriptador::escribir()
{
}
