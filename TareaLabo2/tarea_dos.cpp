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
		
		int promedioCola(){
			Nodo *temp = inicio;
			int suma = 0, datos = 0;
			//int promedio;
			if(!inicio){
				return 0;
				
			}else{
				while(temp){
					suma += temp->dato;
					datos++;
					temp = temp -> sig;
				}
			}
			
			return suma/datos;
		}
		
		int sizeCola(){
			Nodo *temp = inicio;
			int datos = 0;
			
			while(temp){
				temp = temp -> sig;
				datos++;
			}
			
			return datos;
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
		
		int obtenerDatoEnPosicion(int pos){
			Nodo *temp = inicio;
			int i = 0;
			
			while(i != pos && temp){
				temp = temp -> sig;
				i++;
			}
			
			return temp->dato;
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
	Cola cola2;
	
	cola.push(10);
	cola.push(20);
	cola.push(15);
	cola.push(1);
	cola.push(3);
	cola.push(12);
	
	int promedio = cola.promedioCola();
	
	for(int i = 0; i < cola.sizeCola();i++){
		if(cola.obtenerDatoEnPosicion(i) % promedio == 0){
			cola2.push(cola.obtenerDatoEnPosicion(i));
		}
	}
	
	cola2.mostrarCola();
	
}
