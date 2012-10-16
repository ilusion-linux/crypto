#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas
#include "buscador.h"

using std::string;

class Encriptador
{
	public:
	    Encriptador(char *, struct Buscador::directorio *, int);        //Constructor de la clase
		bool iniciarProceso();                                          //Funcion para iniciar el trabajo
		
	private:
		char * chrPassword;
		
		struct directorio                                               //Esctructura para almacenar los archivos a cifrar o decifrar
		{
			string objeto;
			struct directorio * siguiente;
		};
		struct directorio * elementos;
		
		struct llave                                                    //Esctructura para almacenar las llaves generadas
		{
			int intLlave;
			struct llave * siguiente;
		};
		struct llave * llaves;
		struct llave * temporalLlaves;
		struct llave * inicioLlaves;
		
		void generarLlave();                                            //Funcion para generar la llave segun el password ingresada
		void agregarLlave(int);
		void encriptar();                                               //Funcion con implementacion logica para encryptar
		void desencriptar();                                            //Funcion con implementacion logica para desencryptar 
};
#endif
