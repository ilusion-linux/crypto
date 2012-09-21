#ifndef BUSCADOR_H
#define BUSCADOR_H
class Buscador
{
	public:
		Buscador();
		Buscador(char *);
		
	private:
		struct ignorar
		{
			char * extension;
			struct extIgnorar * siguiente;
		};
		
		void leerIgnorados();
		void reiniciarIgnorados();
		void agregarIgnorados(char *);
		void descomponer();
};
#endif
