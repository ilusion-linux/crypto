#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <cstring>

using std::string;

class Buscador
{
	public:
		Buscador();
		void agregarIgnorados(char *);
		
	private:
		struct ignorar
		{
			string extension;
			struct ignorar * siguiente;
		};
		
		struct ignorar * inicioIgnorados;
		struct ignorar * ignorados;
		struct ignorar * temporalIgnorados;
		
		struct directorio
		{
			string directorios;
			struct directorio * siguiente;
		};
		
		struct directorio * inicioDirectorios;
		struct directorio * directorios;
		struct directorio * temporalDirectorios;
		
		void leerIgnorados();
		void reiniciarIgnorados();
		void agregarElementoLista(string);
		void descomponer();
};
#endif
