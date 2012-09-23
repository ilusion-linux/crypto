#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <string>

using std::string;

class Buscador
{
	public:
		Buscador();
		Buscador(char *);
		
	private:
		struct ignorar
		{
			string extension;
			struct extIgnorar * siguiente;
		};
		struct ignorar ignorados;
		
		void leerIgnorados();
		void reiniciarIgnorados();
		void agregarIgnorados(char *);
		void agregarElementoLista(string);
		void descomponer();
};
#endif
