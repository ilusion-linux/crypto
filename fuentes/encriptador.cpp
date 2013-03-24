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
	
	elementos=(struct directorio *)dir;                                 //Conversion y asignacion de la estructura que contiene los directorios a trabajar
}
//Funciones publicas----------------------------------------------------
void Encriptador::iniciarProceso(int intOperacion)                      //Funcion para iniciar el proceso, ya sea encriptacion o desencriptacion
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
void Encriptador::recorrer(int intOperacion)                            //Funcion para lanzar los distintos hilos que se encargan de encriptar o desencriptar
{
	string buffer[intSimultaneo];                                       //Buffers de trabajo
	struct directorio temporal[intSimultaneo];                          //Se utiliza una estructura temporal para desferencia la lista enlazada
	bool bolEstados[intSimultaneo];										//Variable para gestionar el estado de cada hilo
																				//False --> sin ejecutarse
																				//True  --> ejecutandose
	
	parametro=new void ** [intSimultaneo];                              //Variable para encapsular las variables anteriores
	
	ejecutar=new EjecucionSimultanea * [intSimultaneo];					//Objeto para lanzar los hilos
	
	for(int x=0; x<intSimultaneo; x++)									//Creacion de los hilos y los parametros  a enviar
	{
		parametro[x]=new void * [7];
		
		ejecutar[x]=new EjecucionSimultanea();
		
		bolEstados[x]=false;
	}
	
	int intRecorrido=0;
	//llaves=inicioLlaves;												//Se va al primer elemento de intLlaveBinaria, para luego recorrecto uno a uno
	//int intLlaveBinaria=llaves->intLlave;                               //ya que cada hilo utiliza una 
		
	while(elementos!=NULL)                                              //Se recorre cada elemento encontrado en los directorio de trabajo
	{
		if(bolEstados[intRecorrido]==false)                             //Se verifica que no se encuentre ejecutandose un hilo determinado para no
		{																//sobreescribir el hilo y matar la ejecucion anterior
			
			buffer[intRecorrido]="temp/buffer";                         //Se establece el directorio temporal utilizado como buffer de trabajo y se le agrega
			buffer[intRecorrido]+=funcion.toString<int>(intRecorrido);	//el indice del hilo que se ejecutara
			
			temporal[intRecorrido].objeto=elementos->objeto;            //Utilizamos estructura temporal para almacenar los datos actuales de la lista enlaza
			temporal[intRecorrido].byteArchivo=elementos->byteArchivo;  //esto para evitar que el siguiente salto modifique las direccion y se altere la referencia
			
			parametro[intRecorrido][0]=(void *)inicioLlaves;            //Empaquetamos todas las variables a utilizar en la variable parametro
			parametro[intRecorrido][1]=(void *)
				&temporal[intRecorrido].objeto;
			parametro[intRecorrido][2]=(void *)
				&temporal[intRecorrido].byteArchivo;
			parametro[intRecorrido][3]=(void *)&buffer[intRecorrido];
			parametro[intRecorrido][4]=(void *)&ejecutar[intRecorrido];
			parametro[intRecorrido][5]=(void *)&intOperacion;
			parametro[intRecorrido][6]=(void *)
				&bolEstados[intRecorrido];
			
			bolEstados[intRecorrido]=true;                              //Cambiamos la bandera a True para indicar que el hilo a iniciado
			
			ejecutar[intRecorrido]->ejecutarHilo(parametro[intRecorrido]);//Se lanza el hilo
			
			elementos=elementos->siguiente;                             //Pasamos al siguiente elemento
		}
		
		++intRecorrido;                                                 //Se aumenta el recorrido par pasar al siguiente hilo
		
		if(intRecorrido==intSimultaneo)                                 //Si el recorrido llega a los hilos que se establecieron simultaneamente el recorrido
		{                                                               //se iniciara nuevamente en 0
			intRecorrido=0;
		}
	}
	
	intRecorrido=0;														//Regresamos el recorrido a 0
	
	while(intRecorrido<intSimultaneo)                                   //Recorremos los hilos en busca de cuales estan aun activos, y por cada hilo activo
	{                                                                   //se procede a realizar una pausa de un segundo cuantas veces sea neceario para que el
		while(bolEstados[intRecorrido]==true)                           //hilo pueda finalizar, esto es asi por cada hilo, ya que cuando el programa termina aun
		{                                                               //se encuentran hilos ejecutandose
			sleep(1);
		}
		
		++intRecorrido;
	}
}
