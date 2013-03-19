#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas
#include "ejecucionsimultanea.h"

using std::string;

class Encriptador
{	
	public:
		Encriptador(char *, void *, int, int);                          //Constructor de la clase
		void iniciarProceso(int);                                        //Funcion para iniciar el trabajo
		
	private:
		int intOperacion;                                               //Almacena la operacion a ejecutar, 0 encriptar, 1 desencriptar
		int intSimultaneo;												//Almacena las operaciones que se pueden ejecutar simultaneamente
		char * chrPassword;                                             //Recibe el password ingresado
		void *** parametro;
		EjecucionSimultanea ** ejecutar;
		
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
