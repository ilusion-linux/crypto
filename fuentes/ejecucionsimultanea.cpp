#include "ejecucionsimultanea.h"

const int EjecucionSimultanea::intTamanio=((sizeof(int)*8)-1);   		//Definicion del tamanio de la variable int, segun cada plataforma y sistema operativo
const int EjecucionSimultanea::intComparador=1<<intTamanio;      		//Asignacion del juego de bits del numero 1 a intComparados  1000 0000 0000 0000
const int EjecucionSimultanea::intLimitePositivo=127;            		//Definicion de limites para el diccionario positivo
const int EjecucionSimultanea::intLimiteNegativo=-127;           		//Definicion de limites para el diccionario negativo
const int EjecucionSimultanea::intAjuste=127;                    		//Ajuste a aplicar para combinacion que pasen los limites de los diccionarios

EjecucionSimultanea::EjecucionSimultanea(int operacion)
{
	intOperacion=operacion;
}
//Funciones publicas----------------------------------------------------
void EjecucionSimultanea::ejecutarHilo(void * par[])
{
	pthread_t idThread;
	pthread_create(&idThread, NULL, (ptrGenerica)ejecutar, (void *)par);
}
void * EjecucionSimultanea::ejecutar(void * param[])
{
	EjecucionSimultanea * ejecucion=((EjecucionSimultanea *)(param[4]));
	ejecucion->iniciar(param);
}
//Funciones privadas----------------------------------------------------
void EjecucionSimultanea::iniciar(void * parametros[])
{
	long unsigned int intIdentificador=pthread_self();
	
	cout<<"Inicio -------------- de thread "<<pthread_self()<<endl;
	struct llaves * llaves=(struct llaves *)parametros[0];
	string elemento=*((string *)parametros[1]);
	int byteArchivo=*((int *)parametros[2]);
	string buffer=*((string *)parametros[3]);
	intOperacion=*((int *)parametros[5]);
	
	int intRecorrido=0;                                                 //Variable para controlar los bit recorridos en la secuencia de las llaves
	int intLlaveBinaria=llaves->intLlave;                               //llaveBinaria se  utilizara para recorrer los bit de las llaves generadas
	
	char chrLectura[1];                                                 //Variable para leer archivo con la funcion read
	
	string strLectura=buffer;
	strLectura+=funcion.toString<long unsigned int>(intIdentificador);                     //Buffer donde se comprime el archivo, por el momento es estatico
	
	ifstream lectura(elemento.c_str(), ios::binary);                    //Archivo de lectura, para leer el elemento a encriptar
	ofstream escritura(strLectura.c_str(), ios::out);                   //Archivo de escritura, para escribir en el buffer, el contenido encriptado
	
	int (EjecucionSimultanea::*accion)(int, int, int, int, struct llaves *);
	accion=&EjecucionSimultanea::encriptar;
	
	if(intOperacion==1)
	{
		accion=&EjecucionSimultanea::desencriptar;
	}
	
	while(byteArchivo>0)                                                //Se leen todos los bytes del archivo
	{
		int intEscritura;                                               //Variable para obtener la representacion numero de un char de -188 a 187
		lectura.read(chrLectura, sizeof(chrLectura));                   //Lenctura caracter a caracter, que es lo mismo que decir byte a byte, ya que luego
		int intLectura=(int)chrLectura[0];
		
		intEscritura=(this->*accion)(intLectura, intEscritura,          //Llamada a funcion a puntero a funcion que contenga funcion encryptar o desencriptar
			intRecorrido, intLlaveBinaria, llaves);
		
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
	
	bool * bolEstado=(bool *)parametros[6];
	*bolEstado=false;
	
	cout<<"Finalizando -------------- de thread "<<pthread_self()<<endl;
}
int EjecucionSimultanea::encriptar(int intLectura, int intEscritura,
	int intRecorrido, int intLlaveBinaria, struct llaves * llaves)
{
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
	
	return intEscritura;
}
int EjecucionSimultanea::desencriptar(int intLectura, int intEscritura,
	int intRecorrido, int intLlaveBinaria, struct llaves * llaves)
{
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
	
	return intEscritura;
}
