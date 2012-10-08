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
void Buscador::reiniciarIgnorados()
{
	ofstream archivoIgnorados("ignorados.crypto", ios::out);            //Apertura de archivo en modo escritura, de manera de vaciado.
	archivoIgnorados.close();
	ignorados=NULL;
	inicioIgnorados=NULL;
	temporalIgnorados=NULL;
}
//Funciones privadas----------------------------------------------------
void Buscador::leerIgnorados()
{
	ifstream archivoIgnorados("ignorados.crypto", ios::in);             //Apertura de archivo en modo lectura
	string extensiones;                                                 //Variable temporal para la lectura de las extensiones
	
	while(archivoIgnorados>>extensiones)
	{
		if(extensionUnica(extensiones)==true)                           //Se compara una a una las extensiones guardadas y si no ha sido ya leida se procede a
		{                                                               //guardar en una lista enlazada
			agregarElementoIgnorado(extensiones);
		}
	}
	
	archivoIgnorados.close();
	ofstream ignoradosGuardados("ignorados.crypto", ios::out);          //Apertura de archivo en modo escritura, de manera de vaciado.
	temporalIgnorados=inicioIgnorados;                                  //Se recorre la lista enalazada creada con las extensiones sin repetir para guardar las
	                                                                    //sin ninguna repetecion en el archivo.
	while(temporalIgnorados!=NULL)
	{
		ignoradosGuardados<<temporalIgnorados->extension<<endl;
		temporalIgnorados=temporalIgnorados->siguiente;
	}
	
	ignoradosGuardados.close();
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
	struct ignorar * auxIgnorados=inicioIgnorados;
	
	while(auxIgnorados!=NULL)
	{
		if(ignorado.compare(auxIgnorados->extension)==0)
		{
			return false;
		}
		
		auxIgnorados=auxIgnorados->siguiente;
	}
	
	return true;
}

void Buscador::descomponer()
{
	
}
