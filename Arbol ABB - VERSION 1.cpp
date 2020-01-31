#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izd;

};	

 Nodo *arbol=NULL;
 
	//Prototipos
	void menu();
	Nodo *crearNodo(int n);
	void insertarNodo(Nodo *&arbol, int n);
	void mostrarArbol(Nodo *arbol, int cont);
	bool buscarNodo(Nodo *arbol, int n);
	void preOrden(Nodo *arbol);
	void inOrden(Nodo *arbol);
	void postOrden(Nodo *arbol);
	
	//Programa principal
	int main(){
		menu();
		getch();
		return 0;
	}
	
	//Funcion para crear menu de opciones 
	void menu(){
		int dato, opcion, cont=0;
		bool resp;
		
		do{
			cout<<"\t **Menu arbol ABB **"<<endl;
			cout<<"1. Insertar elemento"<<endl;
			cout<<"2. Mostrar Arbol"<<endl;
			cout<<"3. Buscar Elemento"<<endl;
			cout<<"4. Recorrer el arbol en PreOrden"<<endl;
			cout<<"5. Recorrer el arbol en InOrden"<<endl;
			cout<<"6. Recorrer el arbol en PostOrden"<<endl;
			cout<<"7. Salir"<<endl;
			cout<<"\n\t Opcion: ";
			cin>>opcion;
			
			
			switch(opcion){
				case 1:
					cout<<"\nDigite numero: ";
					cin>>dato;
					insertarNodo(arbol,dato);
					cout<<"\n";
					system("pause");
				break;
				
				case 2:
					cout<<"\nMostrando el arbol completo\n\n";
					mostrarArbol(arbol, cont);
					cout<<"\n";
					system("pause");
				break;
					
				case 3:
					cout<<"\nBuscando elemento en el arbol\n\n";
					cout<<"\nDigite numero: ";
					cin>>dato;
					resp=buscarNodo(arbol, dato);
					if(resp==true)
					      cout<<"\nExiste elemento.. ";
					else
					      cout<<"\n NO existe elemento.. ";
					cout<<"\n\n";
					system("pause");
				break;     
				
				case 4:
					cout<<"\nRecorrido del arbol en PreOrden";
					preOrden(arbol);
					cout<<"\n\n";
					system("pause");
				break;
				
				case 5:
					cout<<"\nRecorrido del arbol en InOrden";
					inOrden(arbol);
					cout<<"\n\n";
					system("pause");
				break;
				
				case 6:
					cout<<"\nRecorrido del arbol en PostOrden";
					postOrden(arbol);
					cout<<"\n\n";
					system("pause");
				break;			
			}
			system("cls");
		}while(opcion !=7);
	}
	
	//Funcion para crear nodo
	Nodo *crearNodo(int n){
		Nodo *nuevo=new Nodo();
		
		if(nuevo != NULL){
			nuevo->dato=n;
			nuevo->der=NULL;
			nuevo->izd=NULL;		
		}
			return 0;
	}
	
	//Funcion para insertar nodo
	void insertarNodo(Nodo *&arbol, int n){
		//arbol vacìo
		if(arbol==NULL){
			Nodo *nuevo= crearNodo(n);
			arbol = nuevo;
		}
	//arbol no vacio, tiene un nodo o màs
	else{
		  Nodo *nuevo=crearNodo(n);
		  int valorRaiz=arbol->dato; //obtenemos el valor de la raiz
		  //aplicando recursividad
		  if(n<valorRaiz)
		            insertarNodo(arbol->izd,n);  //insercion a la izquierda
		  else
		            insertarNodo(arbol->der,n);  //insercion a la derecha
		}
}

    //Funcion para mostrar todos los nodos
    void mostrarArbol(Nodo *arbol, int cont){
    	if(arbol==NULL)
    	      return;
    	else{
    		  mostrarArbol(arbol->izd, cont+1);
    		  for(int i=0; i<cont ; i++)
    		       cout<<" ";
    		   cout<<arbol->dato<<endl;
    		   mostrarArbol(arbol->izd, cont+1);
    	}
}

    //Funcion para buscar nodo en el arbol
    bool buscarNodo(Nodo *arbol, int n){
    	if(arbol==NULL)
    	      return false;
    	else{
    		   if(arbol->dato==n)
    		             return true;
    		    else if(n<arbol->dato)
    		             return buscarNodo(arbol->izd,n);
    		    else
    		             return buscarNodo(arbol->der,n);
    	}
	}
	
	//Funcion para recorrido en profundidad - PreOrden
	void preOrden(Nodo *arbol){
		if(arbol==NULL)
		      return;
		else{
			  cout<<arbol->dato<<"-";
			  preOrden(arbol->izd);
			  preOrden(arbol->der);
		}
}

    //Funcion para recorrido en profundidad - InOrden
	void inOrden(Nodo *arbol){
		if(arbol==NULL)
		      return;
		else{
			  inOrden(arbol->izd);
			  cout<<arbol->dato<<"-";
			  inOrden(arbol->der);
		}
}

    //Funcion para recorrido en profundidad - PostOrden
	void postOrden(Nodo *arbol){
		if(arbol==NULL)
		      return;
		else{
			  postOrden(arbol->izd);
			  postOrden(arbol->der);
			  cout<<arbol->dato<<"-";
			  
		}
}
    		             

