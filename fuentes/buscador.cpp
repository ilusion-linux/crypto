#include "buscador.h"

Buscador::Buscador()                                                    //Inicializacion de estructuras en NULL
{
	ignorados=NULL;
	inicioIgnorados=NULL;
	temporalIgnorados=NULL;
	directorios=NULL;
	inicioDirectorios=NULL;
	temporalDirectorios=NULL;
}
//Funciones publicas----------------------------------------------------
void Buscador::agregarIgnorados(char * elementos)                       //Funcnion que recibe como parametro una lista con las diferentes extensiones a agregar
{
	ofstream archivoIgnorados("ignorados.crypto", ios::app);            
	char * chrElementos;                                                
	chrElementos=strtok(elementos, ":");                                //Con la funcion strtok se van a obtener los token de la cadena recibida utilizando
	                                                                    //como caracter separador el caracter ":"
	while(chrElementos!=NULL)                                           
	{
		archivoIgnorados<<chrElementos<<endl;                           //Se procede a guardar una a una las extensiones obtenidas dentro del archivo
		chrElementos=strtok(NULL, ":");                                 //ignorados.crypto
	}
	
	archivoIgnorados.close();
	leerIgnorados();
	
}

void Buscador::reiniciarIgnorados()                                     //Funcion para reiniciar el contenido del archivo ingorados.crypto y resetear
{                                                                       //las listas de la estructura ignorado
	ofstream archivoIgnorados("ignorados.crypto", ios::out);            
	archivoIgnorados.close();
	ignorados=NULL;
	inicioIgnorados=NULL;
	temporalIgnorados=NULL;
}

void Buscador::descomponer(char * elementos)                            //Funcion que recibe como parametro una lista con los directorios que se agregaran
{                                                                       //para trabjar
	char * chrElementos;                                                
	chrElementos=strtok(elementos, ":");                                //Con la funcion strtok se van a obtener los token de la cadena recibida utilizando
	                                                                    //como caracter separador el caracter ":"
	while(chrElementos!=NULL)                                           
	{
		obtenerDirectorio(chrElementos);                                
		chrElementos=strtok(NULL, ":");                                 
	}
}

void * Buscador::darElementos()                                         //Funcion que retorna la direccion inicial de la estructura directorio
{
	return inicioDirectorios;
}

void * Buscador::darIgnorados()
{
	return inicioIgnorados;
}

void Buscador::leerIgnorados()                                          //Funcion para obtener el listado de extensiones guardadas en el archivo
{                                                                       //ignorados.crypto
	ifstream archivoIgnorados("ignorados.crypto", ios::in);             
	string extensiones;                                                 
	
	while(archivoIgnorados>>extensiones)                                //Se recorre el archivo extension por extension y se compara que esta
	{                                                                   //no se encuentre repetida
		if(extensionUnica(extensiones)==true)                           
		{                                                               
			agregarElementoIgnorado(extensiones);
		}
	}
	
	archivoIgnorados.close();
	ofstream ignoradosGuardados("ignorados.crypto", ios::out);          //Se procede a guardar la lista obtenida, dentro del mismo archivo, ya que
	struct ignorar * auxIgnorados=inicioIgnorados;                      //esta no cuenta con ningun elemento repetido
	                                                                    
	while(auxIgnorados!=NULL)
	{
		ignoradosGuardados<<auxIgnorados->extension<<endl;
		auxIgnorados=auxIgnorados->siguiente;
	}
	
	ignoradosGuardados.close();
}

void Buscador::imprimirIgnorados()
{
	leerIgnorados();
	struct ignorar * auxIgnorados=inicioIgnorados;
	
	while(auxIgnorados!=NULL)
	{
		cout<<auxIgnorados->extension<<endl;
		auxIgnorados=auxIgnorados->siguiente;
	}
}
//Funciones privadas----------------------------------------------------
void Buscador::agregarElementoIgnorado(string ignorado)                 //Funcion que recibe un paramatro, que es una extension, para agregarle en su
{                                                                       //repectiva lista enlazada.  Esta funcion gestiona la creacion y enlaze de la
	ignorados=new struct ignorar;                                       //lista dinamica
	ignorados->extension=ignorado;
		
	if(inicioIgnorados==NULL)                                                 
	{
		ignorados->siguiente=NULL;
		
		inicioIgnorados=ignorados;
		temporalIgnorados=ignorados;
	}
	else
	{	
		ignorados->siguiente=NULL;
		
		temporalIgnorados->siguiente=ignorados;
		temporalIgnorados=ignorados;
	}
}

