#include <iostream>
#include <cstring>
#include "buscador.h"

using std::cout;
using std::endl;

Buscador::Buscador()
{
	
}

Buscador::Buscador(char * archivos)
{
	
}

void Buscador::leerIgnorados()
{
}

void Buscador::reiniciarIgnorados()
{
}

void Buscador::agregarIgnorados(char * ignorados)
{
	char * chrElementos;
	
	chrElementos=strtok(ignorados, ":");
	
	while(chrElementos!=NULL)
	{
		//agregarElementoLista(chrElementos);
		cout<<chrElementos<<endl;
		chrElementos=strtok(NULL, ":");
	}
	
	
	/*string temp="";
	for(int x=0; x<strlen(ignorados); x++)
	{
		if(ignorados[x]=='.')
		{
			agregarElementoLista(temp);
			temp="";
		}
		else
		{
			temp=temp+ignorados[x];
		}
	}*/
}

void Buscador::agregarElementoLista(string ignorado)
{
	
}

void Buscador::descomponer()
{
	
}