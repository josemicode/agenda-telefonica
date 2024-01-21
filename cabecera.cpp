#include<iostream>
#include "cabecera.h"

#define MAX 200

using namespace std;

	void nuevoElemento(registro agenda[], int n){
		cout << "Introduzca... " << endl;
		
		cout << "DNI: ";
		cin >> agenda[n].DNI;
		
		cout << "Apellidos: ";
		cin >> agenda[n].Apellidos;
		
		cout << "Nombre: ";
		cin >> agenda[n].Nombre;
		
		cout << "Telefono: ";
		cin >> agenda[n].Telefono;
	}
	
	void mostrarAgenda(registro agenda[], int n){
		for(int i = 0; i<n; i++){
			cout << "Registro " << i+1 << ": " << endl;
			leeRegistro(agenda, i);
		}
	}
	
	bool borrarElemento(registro agenda[], int dni, int n){
		bool res = false;
		for(int i = 0; i<n; i++){
			if(dni == agenda[i].DNI){
				for(int j = i; j<n; j++){
					agenda[j].DNI = agenda[j+1].DNI;
					agenda[j].Apellidos = agenda[j+1].Apellidos;
					agenda[j].Nombre = agenda[j+1].Nombre;
					agenda[j].Telefono = agenda[j+1].Telefono;
				}
				res = true;
			}
		}
		return res;
	}
	
	void leeRegistro(registro agenda[], int r){
		cout << "DNI: " << agenda[r].DNI << endl;
		cout << "Apellidos: " << agenda[r].Apellidos << endl;
		cout << "Nombre: " << agenda[r].Nombre << endl;
		cout << "Telefono: " << agenda[r].Telefono << endl;
		cout << "\n";
	}
	
	bool buscaRegistro(registro agenda[], int dni, int n){
		bool res = false;
		for(int i = 0; i<n; i++){
			if(dni == agenda[i].DNI){
				cout << "Registro " << i+1 << " de la agenda: " << endl;
				leeRegistro(agenda, i);
				res = true;
			}
		}
		return res;
	}
	
	/*void elementosRepetidos(registro agenda[], int n){
		bool aux = true;
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				if(agenda[i].DNI == agenda[j].DNI){
					//cout << "El registro " << i+1 << " coincide con el " << j+1 << endl;
					if(aux){
						cout << "El registro " << i+1 << " (DNI = " << agenda[i].DNI << ") coincide con los siguientes registros: " << endl;
					}
					cout << "-->" << j+1 << endl;
					aux = false;
				}
			}
			aux = true;
		}
	}*/
	
	void elementosRepetidos(registro agenda[], int n){
		int cont = 0;
		int aux[MAX];
		copiarVector(aux, agenda, n);
		
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				if((aux[i]!=-1)&&(aux[i]==aux[j])){
					aux[j] = -1;
					cont++;
				}
			}
			if((cont!=0)&&(aux[i]!=-1)){
				cout << "El registro " << i+1 << " (DNI = " << aux[i] << ") tiene " << cont << " repetidos" << endl;
			}
			cont = 0;
		}
	}
	
	int cuentaLetraInicial(registro agenda[], char letra, int n){
		int res = 0;
		
		for(int i = 0; i<n; i++){
			if(agenda[i].Apellidos[0]==letra){
				res++;
			}
		}
		
		return res;
	}
	
	int mediaLetras(registro agenda[], int n){
		int res = 0;
		
		for(int i = 0; i<n; i++){
			res += agenda[i].Nombre.length();
		}
		
		res /= n;
		
		return res;
	}
	
	void copiarVector(int A[], registro B[], int n){
		for(int i = 0; i<n; i++){
			A[i] = B[i].DNI;
		}
	}