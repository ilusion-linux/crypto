#include <iostream>

using std::cout;
using std::endl;

int estado;

void determinarParametros(char *);

int main(int argC, char * argV[])
{
	estado=0;
	
	for(int x=0; x<argC; x++)
	{
		cout<<argV[x]<<endl;
	}
	
	switch(estado)
	{
		case 0:
		break;
		case 1:
		break;
	}
	
	
	cout<<endl<<endl;
	cout<<"Hola mundo"<<endl;
	return 0;
}

void determinarParametros(char * parametros)
{
	cout<<"Funcion";
}
