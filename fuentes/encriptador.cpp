#include <iostream>                                                     //Biblioteca iostream para funciones de entrada y salida estandard
#include <cmath>                                                        //Biblioteca cmath para funciones matematicas
#include <fstream>                                                      //Biblioteca fstream para funciones de lectura y escritura de archivos
#include <cstdlib>                                                      //Biblioteca cstdlib para funciones de llamadas al sistema operativo
#include "encriptador.h"

using std::cout;
using std::endl;
using std::ios;
using std::ofstream;
using std::ifstream;

const int Encriptador::intTamanio=((sizeof(int)*8)-1);                  //Definicion del tamanio de la variable int, segun cada plataforma y sistema operativo
const int Encriptador::intComparador=1<<intTamanio;                     //Asignacion del juego de bits del numero 1 a intComparados
const int Encriptador::intLimitePositivo=127;                           //Definicion de limites para el diccionario positivo
const int Encriptador::intLimiteNegativo=-127;                          //Definicion de limites para el diccionario negativo
const int Encriptador::intAjuste=127;                                   //Ajuste a aplicar para combinacion que pasen los limites de los diccionarios

Encriptador::Encriptador(char * pass, struct Buscador::directorio * dir,
	int operacion)                                                      
{
	llaves=NULL;                                                        //Inicializacion en NULL de las estructuras para almacenar las llaves
	inicioLlaves=NULL;
	temporalLlaves=NULL;
	
	chrPassword=pass;                                                   
	generarLlave();
	intOperacion=operacion;
	elementos=(struct directorio *)dir;                                 //Conversin y asignacion de la estructura que contiene los directorios a trabajar
}
//Funciones publicas----------------------------------------------------
void Encriptador::iniciarProceso()                                      //Funcion para iniciar el proceso, ya sea encriptacion y desencriptacion
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
void Encriptador::generarLlave()                                        //Funcion para generar las llaves que se aplicaran, segun el password ingresado
{
	int x=0;
	int tempA=0;
	int tamanio=strlen(chrPassword);
	
	while(x<tamanio)                                                    //Generacion de primera clave, sumando pareja de valores del password
	{
		tempA=tempA+(((int)chrPassword[x])-((int)chrPassword[++x]));
		++x;
	}
	
	x=0;
	int tempB=0;
	int y=tamanio;
	int mitad=tamanio/2;
	
	while(x<=mitad)                                                     //Generacion de segunda clave, sumando extremos del password
	{
		tempB=tempB+(chrPassword[x]-chrPassword[tamanio]);
		++x;
		--tamanio;
	}
	
	agregarLlave(fabs(tempA));                                          //Agregando claves a la lista enlazada
	agregarLlave(fabs(tempB));
	agregarLlave(fabs(tempA)+fabs(tempB));
	agregarLlave(fabs(fabs(tempA)-fabs(tempB)));
	
	llaves=inicioLlaves;
	temporalLlaves=inicioLlaves;
	
	while(llaves->siguiente!=temporalLlaves)                            //Asegurandose de que las claves generadas no son mayores, al limite positivo del
	{                                                                   //diccionario
		while(llaves->intLlave>intLimitePositivo)
		{
			llaves->intLlave=llaves->intLlave-llaves->intLlave;
		}
		
		llaves=llaves->siguiente;
	}
}

