#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas

using std::string;

class Encriptador
{
	//friend void * encriptar(void *);                                    //Funcion con implementacion logica para encryptar
	//friend void * desencriptar();                                       //Funcion con implementacion logica para desencryptar
	
	public:
		Encriptador(char *, void *, int);                               //Constructor de la clase
		void iniciarProceso();                                          //Funcion para iniciar el trabajo
		
	private:
		int intOperacion;                                               //Almacena la operacion a ejecutar, 0 encriptar, 1 desencriptar
		char * chrPassword;                                             //Recibe el password ingresado
		
		typedef void *(*ptrFuncion)(void *);                            //Puntero para funcion generica
		
		static const int intAjuste;                                     //Variable para ajustar valores que se pasan de los limites
		static const int intTamanio;                                    //Almacena el tamaño en bytes, de una variable tipo int
		static const int intComparador;                                 //Variable para comparar bites, contiene la mascara 1000 0000 0000 0000 que corresponde a 1
		static const int intLimitePositivo;                             //Variable que contiene el limite del diccionario positivio
		static const int intLimiteNegativo;                             //Variable que contiene el limite del diccionario negativo
					
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
		void recorrer(void (*prtFunc)(void * []));				        //Funcion para recorrer los elementos a operar
};
#endif