void Buscador::agregarElementoDirectorio(string elemento, int tamanio)  //Funcion que recibe un paramatro, que es una elemento de un directorio, para 
{                                                                       //agregarle en su repectiva lista enlazada.  Esta funcion gestiona la creacion 
	directorios=new struct directorio;                                  //y enlaze de la lista dinamica
	directorios->objeto=elemento;
	directorios->byteArchivo=tamanio;
		
	if(inicioDirectorios==NULL)                                               
	{
		directorios->siguiente=NULL;
		
		inicioDirectorios=directorios;
		temporalDirectorios=directorios;
	}
	else
	{
		directorios->siguiente=NULL;
		
		temporalDirectorios->siguiente=directorios;
		temporalDirectorios=directorios;
	}
}

bool Buscador::extensionUnica(string ignorado)                          //Funcion que recibe un parametro, que es una extension, para determinar si es una
{                                                                       //una extension unica, o ya se encuentra en la lista enlazada
	struct ignorar * auxIgnorados=inicioIgnorados;
	
	while(auxIgnorados!=NULL)
	{
		if(ignorado.compare(auxIgnorados->extension)==0)
		{
			return false;
		}
		
		auxIgnorados=auxIgnorados->siguiente;
	}
	
	return true;
}

bool Buscador::extensionValida(string obj)                              //Funcion que recibe un parametro, que es un elemento del directorio a trabajar
{                                                                       //para determinar que este elemento no contenga una extension de las agregadas
    int iPunto=obj.find_last_of(".");                                   //como extensiones a ignorar
	
	if(iPunto!=string::npos)
	{
		return extensionUnica(obj.substr(iPunto, obj.length()));
	}
	
	return true;
}

void Buscador::obtenerDirectorio(string path)                           //Funcion que recibe un parametro, que es un directorio, y se determinaran todos
{ 
	DIR * dir=opendir(path.c_str());                                    //Se abre el directorio recibido
	
	if(dir)                                                             //Si dir se abrio correctamente
	{
		struct dirent * listado;                                        //Creamos un puntero a la estructura dirent
		
		while((listado=readdir(dir))!=NULL)                             //Recorremos uno a uno los elementos del directorio abierto
		{
			char * elemento=listado->d_name;                            
			
			if(strcmp(elemento, ".")!=0 && strcmp(elemento, "..")!=0)   //Determinados que cada elemento no sean ni "." ni "..", los cuales pertenecen a cada
			{                                                           //directorio de los sistemas UNIX y Linux
				struct stat atributos;                                  //Se crea una estructura tipo stat, para contener informacion sobre cada elemento
				string aux=string(path)+string("/")+string(             
					listado->d_name);                                   //Unimos el directorio con el nombre del elemento, para obtener direcciones completas
				
				if(stat(aux.c_str(), &atributos)==0)                    //Con la funcion stat se obtienen los atributos del elemento del directorio listado
				{
					if(S_ISDIR(atributos.st_mode))                      //Si el elemento es un directo se utiliza la recursividad, para volver a buscar dentro
					{                                                   //del nuevo directorio, llamando a esta misma funcion
						obtenerDirectorio(aux);
					}
					else                                                //Si el elemento listado no es un directorio, se comprueba que no sea un elemento con
					{                                                   //una extension invalida, y se agrega al lista de directorios
						if(extensionValida(aux)==true)
						{
							int numero=atributos.st_size;
							agregarElementoDirectorio(aux, numero);
						}
					}
				}
			}
		}
		
		closedir(dir);
	}
	else
	{
		struct stat atributos;                                  		//Se crea una estructura tipo stat, para contener informacion sobre cada elemento;                                   			//Unimos el directorio con el nombre del elemento, para obtener direcciones completas
	
		if(stat(path.c_str(), &atributos)==0)                    		//Con la funcion stat se obtienen los atributos del elemento del directorio listado
		{
			if(extensionValida(path)==true)
			{
				int numero=atributos.st_size;
				agregarElementoDirectorio(path, numero);
			}
		}
		else
		{
			cout<<"Directorio "<<path<<" es un invalido"<<endl;
		}
	}
}
