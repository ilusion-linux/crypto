#include <iostream>                                                     //Biblioteca iostream para funciones de entrada y salida estandard
#include <fstream>                                                      //Biblioteca fstream para funciones de lectura y escritura de archivos
#include <sys/stat.h>                                                   //Biblioteca stat con funciones para obtencion de atributos de directorios y archivos
#include <dirent.h>                                                     //Biblioteca con funciones para manejo de directorios
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
	directorios=NULL;
	inicioDirectorios=NULL;
	temporalDirectorios=NULL;
}
//Funciones publicas----------------------------------------------------
void Buscador::agregarIgnorados(char * elementos)
{
	ofstream archivoIgnorados("ignorados.crypto", ios::app);            
	char * chrElementos;                                                
	chrElementos=strtok(elementos, ":");                                
	
	while(chrElementos!=NULL)                                           
	{
		archivoIgnorados<<chrElementos<<endl;                           
		chrElementos=strtok(NULL, ":");                                 
	}
	
	archivoIgnorados.close();
	leerIgnorados();
	
}

void Buscador::reiniciarIgnorados()
{
	ofstream archivoIgnorados("ignorados.crypto", ios::out);            
	archivoIgnorados.close();
	ignorados=NULL;
	inicioIgnorados=NULL;
	temporalIgnorados=NULL;
}

void Buscador::descomponer(char * elementos)
{
	char * chrElementos;                                                
	chrElementos=strtok(elementos, ":"); 
	
	while(chrElementos!=NULL)                                           
	{
		obtenerDirectorio(chrElementos);
		chrElementos=strtok(NULL, ":");                                 
	}
}

struct Buscador::directorio * Buscador::darElementos()
{
	return inicioDirectorios;
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
	ofstream ignoradosGuardados("ignorados.crypto", ios::out);          
	temporalIgnorados=inicioIgnorados;                                  
	                                                                    
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

void Buscador::agregarElementoDirectorio(string elemento)
{
	if(directorios==NULL)
	{
		directorios=new struct directorio;
		directorios->objeto=elemento;
		directorios->siguiente=NULL;
		
		inicioDirectorios=directorios;
		temporalDirectorios=directorios;
	}
	else
	{
		directorios=new struct directorio;
		directorios->objeto=elemento;
		directorios->siguiente=NULL;
		
		temporalDirectorios->siguiente=directorios;
		temporalDirectorios=directorios;
	}
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

bool Buscador::extensionValida(string obj)
{
	int iPunto=obj.find_last_of(".");
	
	if(iPunto!=string::npos)
	{
		return extensionUnica(obj.substr(iPunto, obj.length()));
	}
	
	return true;
}

void Buscador::obtenerDirectorio(string path)
{
	DIR * dir=opendir(path.c_str());
	
	if(dir)
	{
		struct dirent * listado;
		
		while((listado=readdir(dir))!=NULL)
		{
			char * elemento=listado->d_name;
			
			if(strcmp(elemento, ".")!=0 && strcmp(elemento, "..")!=0)
			{
				struct stat atributos;
				string aux=path+"/"+string(listado->d_name);
				
				if(stat(aux.c_str(), &atributos)==0)
				{
					if(S_ISDIR(atributos.st_mode))
					{
						obtenerDirectorio(aux);
					}
					else
					{
						if(extensionValida(aux)==true)
						{
							cout<<aux<<endl;
							agregarElementoDirectorio(aux);
						}
					}
				}
			}
		}
		
		closedir(dir);
	}
	else
	{
		cout<<"Directorio invalido"<<endl;
	}
}
