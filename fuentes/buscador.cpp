#include <iostream>
#include "buscador.h"

using std::cout;
using std::endl;

Buscador::Buscador()
{
	ignorados=NULL;
	inicioIgnorados=NULL;
	temporalIgnorados=NULL;
}
//Funciones publicas----------------------------------------------------
void Buscador::agregarIgnorados(char * elementos)
{
	char * chrElementos;
	
	chrElementos=strtok(elementos, ":");
	
	while(chrElementos!=NULL)
	{
		agregarElementoLista(chrElementos);
		chrElementos=strtok(NULL, ":");
	}
	
	/*ignorados=inicioIgnorados;
	while(ignorados!=NULL)
	{
		cout<<(ignorados->extension)<<endl;
		ignorados=ignorados->siguiente;
	}*/
}
//Funciones privadas----------------------------------------------------
void Buscador::leerIgnorados()
{
}

void Buscador::reiniciarIgnorados()
{
}

void Buscador::agregarElementoLista(string ignorado)
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

void Buscador::descomponer()
{
	
}