void Encriptador::agregarLlave(int elemento)                            //Funcion que recibe un paramatro, que es una clave, para agregarle en su
{                                                                       //repectiva lista enlazada.  Esta funcion gestiona la creacion y enlaze de la
	llaves=new struct llave;                                            //lista dinamica
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
	int intLlaveBinaria=llaves->intLlave;
	
	while(elementos!=NULL)
	{
		char chrLectura[1];
		string strLectura="temp/bufferA.crypto";
		ifstream lectura(elementos->objeto.c_str(), ios::binary);
		ofstream escritura(strLectura.c_str(), ios::out);
		
		while(elementos->byteArchivo>0)
		{
			int intEscritura;
			lectura.read(chrLectura, sizeof(chrLectura));
			int intLectura=(int)chrLectura[0];
			
			if(intLectura==-128)
			{
				intEscritura=-128;
			}
			else
			{
				if((intRecorrido%2)==0)
				{
					if((intLlaveBinaria && intComparador)==true)
					{
						intEscritura=intLectura+llaves->intLlave;
						
						if(intLectura==127)
						{
							intEscritura=intLectura;
						}
						else if(intEscritura>=intLimitePositivo)
						{
							intEscritura=intLectura-intAjuste;
							intEscritura=intEscritura-intAjuste;
							intEscritura=intEscritura+llaves->intLlave;
						}
					}
					else
					{
						intEscritura=intLectura-llaves->intLlave;
						
						if(intLectura==-127)
						{
							intEscritura=intLectura;
						}
						else if(intEscritura<=intLimiteNegativo)
						{
							intEscritura=intLectura+intAjuste;
							intEscritura=intEscritura+intAjuste;
							intEscritura=intEscritura-llaves->intLlave;
						}
					}
				}
				else
				{
					if((intLlaveBinaria && intComparador)==true)
					{
						intEscritura=intLectura-llaves->intLlave;
						
						if(intLectura==-127)
						{
							intEscritura=intLectura;
						}
						else if(intEscritura<=intLimiteNegativo)
						{
							intEscritura=intLectura+intAjuste;
							intEscritura=intEscritura+intAjuste;
							intEscritura=intEscritura-llaves->intLlave;
						}
					}
					else
					{
						intEscritura=intLectura+llaves->intLlave;
						
						if(intLectura==127)
						{
							intEscritura=intLectura;
						}
						else if(intEscritura>=intLimitePositivo)
						{
							intEscritura=intLectura-intAjuste;
							intEscritura=intEscritura-intAjuste;
							intEscritura=intEscritura+llaves->intLlave;
						}
					}
				}
			}
			
			escritura<<((char)intEscritura);
			
			if(intRecorrido==intTamanio)
			{
				intRecorrido=0;
				llaves=llaves->siguiente;
				intLlaveBinaria=llaves->intLlave;
			}
			else
			{
				intLlaveBinaria<<=1;
				++intRecorrido;
			}
			
			--elementos->byteArchivo;
		}
		
		lectura.close();
		escritura.close();
		
		string copy=string("cp \"")+strLectura+string("\" \"")+
			elementos->objeto+string("\"");
		system(copy.c_str());
		
		elementos=elementos->siguiente;
	}
}

void Encriptador::desencriptar()
{
	int intRecorrido=0;
	llaves=inicioLlaves;
	int intLlaveBinaria=llaves->intLlave;
	
	while(elementos!=NULL)
	{
		char chrLectura[1];
		string strLectura="temp/bufferA.crypto";
		ifstream lectura(elementos->objeto.c_str(), ios::binary);
		ofstream escritura(strLectura.c_str(), ios::out);
		
		while(elementos->byteArchivo>0)
		{
			int intEscritura;
			lectura.read(chrLectura, sizeof(chrLectura));
			int intLectura=(int)chrLectura[0];
			
			if(intLectura==-128)
			{
				intEscritura=-128;
			}
			else
			{		
				if((intRecorrido%2)==0)
				{
					if((intLlaveBinaria && intComparador)==true)
					{
						intEscritura=intLectura-llaves->intLlave;
						
						if(intLectura==127)
						{
							intEscritura=intLectura;
						}
						else if(intEscritura<intLimiteNegativo)
						{
							intEscritura=intEscritura+intAjuste;
							intEscritura=intEscritura+intAjuste;
						}
					}
					else
					{
						intEscritura=intLectura+llaves->intLlave;
						
						if(intLectura==-127)
						{
							intEscritura=intLectura;
						}
						else if(intEscritura>intLimitePositivo)
						{
							intEscritura=intEscritura-intAjuste;
							intEscritura=intEscritura-intAjuste;
						}
					}
				}
				else
				{
					if((intLlaveBinaria && intComparador)==true)
					{
						intEscritura=intLectura+llaves->intLlave;
						
						if(intLectura==-127)
						{
							intEscritura=intLectura;
						}
						else if(intEscritura>intLimitePositivo)
						{
							intEscritura=intEscritura-intAjuste;
							intEscritura=intEscritura-intAjuste;
						}
					}
					else
					{
						intEscritura=intLectura-llaves->intLlave;
						
						if(intLectura==127)
						{
							intEscritura=intLectura;
						}
						else if(intEscritura<intLimiteNegativo)
						{
							intEscritura=intEscritura+intAjuste;
							intEscritura=intEscritura+intAjuste;
						}
					}
				}
			}
					
			escritura<<((char)intEscritura);
			
			if(intRecorrido==intTamanio)
			{
				intRecorrido=0;
				llaves=llaves->siguiente;
				intLlaveBinaria=llaves->intLlave;
			}
			else
			{
				intLlaveBinaria<<=1;
				++intRecorrido;
			}
			
			--elementos->byteArchivo;
		}
		
		lectura.close();
		escritura.close();
		
		string copy=string("cp \"")+strLectura+string("\" \"")+
			elementos->objeto+string("\"");
		system(copy.c_str());
		
		elementos=elementos->siguiente;
	}
}

void Encriptador::leer()
{
}

void Encriptador::escribir()
{
}
