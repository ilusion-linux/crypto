#include "encriptador.h"

const int Encriptador::intLimitePositivo=127;
const int Encriptador::intSimultaneoDefault=2;

Encriptador::Encriptador(char * pass, void * dir, int operacion,
	int simultaneo)                                                      
{
	llaves=NULL;                                                        //Inicializacion en NULL de las estructuras para almacenar las llaves
	inicioLlaves=NULL;
	temporalLlaves=NULL;
	
	chrPassword=pass;      
	                                             
	intSimultaneo=simultaneo;
	if(intSimultaneo==0)
	{
		intSimultaneo=intSimultaneoDefault;
	}
	
	generarLlave();
	intOperacion=operacion;
	elementos=(struct directorio *)dir;                                 //Conversin y asignacion de la estructura que contiene los directorios a trabajar
}
//Funciones publicas----------------------------------------------------
void Encriptador::iniciarProceso(int intOperacion)                      //Funcion para iniciar el proceso, ya sea encriptacion y desencriptacion
{
	recorrer(intOperacion);
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
void Encriptador::recorrer(int intOperacion)
{
	int intOperaciones[intSimultaneo];
	int bolEstados[intSimultaneo];
	string buffer[intSimultaneo];
	struct directorio temporal[intSimultaneo];
	
	parametro=new void ** [intSimultaneo];
	ejecutar=new EjecucionSimultanea * [intSimultaneo];
	
	for(int x=0; x<intSimultaneo; x++)
	{
		parametro[x]=new void * [7];
		
		ejecutar[x]=new EjecucionSimultanea(intOperacion);
		
		intOperaciones[x]=intOperacion;
		bolEstados[x]=false;
	}
	
	int intRecorrido=0;	
	llaves=inicioLlaves;
	int intLlaveBinaria=llaves->intLlave;
		
	while(elementos!=NULL)
	{
		if(bolEstados[intRecorrido]==false)
		{
			ejecutar[intRecorrido]=new EjecucionSimultanea(intOperacion);
			
			buffer[intRecorrido]="temp/buffer";
			buffer[intRecorrido]+=funcion.toString<int>(intRecorrido);
			
			temporal[intRecorrido].objeto=elementos->objeto;
			temporal[intRecorrido].byteArchivo=elementos->byteArchivo;
			
			parametro[intRecorrido][0]=(void *)inicioLlaves;
			parametro[intRecorrido][1]=(void *)&temporal[intRecorrido].objeto;
			parametro[intRecorrido][2]=(void *)&temporal[intRecorrido].byteArchivo;
			parametro[intRecorrido][3]=(void *)&buffer[intRecorrido];
			parametro[intRecorrido][4]=(void *)&ejecutar[intRecorrido];
			parametro[intRecorrido][5]=(void *)&intOperaciones[intRecorrido];
			parametro[intRecorrido][6]=(void *)&bolEstados[intRecorrido];
			
			bolEstados[intRecorrido]=true;
			ejecutar[intRecorrido]->ejecutarHilo(parametro[intRecorrido]);
			
			elementos=elementos->siguiente;
		}
		
		++intRecorrido;
		if(intRecorrido==intSimultaneo)
		{
			intRecorrido=0;
		}
	}
	
	intRecorrido=0;
	
	while(intRecorrido<intSimultaneo)
	{
		while(bolEstados[intRecorrido]==true)
		{
			sleep(1);
		}
		
		++intRecorrido;
	}
}
