#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>                                                      //Biblioteca cstdlib para funciones de llamadas al sistema operativo
#include "encriptador.h"

using std::cout;
using std::endl;
using std::ios;
using std::ofstream;
using std::ifstream;

const int Encriptador::intTamanio=((sizeof(int)*8)-1);                  //Definicion del tamanio de la variable char, segun cada plataforma y sistema operativo
const int Encriptador::intComparador=1<<intTamanio;

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
	while(elementos!=NULL)
	{
		cout<<elementos->objeto<<endl;
		elementos=elementos->siguiente;
	}
	elementos=inicioElementos;
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
	cout<<endl<<endl;
}

void Encriptador::agregarLlave(int elemento)
{
	llaves=new struct llave;
	llaves->intLlave=elemento;
	cout<<elemento<<"  |  ";
	
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
		
		while(!lectura.eof())
		{
			int intEscritura;
			lectura.read(chrLectura, sizeof(chrLectura));
			
			if((intRecorrido%2)==0)
			{
				if((intLlaveBinaria && intComparador)==true)
				{
					intEscritura=((int)chrLectura[0])+llaves->intLlave;
					
					if(intEscritura>256)
					{
						intEscritura=intEscritura-256;
					}
				}
				else
				{
					intEscritura=((int)chrLectura[0])-llaves->intLlave;
					
					if(intEscritura<0)
					{
						intEscritura=fabs(intEscritura);
						intEscritura=256-intEscritura;
					}
				}
			}
			else
			{
				if((intLlaveBinaria && intComparador)==true)
				{
					intEscritura=((int)chrLectura[0])-llaves->intLlave;
					
					if(intEscritura<0)
					{
						intEscritura=fabs(intEscritura);
						intEscritura=256-intEscritura;
					}
				}
				else
				{
					intEscritura=((int)chrLectura[0])+llaves->intLlave;
					
					if(intEscritura>256)
					{
						intEscritura=intEscritura-256;
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
		
		while(!lectura.eof())
		{
			int intEscritura;
			lectura.read(chrLectura, sizeof(chrLectura));
			
			if((intRecorrido%2)==0)
			{
				if((intLlaveBinaria && intComparador)==true)
				{
					if((llaves->intLlave)<((int)chrLectura[0]))
					{
						intEscritura=((int)chrLectura[0])-llaves->intLlave;
					}
					else
					{
						intEscritura=llaves->intLlave-((int)chrLectura[0]);
						intEscritura=256-intEscritura;
					}
				}
				else
				{
					if((llaves->intLlave)<((int)chrLectura[0]))
					{
						intEscritura=llaves->intLlave+((int)chrLectura[0]);
					}
					else
					{
						intEscritura=256-((int)chrLectura[0]);
						intEscritura=llaves->intLlave-intEscritura;
					}
				}
			}
			else
			{
				if((intLlaveBinaria && intComparador)==true)
				{
					if((llaves->intLlave)<((int)chrLectura[0]))
					{
						intEscritura=llaves->intLlave+((int)chrLectura[0]);
					}
					else
					{
						intEscritura=256-((int)chrLectura[0]);
						intEscritura=llaves->intLlave-intEscritura;
					}
				}
				else
				{
					if((llaves->intLlave)<((int)chrLectura[0]))
					{
						intEscritura=((int)chrLectura[0])-llaves->intLlave;
					}
					else
					{
						intEscritura=llaves->intLlave-((int)chrLectura[0]);
						intEscritura=256-intEscritura;
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
