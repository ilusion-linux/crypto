#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <string>

using std::string;

class Buscador
{
	public:
		Buscador();
		Buscador(char *);
		void agregarIgnorados(char *);
		
	private:
		struct ignorar
		{
			string extension;
			struct extIgnorar * siguiente;
		};
		
		struct ignorar * ignorados;
		
		void leerIgnorados();
		void reiniciarIgnorados();
		void agregarElementoLista(string);
		void descomponer();
};
#endif
