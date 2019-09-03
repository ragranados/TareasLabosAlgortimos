#include <iostream>

using namespace std;

/*Escribir un programa que invierta el contenido de una cola
y guarde los multiplos del promedio en otra cola*/

struct Nodo{
	int dato;
	Nodo *sig;
};

class Cola{
	
	private: 
		Nodo *inicio;
		Nodo *fin;
	
	public: 
		Nodo* crearNodo(int valor){
			Nodo *n = new Nodo;
			n-> dato = valor;
			n->sig = nullptr;
			return n;
		}
		
		void mostrarCola(){
			Nodo *temp = inicio;
			if(!inicio){
				cout<<"cola vacia";
				
			}else{
				while(temp){
					cout<<temp->dato<<", ";
					temp = temp -> sig;
				}
			}
		}
		
		void push(int valor){
			Nodo *n = crearNodo(valor);
			
			if(!inicio){
				inicio = n;
				fin = n;
			}else{
				fin -> sig = n;
				fin = n;
			}
		}
		
		void pop(){
			Nodo *temp = inicio;
			
			inicio = inicio -> sig;
			free(temp);
		}
		
		Cola(){
			this -> inicio = nullptr;
			this -> fin = nullptr;
		}
};

int main(){
	
	Cola cola;
	
	cola.push(2);
	cola.push(3);
	
	cola.pop();
	
	cola.mostrarCola();
	
}
