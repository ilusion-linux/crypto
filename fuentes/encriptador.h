#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H

#include <iostream>                                                     //Biblioteca iostream para funciones de entrada y salida estandard
#include <cmath>                                                        //Biblioteca cmath para funciones matematicas
#include "ejecucionsimultanea.h"
#include "funciones.h"

class Encriptador
{	
	public:
		Encriptador(char *, void *, int, int);                          //Constructor de la clase
		void iniciarProceso(int);                                       //Funcion para iniciar el trabajo
		
	private:
		int intOperacion;                                               //Almacena la operacion a ejecutar, 0 encriptar, 1 desencriptar
		int intSimultaneo;												//Almacena las operaciones que se pueden ejecutar simultaneamente
		char * chrPassword;                                             //Recibe el password ingresado
		
		void *** parametro;												//Almacena las diferentes variables que se enviaran al ejecutador
		EjecucionSimultanea ** ejecutar;								//Objeto para procesar la encriptacion o desencriptacion
		
		Funciones funcion;                                              //Objeto con funciones utiles para conversiones
		
		static const int intLimitePositivo;                             //Variable que contiene el limite del diccionario positivio
		static const int intSimultaneoDefault;						    //Almacena las operaciones por default que se pueden ejecutar simultaneamente
					
		struct directorio                                               //Esctructura para almacenar los archivos a cifrar o decifrar
		{
			string objeto;
			int byteArchivo;
			struct directorio * siguiente;
		};
		struct directorio * elementos;
		
		struct llave                                                    //Esctructura para almacenar las llaves generadas
		{
			int intLlave;
			struct llave * siguiente;
		};
		struct llave * llaves;
		struct llave * inicioLlaves;
		struct llave * temporalLlaves;
		
		void generarLlave();                                            //Funcion para generar la llave segun el password ingresada
		void agregarLlave(int);                                         //Funcion para agregar elementos a la lista enlazada de claves generadas
		void recorrer(int);                        				        //Funcion para recorrer los elementos a operar
};
#endif
