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

EjecucionSimultanea::EjecucionSimultanea(int id)
{
	ocupado=false;
	intIndice=id;
	//idThread=new pthread_t();
	//pthread_self();
}
//Funciones privadas----------------------------------------------------
void EjecucionSimultanea::encriptar(void * parametros[])
{
	cout<<"Inicio de encriptacion"<<endl;
	
	static const int intTamanio=((sizeof(int)*8)-1);                //Definicion del tamanio de la variable int, segun cada plataforma y sistema operativo
	static const int intComparador=1<<intTamanio;                   //Asignacion del juego de bits del numero 1 a intComparados  1000 0000 0000 0000
	static const int intLimitePositivo=127;                         //Definicion de limites para el diccionario positivo
	static const int intLimiteNegativo=-127;                        //Definicion de limites para el diccionario negativo
	static const int intAjuste=127;                                 //Ajuste a aplicar para combinacion que pasen los limites de los diccionarios
	
	struct llaves{int intLlave;struct llaves * siguiente;};         //Para almacenar copia de llaves
	struct llaves * llaves;
	
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
	static const int intTamanio=((sizeof(int)*8)-1);                //Definicion del tamanio de la variable int, segun cada plataforma y sistema operativo
	static const int intComparador=1<<intTamanio;                   //Asignacion del juego de bits del numero 1 a intComparados  1000 0000 0000 0000
	static const int intLimitePositivo=127;                         //Definicion de limites para el diccionario positivo
	static const int intLimiteNegativo=-127;                        //Definicion de limites para el diccionario negativo
	static const int intAjuste=127;                                 //Ajuste a aplicar para combinacion que pasen los limites de los diccionarios
	
	struct llaves{int intLlave;struct llaves * siguiente;};         //Para almacenar copia de llaves
	struct llaves * llaves;
	
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
//Funciones publicas----------------------------------------------------
void EjecucionSimultanea::ejecutarHilo(void *(*funcionGenerica)(void *), void * par[])
{
	ocupado=true;
	
	typedef void *(*ptrGenerica)(void *);                               //Puntero para funcion generica
	
	void (*ptrGen)(void * pa[]);
	//ptrGen=&EjecucionSimultanea::encriptar;
	
	
	//pthread_create(&idThread, NULL, (ptrGenerica)ptrGen, (void *)par);
	//pthread_create(&idThread, NULL, funcionGenerica, (void *)par);
	//pthread_join(idThread, NULL);
	
	ocupado=false;
}
void EjecucionSimultanea::ejecutarHilo(void * par[], pthread_t thread)
{
	ocupado=true;
	
	
	//void *(*ptrGenerica)(void *);                                     //Puntero para funcion generica
	
	//void (*ptrGen)(void * pa[]);
	
	//void (EjecucionSimultanea::*ptrFunGen)(void * gen[]); 
	//ptrFunGen=&EjecucionSimultanea::encriptar;
	
	//ptrGenerica=(ptrGen)ptrFunGen;
	
	
	//pthread_create(&idThread, NULL, (ptrGen)encriptar, (void *)par);
	par[4]=(void *)this;
	
	pthread_create(&thread, NULL, (ptrGenerica)ejecutar, (void *)par);
	
	//pthread_create(&idThread, NULL, funcionGenerica, (void *)par);
	pthread_join(thread, NULL);
	
	cout<<"--"<<ocupado<<"--"<<endl;
	
	//ocupado=false;
}
/*pthread_t EjecucionSimultanea::darIdThread()
{
	//cout<<idThread.p<<endl;
	return idThread[intIndice];
}*/
void * EjecucionSimultanea::ejecutar(void * param[])
{
	//EjecucionSimultanea * ejecucion=((EjecucionSimultanea *)(&param[4]));
	EjecucionSimultanea * ejecucion=((EjecucionSimultanea *)(param[4]));
	string aux=*((string *)param[3]);
	
	cout<<"Hola Mundo"<<pthread_self()<<endl;//<<ejecucion->darIdThread()<<endl;
	
	bool tmp=ejecucion->obtenerEstado();
	if(tmp==true)
	{
		cout<<"True"<<tmp<<endl<<aux<<endl;
	}
	else
	{
		cout<<"False"<<tmp<<endl<<aux<<endl;
	}
	
	for(int x=0; x<10000; x++)
	{
		if((x%100)==0)
		{
			cout<<x<<" ";
		}
	}
	cout<<endl;
	
	ejecucion->establecerEstado(false);
	cout<<"Terminando Hilo"<<endl;
	//pthread_join(pthread_self(), NULL);
	pthread_exit(NULL);
}
void EjecucionSimultanea::establecerEstado(bool valor)
{
	ocupado=valor;
}
bool EjecucionSimultanea::obtenerEstado()
{
	return ocupado;
}	
