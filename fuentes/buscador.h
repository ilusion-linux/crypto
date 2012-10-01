#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <cstring>

using std::string;

class Buscador
{
	public:
		Buscador();//Constructor de la clase
		void agregarIgnorados(char *);/*Funcion para agregar extensiones
			a ignorar*/
		void leerIgnorados();/*Funcion para leer las extensiones
			guardadas, que no seran tomadas en cuenta*/
		
	private:
		struct ignorar
		{
			string extension;
			struct ignorar * siguiente;
		};/*Estructura para almacenar el listado de extensones guardadas
			que seran ignoradas*/
		
		/*Estructutas de ignorar a punteros, para manejar las listas
		  enlzadas*/
		struct ignorar * inicioIgnorados;
		struct ignorar * ignorados;
		struct ignorar * temporalIgnorados;
		
		struct directorio
		{
			string directorios;
			struct directorio * siguiente;
		};/*Esctructura para almacenar los archivos a cifrar o
			decifrar*/
		
		/*Estructutas de directorio a punteros, para manejar las listas
		  enlzadas*/
		struct directorio * inicioDirectorios;
		struct directorio * directorios;
		struct directorio * temporalDirectorios;
		
		bool extensionUnica(string);/**/
		void agregarElementoIgnorado(string);/*Funcion para agregar
			elementos a la lista enlazada de extensiones ignoradas*/
		void agregarElementoDirectorio(string);/*Funcion para agregar
			elementos a la lista enlazada de directorios a cifrar o decifrar*/
		void reiniciarIgnorados();/*Funcion para reiniciar el listado de
			extensiones ignoradas*/
		void descomponer();/*Funcion para buscar recursivamente los
			documentos listados dentro algun directorio indicado*/
};
#endif
