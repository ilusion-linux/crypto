#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas

using std::string;

class Buscador
{
	public:
		Buscador();                                                     //Constructor de la clase
		void agregarIgnorados(char *);                                  //Funcion para agregar extensiones a ignorar
		void leerIgnorados();                                           //Funcion para leer las extensiones guardadas, que no seran tomadas en cuenta
		void reiniciarIgnorados();                                      //Funcion para reiniciar el listado de extensiones ignoradas
		void descomponer(char *);                                       //Funcion para buscar recursivamente los documentos listados dentro algun directorio indicado
		
	private:
		struct ignorar                                                  //Estructura para almacenar el listado de extensones guardadas que seran ignoradas
		{
			string extension;
			struct ignorar * siguiente;
		};
		struct ignorar * inicioIgnorados;                               //Estructutas de ignorar a punteros, para manejar las listas enlzadas
		struct ignorar * ignorados;
		struct ignorar * temporalIgnorados;
		
		struct directorio                                               //Esctructura para almacenar los archivos a cifrar o decifrar
		{
			string objeto;
			struct directorio * siguiente;
		};
		struct directorio * inicioDirectorios;                          //Estructutas de directorio a punteros, para manejar las listas enlzadas
		struct directorio * directorios;
		struct directorio * temporalDirectorios;
		
		bool extensionUnica(string);                                    //Funcion para comprobar que no hay extensiones repetidas
		bool extensionValida(string);									//Funcion para comprobar que el archivo contiene una extension valida
		void agregarElementoIgnorado(string);                           //Funcion para agregar elementos a la lista enlazada de extensiones ignoradas
		void agregarElementoDirectorio(string);                         //Funcion para agregar elementos a la lista enlazada de directorios a cifrar o decifrar
		void obtenerDirectorio(string);                                 //Funcion para obtener el listado de archivos de un directorio
	
	public:
		struct directorio * darElementos();                             //Funcion para obtener los elementos a trabajar
};
#endif
