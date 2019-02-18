//José Adolfo Guzmán Solis
//Programación II
//Grupo 02 
//Cadenas con punteros

#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std; 

char cadena[15]; 
char *puntero; 

int main() {
	cout<<"Ingrese texto de cadena: "<<endl; 
	//cin.getline(cadena,15,'\n'); 
	cin>>cadena; 
	//cout<<cadena; 
	for(int i=15 ; i>=0; i--){
		puntero=&cadena[i]; 
		cout<<*puntero; 
	}
	return 0;
}


