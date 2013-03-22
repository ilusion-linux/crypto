#include "funciones.h"

const int Funciones::intAjuste=48;
const int Funciones::intMultiplo=10;

Funciones::Funciones()
{
}
//Funciones publicas----------------------------------------------------
int Funciones::maximoInt(int intEntero)
{
	int intMayor=1;
	int intRetorno=0;
	          
	while(intEntero>=intMayor)
	{
		intMayor*=intMultiplo;
	}
	
	intMayor/=intMultiplo;
	
	intRetorno=intEntero/intMayor;
	
	if(intMayor>1)
	{
		intEntero-=(intMayor*intRetorno);
		int intAux=maximoInt(intEntero);
		
		if(intAux>intRetorno)
		{
			intRetorno=intAux;
		}
	}
	
	return intRetorno;
}
char * Funciones::toCadena(int intEntero)
{
	int intMayor=1;
	int intInicio=1;
	int intContador=1;
	char * strRetorno;
	          
	while(intEntero>=intMayor)
	{
		intMayor*=intMultiplo;
		++intContador;
	}
	
	intMayor/=intMultiplo;
	strRetorno=new char[intContador];
	
	while(intMayor>=intInicio)
	{
		int intAux=intEntero/intMayor;
		intAux+=intAjuste;
			
		char chrTmp[1];
		chrTmp[0]=intAux;
		
		strncat(strRetorno, chrTmp, 1);
		
		intEntero-=(intMayor*(intAux-intAjuste));
		intMayor/=intMultiplo;
	}
	
	return strRetorno;
}
