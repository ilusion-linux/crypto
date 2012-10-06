#include <iostream>
#include <fstream>
#include "buscador.h"

using std::cout;
using std::endl;
using std::ios;
using std::ofstream;
using std::ifstream;

Buscador::Buscador()                                                    //Inicializacion de estructuras en NULL
{
	ignorados=NULL;
	inicioIgnorados=NULL;
	temporalIgnorados=NULL;
}
//Funciones publicas----------------------------------------------------
void Buscador::agregarIgnorados(char * elementos)
{
	ofstream archivoIgnorados("ignorados.crypto", ios::app);            //Apertura de archivo en modo escritura, de manera concatenada
	char * chrElementos;                                                //Variable para almacenar las diferentes extensiones que seran agregadas al archivo
	chrElementos=strtok(elementos, ":");                                //Funcion que strtok, que separa en token la cadena, tomando como elemento separador :
	
	while(chrElementos!=NULL)                                           //Mientas tengamos extensiones validos
	{
		archivoIgnorados<<chrElementos<<endl;                           //Escritura en archivo, se escribe la extencion y un salto de linea
		chrElementos=strtok(NULL, ":");                                 //Se vuelve a llama a la funcion strtok, para obtener la siguiente extension
	}
	
	archivoIgnorados.close();
	leerIgnorados();
	
}
//Funciones privadas----------------------------------------------------
void Buscador::leerIgnorados()
{
	ifstream archivoIgnorados("ignorados.crypto", ios::in);
	
	string extensiones;
	while(archivoIgnorados>>extensiones)
	{
		if(extensionUnica(extensiones)==true)
		{
			agregarElementoIgnorado(extensiones);
		}
	}
	
	archivoIgnorados.close();
}

void Buscador::agregarElementoIgnorado(string ignorado)
{
	if(ignorados==NULL)
	{
		ignorados=new struct ignorar;
		ignorados->extension=ignorado;
		ignorados->siguiente=NULL;
		
		inicioIgnorados=ignorados;
		temporalIgnorados=ignorados;
	}
	else
	{	
		ignorados=new struct ignorar;
		ignorados->extension=ignorado;
		ignorados->siguiente=NULL;
		
		temporalIgnorados->siguiente=ignorados;
		temporalIgnorados=ignorados;
	}
}

void Buscador::agregarElementoDirectorio(string ignorado)
{
}

bool Buscador::extensionUnica(string ignorado)
{
	temporalIgnorados=inicioIgnorados;
	while(temporalIgnorados!=NULL)
	{
		if(ignorado.compare(temporalIgnorados->extension)==0)
		{
			return false;
		}
		temporalIgnorados=temporalIgnorados->siguiente;
	}
	return true;
}

void Buscador::reiniciarIgnorados()
{
}

void Buscador::descomponer()
{
	
}
