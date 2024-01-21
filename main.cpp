#include<iostream>
#include "cabecera.h"

#define MAX 200

using namespace std;

	int main(){
		bool continuar = true;
		int eleccion, lim, numElementos = 0, dniAux;
		char caracterAux;
		int numResultante;
		registro agenda[MAX];
		
		
		do{
			cout << "Introduzca un limite de registros: ";
			cin >> lim;
		}while(lim>MAX);
		
		do{
			cout << "\nElija entre las siguientes opciones: \n\n";
			cout << "1)--> Nuevo elemento" << endl;
			cout << "2)--> Eliminar elemento" << endl;
			cout << "3)--> Buscar elemento" << endl;
			cout << "4)--> Contar iniciales de apellidos" << endl;
			cout << "5)--> Mostrar todos los registros" << endl;
			cout << "6)--> Resetear agenda" << endl;
			cout << "7)--> Comprobar elementos con el mismo DNI" << endl;
			cout << "8)--> Longitud media de todos los nombres" << endl;
			cout << "9)--> Salir del menu" << endl;
			
			cin >> eleccion;
			
			switch(eleccion){
				case 1:
					if(numElementos<lim){
						nuevoElemento(agenda, numElementos++);
					}else{
						cout << "Agenda llena..." << endl;
					}
					break;
				case 2:
					cout << "Introduzca el DNI del contacto a borrar: " << endl;
					cin >> dniAux;
					if(borrarElemento(agenda, dniAux, numElementos)){
						cout << "Elemento borrado" << endl;
						numElementos--;
					}else{
						cout << "No se ha podido encontrar..." << endl;
					}
					break;
				case 3:
					cout << "Introduzca el DNI del contacto a localizar: " << endl;
					cin >> dniAux;
					if(!buscaRegistro(agenda, dniAux, numElementos)){
						cout << "No se ha podido encontrar..." << endl;
					}
					break;
				case 4:
					cout << "Introduzca la letra inicial a contar: " << endl;
					cin >> caracterAux;
					numResultante = cuentaLetraInicial(agenda, caracterAux, numElementos);
					cout << "El numero total de apellidos con " << caracterAux << " como inicial es " << numResultante << endl;
					break;
				case 5:
					if(numElementos>0){
						cout << "Su agenda de contactos contiene los siguientes registros: " << endl;
						mostrarAgenda(agenda, numElementos);
					}else{
						cout << "Su agenda de contactos esta vacia actualmente..." << endl;
					}
					break;
				case 6:
					numElementos = 0;
					cout << "Agenda reseteada\n" << endl;
					break;
				case 7:
					elementosRepetidos(agenda, numElementos);
					break;
				case 8:
					if(numElementos>0){
						numResultante = mediaLetras(agenda, numElementos);
					cout << "El numero promedio de letras en los nombres de los contactos es " << numResultante << endl;
					}else{
						cout << "Su agenda de contactos esta vacia actualmente..." << endl;
					}
					break;
				case 9:
					continuar = false;
					break;
				default:
					cout << "Opcion no disponible\n" << endl;
					break;
			}
		}while(continuar);
		
		return 0;
	}