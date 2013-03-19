#include "funciones.h"

const int Funciones::ajuste=48;
const int Funciones::intMultiplo=10;

Funciones::Funciones()
{
}
//Funciones publicas----------------------------------------------------
int Funciones::maximoInt(int intEntero)
{
	int intMayor=1;
	int retorno=0;
	          
	while(intEntero>=intMayor)
	{
		intMayor*=intMultiplo;
	}
	
	intMayor/=intMultiplo;
	
	intRetorno=intEntero/intMayor;
	
	if(intMayor>1)
	{
		intEntero-=(intMayor*intRetorno);
		int intAux=maximo(intEntero);
		
		if(intAux>intRetorno)
		{
			intRetorno=intAux;
		}
	}
	
	return intRetorno;
}
string Funciones::toString(int intEntero)
{
	int intInicio=1;
	int intMayor=1;
	string strRetorno="";
	          
	while(intEntero>=intMayor)
	{
		intMayor*=intMultiplo;
	}
	
	intMayor/=intMultiplo;
	
	while(intMayor>=intInicio)
	{
		int intAux=intEntero/intMayor;
		intAux+=intAjuste;
			
		char chrTmp=intAux;
		
		strRetorno+=chrTmp;
		
		intEntero-=(intMayor*(intAux-intAjuste));
		intMayor/=intMultiplo;
	}
	
	return strRetorno;
}
char * Funciones::toStringC(int intEntero)
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
