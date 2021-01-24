#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <ctime>

//constantes
#define talla 4
#define DNI 38374502

using namespace std;

//variables
int i;
int opcion;//recibe el valor para el switch.
char respuesta;//recibe un caracter (s/n) para volver a ingresar contraseña en caso de error.
bool seguir = true;//variable para crear el ciclo y volver al Menu.
int Nueva_contra[talla]; //vector con contraseña al azar.
int Ingreso_usuario[talla]; // vector con contraseña ingresada por el usuario.

//Prototipo de funciones
void Menu(); //menu principal para seleccionar opciones.
void Program_(); //Funcion que contiene la logica del programa.
void Pause_cls(); // Funcion para no repetir tanto codigo(System(pause)/system(cls)).
void Crear_contra(); // Funcion que genera una contraseña aleatoria de 4 digitos. 
void Utilizar_contra(); //Funcion que permite al usuario ingresar contraseña.
void Compara_contra(); // Compara la contraseña aleatoria con la ingresada por el usuario.

//Funciones 
void Program_(){
	seguir = true;
	do{
		Menu();
		do{
		cout << "OPCION: "; cin >> opcion;
		if((opcion < 1)||(opcion > 3)){
			cout <<"Ingrese un dato dentro del rango 1 - 3"<< endl;
		}
		}while((opcion < 1)||(opcion > 3));
		switch (opcion){
		case 1:
			Crear_contra();
			Pause_cls();
			break;
		case 2:
			Utilizar_contra();
			Compara_contra();
			Pause_cls();
			break;
		case 3:
			seguir = false;
			break; 
		}
	}while(seguir);
}

void Pause_cls(){
	system("pause");
	system("cls");
}

void Menu(){
	cout << "Evaluacion Final de Herramientas de Programacion - ESBA"<< endl;
	cout << "-------------------------------------------------------"<< endl;
	cout << "		JOSÉ ALBERTO CARLOMAGNO" << endl << endl;
	cout << "	MENU" << endl<< endl;
	cout << "1 - CREAR CLAVES AL AZAR" << endl;
	cout << "2 - UTILIZAR CLAVES" << endl;
	cout << "3 - SALIR"<<endl<< endl;
}


void Crear_contra(){
	for(i=0;i<talla;i++){
		Nueva_contra[i] = rand()% 10 ;
	}
	cout << "Su nueva contraseña es : ";
	for(i=0;i<talla;i++){
		cout << Nueva_contra[i];
	}
	cout << endl;
}

void Utilizar_contra(){
	cout << "Ingrese su contraseña:" << endl;
	for(i=0;i<talla;i++){
		do{
			cin >> Ingreso_usuario[i];
			if ((Ingreso_usuario[i] < 0) || (Ingreso_usuario[i] > 9)){
				cout << "ingrese un numero dentro del rango 0 - 9 ..."<<endl;
			}
		}while((Ingreso_usuario[i] < 0) || (Ingreso_usuario[i] > 9));
	}
	cout << "Usted ingreso: ";
	for(i=0;i<talla;i++){
		cout << Ingreso_usuario[i];
	}
	cout << endl;
}

void Compara_contra(){
	int tf = 0; //contador que aumenta por cada digito correcto
	for(i=0;i<talla;i++){
		if(Nueva_contra[i] == Ingreso_usuario[i]){
			tf++;
		}
	}
	if(tf == 4){
		cout << "Carlomagno José Alberto " << DNI << endl;
	}else{
		cout << "Su contraseña es Incorrecta... volver a ingresar contraseña? s/n"<<endl ;
		do{
		cin >> respuesta;
		if((respuesta != 's') && (respuesta != 'n')){
			cout << "ingreso una opcion no valida ... vuelve a intentarlo "<< endl;
		}
		}while((respuesta != 's') && (respuesta != 'n'));
		if(respuesta == 's'){
			Utilizar_contra();
			Compara_contra();
		}
	}
}
//programa principal
int main() {
	srand(time(NULL));
	Program_();
	return 0;
}

