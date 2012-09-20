#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H
class Encriptador
{
	public:
		Encriptador();
		bool encriptar();
		bool desencriptar();
	private:
		struct directorios
		{
			char * trabajo;
			struct directorios * siguiente;
		};
};
#endif
