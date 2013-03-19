#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstring>

using std::string;

class Funciones
{
	public:
		Funciones();
		int maximoInt(int);
		string toString(int);
		char * toStringC(int);
		
	private:
		static const int intAjuste;
		static const int intMultiplo;
};
#endif
