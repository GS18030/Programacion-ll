//Deytel cap 24
#include <iostream>
#include <conio.h> 

using namespace std; 
/*ATRIBUTOS---------------------------------------------------*/
class Cola{
	class Nodo {//estructura de la clase
		public: 
		int info;
		Nodo *sig;//recursivo
	};
	Nodo *raiz; //ultimo elemento de la cola 
	Nodo *fondo; //primer elemento en entrar a la cola
	/*-------------------------------------------------------*/

public: 
	Cola();  //constructor 
	~Cola(); //destructor, metodo que destruye la clase
	void insertar (int x);
	int extraer();
	void imprimir (); 
	bool vacia(); 
};

Cola::Cola()
{
	raiz = NULL;
	fondo = NULL;
	}	
	
Cola::~Cola()
{
	Nodo *reco = raiz; 
	Nodo *bor;
	while (reco != NULL)
	{
		bor = reco;
		reco = reco->sig;
		delete bor;
	}
};
//instancear una clase

void Cola::insertar(int x)
{
	Nodo *nuevo; 
	nuevo = new Nodo(); //new: etiquetar que parte pertenece a info y que parte pertenece a siguiente, reservar un espacio, seccionar el dato Nodo
	nuevo -> info = x; 
	nuevo->sig = NULL;
	if (vacia())
	{
		raiz = nuevo;
		fondo = nuevo;
	}
	else 
	{ 
	fondo->sig=nuevo; 
	fondo = nuevo;
	}
}

int Cola::extraer()
{ 
	if (!vacia())
	{
		int informacion = raiz-> info;
		Nodo *bor = raiz; 
		if (raiz == fondo)
		{ 
			raiz = NULL;
			fondo = NULL;
		}
		else 
		{
			raiz = raiz->sig;
		}
		delete bor; 
		return informacion;	 
	}
	else {
		return -1;
	}
	
}

void Cola::imprimir()
{
	Nodo *reco = raiz; 
	cout<<"Listado de los elementos de la cola: "<<endl; 
	while (reco !=NULL)
	{ 
		cout <<reco-> info<< "-";
		reco = reco-> sig; 
	}
}

bool Cola::vacia()
{
	if (raiz==NULL)
	return  true;
	else 
	return false;
};

int main()
{
	Cola* cola1=new Cola();
	cola1->insertar(5);
	cola1->insertar(10); 
	cola1->insertar(50);
	cola1->imprimir();
	cout << "Extraemos uno de la cola: "<<cola1->extraer()<<endl;
	cola1->imprimir();
	delete cola1;	
	cin.get();
	return 0; 
};
