#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas
#include "buscador.h"

using std::string;

class Encriptador
{
	public:
		Encriptador(char *, struct Buscador::directorio *, int);        //Constructor de la clase
		void iniciarProceso();                                          //Funcion para iniciar el trabajo
		
	private:
		int intOperacion;
		char * chrPassword;
		static const int intTamanio;
		static const int intComparador;
		static const int intLimitePositivo;
		static const int intLimiteNegativo;
		static const int intAjuste;
					
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
		struct llave * temporalLlaves;
		struct llave * inicioLlaves;
		
		void generarLlave();                                            //Funcion para generar la llave segun el password ingresada
		void agregarLlave(int);
		void encriptar();                                               //Funcion con implementacion logica para encryptar
		void desencriptar();                                            //Funcion con implementacion logica para desencryptar 
		void leer();                                                    //Funcion para leer los archimos en modo binario
		void escribir();                                                //Funcion para escribir los datos en modo binario
};
#endif
