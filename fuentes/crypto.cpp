/*
 * crypto
 * Programa encriptador
 * 
 * autor ilusion-linux
 * */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "buscador.h"

using std::cout;
using std::endl;

//Encriptador encriptador;

int intOperacion;/*Variable para almacenar tipo de operacion
	0  encriptar
	1  desencriptar*/
				  
int intDir;/*Variable para identificar si es directorio o documento
	0  directorios
	1  archivos*/
		   
char * chrPassword;//Variable que contiene la contraseña ingresada
char * chrRuta;//Variable que contiene la ruta directorio

void mostarInformacion();
/*
 * Funcion para mostrar caracteristicas del programa, asi como las 
 * diferentes opciones que este permite
 * */

int main(int argC, char * argV[])
{
	intOperacion=-1;/*Variable utilizada para indicar el tipo de
		operacion a realizar*/
	
	Buscador buscador;//Variable tipo clase Buscador
	
	int intEstado=0;/*Variable para analizar si se esta leendo un
		parametro o un valor de parametro*/
	
	char ** chrAuxiliar;/*Variable tipo puntero a puntero, para
		referenciar el valor donde se almacenara algun parametro*/
						
	cout<<"--------------------------------------"<<endl;
	for(int x=1; x<argC; x++)
	{
		switch(intEstado)
		{
			case 0:
				if(strcasecmp(argV[x], "l")==0)
				{
					intEstado=1;
					chrAuxiliar=&chrRuta;
				}
				else if(strcasecmp(argV[x], "p")==0)
				{
					intEstado=1;
					chrAuxiliar=&chrPassword;
				}
				else if(strcasecmp(argV[x], "e")==0)
				{
					intOperacion=0;
				}
				else if(strcasecmp(argV[x], "d")==0)
				{
					intOperacion=1;
				}
				else if(strcasecmp(argV[x], "i")==0)
				{
					x=argC;
					intEstado=-1;
					intOperacion=-1;
					mostarInformacion();
				}
				else if(strcasecmp(argV[x], "h")==0)
				{
					intEstado=2;
				}
				else
				{
					cout<<"Error:"<<endl;
					cout<<"El parametro "<<argV[x]<<" no es un "
					    <<"parametro vaido."<<endl<<endl;
					cout<<"Consulte crypto i, para obtener ayuda"<<endl;
					x=argC;
					intEstado=-1;
					intOperacion=-1;
				}
			break;
			case 1:
				if(strcasecmp(argV[x], "l")==0 || strcasecmp(argV[x],
					"p")==0 || strcasecmp(argV[x], "e")==0 ||
					strcasecmp(argV[x], "d")==0 || strcasecmp(argV[x],
					"i")==0)
				{
					x=argC;
					intEstado=-1;
					intOperacion=-1;
					cout<<"Error en la definicion de los parametros.";
					cout<<endl;
				}
				else
				{
					chrRuta=argV[x];
					intEstado=0;
				}
			break;
			case 2:
				intEstado=0;
				buscador.agregarIgnorados(argV[x]);
			break;
		}
	}
	
	switch(intOperacion)
	{
		case 0:
		
		break;
		case 1:
		
		break;
		default:
			cout<<"No ha indicado si desea encriptar o desencriptar.";
			cout<<endl;
		break;
	}
	
	return 0;
}

void mostarInformacion()
{
	system("more crypto.info");
}
