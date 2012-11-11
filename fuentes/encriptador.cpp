#include <iostream>                                                     //Biblioteca iostream para funciones de entrada y salida estandard
#include <cmath>                                                        //Biblioteca cmath para funciones matematicas
#include <fstream>                                                      //Biblioteca fstream para funciones de lectura y escritura de archivos
#include <cstdlib>                                                      //Biblioteca cstdlib para funciones de llamadas al sistema operativo
#include "encriptador.h"
#include "ejecucionsimultanea.h"

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

Encriptador::Encriptador(char * pass, void * dir, int operacion)                                                      
{
	llaves=NULL;                                                        //Inicializacion en NULL de las estructuras para almacenar las llaves
	inicioLlaves=NULL;
	temporalLlaves=NULL;
	
	chrPassword=pass;                                                   
	generarLlave();
	intOperacion=operacion;
	elementos=(struct directorio *)dir;                                 //Conversin y asignacion de la estructura que contiene los directorios a trabajar
}
//Funciones amigas------------------------------------------------------
void encriptar(void * parametros[])
{
	struct llaves{int intLlave;struct llaves * siguiente;};               //Para almacenar copia de llaves
	struct llaves * llaves;
	
	llaves=(struct llaves *)parametros[0];
	string elemento=*((string *)parametros[1]);
	
	char chrLectura[1];                                                 //Variable para leer archivo con la funcion read
	string strLectura="temp/bufferA.crypto";                            //Buffer donde se comprime el archivo, por el momento es estatico
	ifstream lectura(elemento.c_str(), ios::binary);                    //Archivo de lectura, para leer el elemento a encriptar
	ofstream escritura(strLectura.c_str(), ios::out);                   //Archivo de escritura, para escribir en el buffer, el contenido encriptado
	
	cout<<elemento.c_str()<<endl;
}
/*void * encriptar(void * lista)                                          //Funcion para manejar la encriptacion de los archivos
{
	int intRecorrido=0;                                                 //Variable para controlar los bit recorridos en la secuencia de las llaves
	llaves=inicioLlaves;                                                
	int intLlaveBinaria=llaves->intLlave;                               //llaveBinaria se  utilizara para recorrer los bit de las llaves generadas
	
	while(elementos!=NULL)                                              //Se recorre elemento a elmentos que se procedera a encriptar
	{
		char chrLectura[1];                                             //Variable para leer archivo con la funcion read
		string strLectura="temp/bufferA.crypto";                        //Buffer donde se comprime el archivo, por el momento es estatico
		ifstream lectura(elementos->objeto.c_str(), ios::binary);       //Archivo de lectura, para leer el elemento a encriptar
		ofstream escritura(strLectura.c_str(), ios::out);               //Archivo de escritura, para escribir en el buffer, el contenido encriptado
		
		while(elementos->byteArchivo>0)                                 //Se leen todos los bytes del archivo
		{
			int intEscritura;                                           //Variable para obtener la representacion numero de un char de -188 a 187
			lectura.read(chrLectura, sizeof(chrLectura));               //Lenctura caracter a caracter, que es lo mismo que decir byte a byte, ya que luego
			int intLectura=(int)chrLectura[0];                          //se hace la respectiva conversion
			
			if(intLectura==-128)                                        //el byte -128 no se encripta
			{
				intEscritura=intLectura;
			}
			else                                                        //el resto se procede a evaluar, para su comprension
			{
				if((intRecorrido%2)==0)                                 //Si el byte recorrido es un byte par, se procede a operar, al entncotrar un bit 1
				{                                                       //se realiza una suma al encontra un bit 0 se realiza suma
					if((intLlaveBinaria & intComparador)==true)
					{
						if(intLectura==127)                             //En estado de suma tambien se enmascara el byte 127
						{
							intEscritura=intLectura;
						}
						else 
						{
							intEscritura=intLectura+llaves->intLlave;   //Al byte leido se le suma la clave actual
							
							if(intEscritura>=intLimitePositivo)         //Se compara que el nuevo valor obtenido no sobre pase el limite positivo
							{
								intEscritura=intLectura-intAjuste;      //Si es asi se procede a realizar la siguiente mascara, al byte leido se le resta
								intEscritura-=intAjuste;                //el ajuste, y luego a este resultado se vuelve a restar, para luego sumarle
								intEscritura+=llaves->intLlave;         //la llave actual
							}
						}
					}
					else
					{
						if(intLectura==-127)                            //En estado de suma tambien se enmascara el byte -127
						{
							intEscritura=intLectura;
						}
						else 
						{
							intEscritura=intLectura-llaves->intLlave;
							
							if(intEscritura<=intLimiteNegativo)		    //Se compara que el nuevo valor obtenido no sobre pase el limite negativo
							{
								intEscritura=intLectura+intAjuste;      //Si es asi se procede a realizar la siguiente mascara, al byte leido se le suma
								intEscritura+=intAjuste;                //el ajuste, y luego a este resultado se vuelve a sumar, para luego restarle
								intEscritura-=llaves->intLlave;         //la llave actual
							}
						}
					}
				}
				else                                                    //En caso contrario, si el byte es impar, se procede a operar al encontrar un bit 0
				{                                                       //se realiza una suma, al encontrar un bit 1 se realiza una resta
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
			
			escritura<<((char)intEscritura);                            //Se procede a escribir en el buffer el byte ya cifrado
			
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

void * desencriptar(void * lista)
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
			
			--elementos->byteArchivo;
		}
		
		lectura.close();
		escritura.close();
		
		string copy=string("cp \"")+strLectura+string("\" \"")+
			elementos->objeto+string("\"");
		system(copy.c_str());
		
		elementos=elementos->siguiente;
	}
}*/
//Funciones publicas----------------------------------------------------
void Encriptador::iniciarProceso()                                      //Funcion para iniciar el proceso, ya sea encriptacion y desencriptacion
{
	/*EjecucionSimultanea ejecutar;
	cout<<"Id de hilo: "<<ejecutar.darIdThread()<<endl;
	
	void *(*ptrFunc)(void*);
	ptrFunc=leera;
	ejecutar.ejecutarHilo(ptrFunc);
	
	ptrLeer=&Encriptador::leer;
	ptrLeer=&leera;
	(this->*ptrLeer)(NULL);
	
	typedef void *(*gene)(void *);
	
	ejecutar.ejecutarHilo((gene)&ptrLeer);
	ejecutar.ejecutarHilo(ptrLeer);
	
	
	EjecucionSimultanea ejecutar2;
	
	ptrLeer2=&Encriptador::leer;
	
	cout<<"Id de hilo: "<<ejecutar2.darIdThread()<<endl;
	ptrLeer=(gene)&ptrLeer2;
	ejecutar2.ejecutarHilo(ptrLeer);
	
	ejecutar2.ejecutarHilo(leer);*/
	
	void * parametro[2];
	string temp="Hola mundo";
	parametro[0]=(void *)inicioLlaves;
	parametro[1]=(void *)&temp;
	encriptar(parametro);
	
	
	switch(intOperacion)
	{
		case 0:
			/* 
			 * encriptar();
			 * */
		break; 
		case 1:
			//desencriptar();
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
void Encriptador::recorrer(void (*ptrFuncion)(void * parm[]))
{
	int intRecorrido=0;
	llaves=inicioLlaves;
	int intLlaveBinaria=llaves->intLlave;
	
	void * parametro[3];
	parametro[0]=(void *)inicioLlaves;
	
	while(elementos!=NULL)
	{
		parametro[1]=(void *)&elementos->objeto;
		
		
		elementos=elementos->siguiente;
	}
}
