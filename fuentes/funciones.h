#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>                                                     //Biblioteca iostream para funciones de entrada y salida estandard
#include <cstring>                                                      //Biblioteca cstring para funciones de manejo de cadenas

using std::string;

class Funciones
{
	public:
		Funciones();
		int maximoInt(int);
		char * toCadena(int);
		template<class T> string toString(T intEntero)
		{
			T intInicio=1;
			T intMayor=1;
			string strRetorno="";
					  
			while(intEntero>=intMayor)
			{
				intMayor*=intMultiplo;
			}
			
			intMayor/=intMultiplo;
			
			while(intMayor>=intInicio)
			{
				T intAux=intEntero/intMayor;
				intAux+=intAjuste;
					
				char chrTmp=intAux;
				
				strRetorno+=chrTmp;
				
				intEntero-=(intMayor*(intAux-intAjuste));
				intMayor/=intMultiplo;
			}
			
			return strRetorno;
		}
		
	private:
		static const int intAjuste;
		static const int intMultiplo;
};
#endif
