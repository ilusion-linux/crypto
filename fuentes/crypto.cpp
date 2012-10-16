/*
 * crypto
 * Programa encriptador
 * 
 * autor ilusion-linux
 * email ilusion.linux@gmail.com
 * */
#include <iostream>                                                     //Biblioteca iostream para funciones de entrada y salida estandard
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas
#include <cstdlib>                                                      //Biblioteca cstdlib para funciones de llamadas al sistema operativo
#include "buscador.h"
#include "encriptador.h"

using std::cout;
using std::endl;

void mostarInformacion();                                               //Funcion para mostrar caracteristicas del programa, asi como las diferentes opciones que este permite

int main(int argC, char * argV[])
{
	cout<<"--------------------------------------"<<endl;
	int intOperacion=-1;                                                //Variable para almacenar tipo de operacion= 0  encriptar, 1  desencriptar; tipo de operacion a realizar.
	int intDir;                                                         //Variable para identificar si es directorio o documento= 0  directorios,  1  archivos
	int intEstado=0;                                                    //Variable para analizar si se esta leendo un parametro o un valor de parametro
	int intPassword=0;
	int intExtension=0;
	int intDirectorio=0;
	char * chrPassword;                                                 //Variable que contiene la contraseña ingresada
	char * chrRuta;                                                     //Variable que contiene la ruta directorio
	char * chrExtension;                                                //Variable que contiene extensiones ignoradas
	char ** chrAuxiliar;                                                //Variable tipo puntero a puntero, para referenciar el valor donde se almacenara algun parametro
	
	Buscador buscador;                                                  //Variable tipo clase Buscador
		
	for(int x=1; x<argC; x++)
	{
		if(intEstado==0)
		{
			if(strcasecmp(argV[x], "l")==0)                             //Estado para leer opciones del sistema
			{                                                           //Opcion para definir directorios
				intEstado=1;
				intDirectorio=1;
				chrAuxiliar=&chrRuta;
			}
			else if(strcasecmp(argV[x], "c")==0)                        //Opcion para definir la contraseña de trabajo
			{
				intEstado=1;
				intPassword=1;
				chrAuxiliar=&chrPassword;
			}
			else if(strcasecmp(argV[x], "e")==0)                        //Opcion que indica encriptacion
			{
				intOperacion=0;
			}
			else if(strcasecmp(argV[x], "d")==0)                        //Opcion que indica desencriptacion
			{
				intOperacion=1;
			}
			else if(strcasecmp(argV[x], "x")==0)                        //Opcion para leer las extensiones a ignorar
			{
				buscador.leerIgnorados();
			}
			else if(strcasecmp(argV[x], "h")==0)                        //Opcion para agregar extensiones a ignorar
			{
				intEstado=1;
				intExtension=1;
				chrAuxiliar=&chrExtension;
			}
			else if(strcasecmp(argV[x], "p")==0)                        //Opcion para mostrar las extensiones a ignorar
			{
				cout<<"Listado de extensiones ignoradas:"<<endl;
				buscador.imprimirIgnorados();
			}
			else if(strcasecmp(argV[x], "r")==0)                        //Opcion para reiniciar las extensiones ignoradas
			{
				buscador.reiniciarIgnorados();
			}
			else if(strcasecmp(argV[x], "i")==0)                        //Opcion para mostrar informacion de las opciones del software
			{
				x=argC;
				intEstado=-1;
				intOperacion=-1;
				mostarInformacion();
			}
			else
			{
				x=argC;
				intEstado=-1;
				intOperacion=-1;
				cout<<"Error:"<<endl;
				cout<<"El parametro "<<argV[x]<<" no es un parametro "<<
					"vaido."<<endl<<endl;
				cout<<"Consulte crypto i, para obtener ayuda"<<endl;
			}
		}
		else if(intEstado==1)
		{
			if(strcasecmp(argV[x], "l")==0 || strcasecmp(argV[x], "p")  //Estado para leer valores para las opciones del sistemas
				==0 || strcasecmp(argV[x], "e")==0 || strcasecmp(
				argV[x], "d")==0 || strcasecmp(argV[x], "i")==0)
			{
				x=argC;
				intEstado=-1;
				intOperacion=-1;
				cout<<"Error en la definicion de los parametros."<<endl;
			}
			else
			{
				intEstado=0;
				*chrAuxiliar=argV[x];
			}
		}
	}
	
	cout<<"--------------------------------------"<<endl;
	
	if(intEstado==0)                                                    //Se compara que se encuentre en un estado valido, que se haya asignado su valor
	{                                                                   //correspondiente al ultimo parametro
		if(intExtension==1)                                             //Si se definieron extensiones se agregan al trabajo actual
		{
			buscador.agregarIgnorados(chrExtension);
		}
		
		if(intDirectorio==0)                                            //Se comprueba que se haya definido el directorio de trabajo
		{
			cout<<"Debe establecerse el directorio a trabajar."<<endl;
			
		}
		else if(intPassword==0)                                         //Se comprueba que se definiera el password de trabajo
		{
			cout<<"Debe definir el password que se utilizara para "<<
				"encryptar/desencryptar."<<endl;
		}
		else
		{
			buscador.descomponer(chrRuta);                              //Descomponemos la ruta de trabajo
			
			if(intOperacion==0 || intOperacion==1)                      //Se procede a encryptar o a desencryptar
			{
				//Encriptador encriptador(chrPassword, buscador, intOperacion);
				Encriptador encriptador(chrPassword, buscador.darElementos(), intOperacion);
			}
			else
			{
				cout<<"No ha indicado si desea encriptar o desencri"<<
					"ptar."<<endl;
			}
		}
	}
	else
	{
		cout<<"Error en la definicion de los parametros."<<endl;
	}
	
	return 0;
}

void mostarInformacion()
{
	system("more info.crypto");                                         //Llamada al sistema, para mostrar la informacion del archivo info.crypto
}
