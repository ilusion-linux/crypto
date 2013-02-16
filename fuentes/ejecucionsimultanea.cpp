#include "ejecucionsimultanea.h"
#include <iostream>                                                     //Biblioteca iostream para funciones de entrada y salida estandard
#include <fstream>                                                      //Biblioteca fstream para funciones de lectura y escritura de archivos
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas
#include <cstdlib>                                                      //Biblioteca cstdlib para funciones de llamadas al sistema operativo

using std::string;
using std::cout;
using std::endl;
using std::ios;
using std::ofstream;
using std::ifstream;

EjecucionSimultanea::EjecucionSimultanea()
{
	ocupado=false;
	idThread=pthread_self();
}
//Funciones publicas----------------------------------------------------
void EjecucionSimultanea::ejecutarHilo(void *(*funcionGenerica)(void *), void * par[])
{
	ocupado=true;
	
	typedef void *(*ptrGenerica)(void *);                               //Puntero para funcion generica
	
	void (*ptrGen)(void * pa[]);
	ptrGen=&EjecucionSimultanea::encriptar;
	
	
	//pthread_create(&idThread, NULL, (ptrGenerica)ptrGen, (void *)par);
	//pthread_create(&idThread, NULL, funcionGenerica, (void *)par);
	//pthread_join(idThread, NULL);
	
	ocupado=false;
}
pthread_t EjecucionSimultanea::darIdThread()
{
	//cout<<idThread.p<<endl;
	return idThread;
}
//Funciones privadas----------------------------------------------------
void EjecucionSimultanea::encriptar(void * parametros[])
{
	llaves=(struct llaves *)parametros[0];
	string elemento=*((string *)parametros[1]);
	int byteArchivo=*((int *)parametros[2]);
	string buffer=*((string *)parametros[3]);
	
	cout<<"-----Encriptando Archivo "<<elemento<<endl;
	
	int intRecorrido=0;                                                 //Variable para controlar los bit recorridos en la secuencia de las llaves
	int intLlaveBinaria=llaves->intLlave;                               //llaveBinaria se  utilizara para recorrer los bit de las llaves generadas
	
	char chrLectura[1];                                                 //Variable para leer archivo con la funcion read
	//string strLectura="temp/bufferA.crypto";                            //Buffer donde se comprime el archivo, por el momento es estatico
	string strLectura=buffer;                                           //Buffer donde se comprime el archivo, por el momento es estatico
	ifstream lectura(elemento.c_str(), ios::binary);                    //Archivo de lectura, para leer el elemento a encriptar
	ofstream escritura(strLectura.c_str(), ios::out);                   //Archivo de escritura, para escribir en el buffer, el contenido encriptado
	
	while(byteArchivo>0)                                                //Se leen todos los bytes del archivo
	{
		int intEscritura;                                               //Variable para obtener la representacion numero de un char de -188 a 187
		lectura.read(chrLectura, sizeof(chrLectura));                   //Lenctura caracter a caracter, que es lo mismo que decir byte a byte, ya que luego
		int intLectura=(int)chrLectura[0];                              //se hace la respectiva conversion
		
		if(intLectura==-128)                                            //el byte -128 no se encripta
		{
			intEscritura=intLectura;
		}
		else                                                            //el resto se procede a evaluar, para su comprension
		{
			if((intRecorrido%2)==0)                                     //Si el byte recorrido es un byte par, se procede a operar, al entncotrar un bit 1
			{                                                           //se realiza una suma al encontra un bit 0 se realiza suma
				if((intLlaveBinaria & intComparador)==true)
				{
					if(intLectura==127)                                 //En estado de suma tambien se enmascara el byte 127
					{
						intEscritura=intLectura;
					}
					else 
					{
						intEscritura=intLectura+llaves->intLlave;       //Al byte leido se le suma la clave actual
						
						if(intEscritura>=intLimitePositivo)             //Se compara que el nuevo valor obtenido no sobre pase el limite positivo
						{
							intEscritura=intLectura-intAjuste;          //Si es asi se procede a realizar la siguiente mascara, al byte leido se le resta
							intEscritura-=intAjuste;                    //el ajuste, y luego a este resultado se vuelve a restar, para luego sumarle
							intEscritura+=llaves->intLlave;             //la llave actual
						}
					}
				}
				else
				{
					if(intLectura==-127)                                //En estado de suma tambien se enmascara el byte -127
					{
						intEscritura=intLectura;
					}
					else 
					{
						intEscritura=intLectura-llaves->intLlave;
						
						if(intEscritura<=intLimiteNegativo)		        //Se compara que el nuevo valor obtenido no sobre pase el limite negativo
						{
							intEscritura=intLectura+intAjuste;          //Si es asi se procede a realizar la siguiente mascara, al byte leido se le suma
							intEscritura+=intAjuste;                    //el ajuste, y luego a este resultado se vuelve a sumar, para luego restarle
							intEscritura-=llaves->intLlave;             //la llave actual
						}
					}
				}
			}
			else                                                        //En caso contrario, si el byte es impar, se procede a operar al encontrar un bit 0
			{                                                           //se realiza una suma, al encontrar un bit 1 se realiza una resta
				if((intLlaveBinaria & intComparador)==true)
				{
					intEscritura=intLectura-llaves->intLlave;
					
					if(intLectura==-127)
					{
						intEscritura=intLectura;
					}
					else if(intEscritura<=intLimiteNegativo)
					{
						intEscritura=intLectura+intAjuste;
						intEscritura+=intAjuste;
						intEscritura-=llaves->intLlave;
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
						intEscritura-=intAjuste;
						intEscritura+=llaves->intLlave;
					}
				}
			}
		}
		
		escritura<<((char)intEscritura);                                //Se procede a escribir en el buffer el byte ya cifrado
		
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
		
		--byteArchivo;
	}
	
	lectura.close();
	escritura.close();
	
	string copy=string("cp \"")+strLectura+string("\" \"")+elemento+
		string("\"");
	system(copy.c_str());
	cout<<"-----Fin Encriptado"<<endl;
}
void EjecucionSimultanea::desencriptar(void * parametros[])
{
	llaves=(struct llaves *)parametros[0];
	string elemento=*((string *)parametros[1]);
	int byteArchivo=*((int *)parametros[2]);
	
	int intRecorrido=0;                                                 //Variable para controlar los bit recorridos en la secuencia de las llaves
	int intLlaveBinaria=llaves->intLlave;                               //llaveBinaria se  utilizara para recorrer los bit de las llaves generadas
	
	char chrLectura[1];
	string strLectura="temp/bufferA.crypto";
	ifstream lectura(elemento.c_str(), ios::binary);
	ofstream escritura(strLectura.c_str(), ios::out);
	
	while(byteArchivo>0)
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
				if((intLlaveBinaria & intComparador)==true)
				{
					if(intLectura==127)
					{
						intEscritura=intLectura;
					}
					else
					{
						intEscritura=intLectura-llaves->intLlave;
						
						if(intEscritura<intLimiteNegativo)
						{
							intEscritura+=intAjuste;
							intEscritura+=intAjuste;
						}
					}
				}
				else
				{
					if(intLectura==-127)
					{
						intEscritura=intLectura;
					}
					else
					{
						intEscritura=intLectura+llaves->intLlave;
						
						if(intEscritura>intLimitePositivo)
						{
							intEscritura-=intAjuste;
							intEscritura-=intAjuste;
						}
					}
				}
			}
			else
			{
				if((intLlaveBinaria & intComparador)==true)
				{
					if(intLectura==-127)
					{
						intEscritura=intLectura;
					}
					else
					{
						intEscritura=intLectura+llaves->intLlave;
						
						if(intEscritura>intLimitePositivo)
						{
							intEscritura-=intAjuste;
							intEscritura-=intAjuste;
						}
					}
				}
				else
				{
					if(intLectura==127)
					{
						intEscritura=intLectura;
					}
					else
					{
						intEscritura=intLectura-llaves->intLlave;
						
						if(intEscritura<intLimiteNegativo)
						{
							intEscritura+=intAjuste;
							intEscritura+=intAjuste;
						}
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
		
		--byteArchivo;
	}
	
	lectura.close();
	escritura.close();
	
	string copy=string("cp \"")+strLectura+string("\" \"")+elemento+
		string("\"");
	system(copy.c_str());
}
