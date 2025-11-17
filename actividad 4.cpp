#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Personaje {
	string nombre;
	string elemento;
	string clase;
	int vidaMaxima;
	int danio;
	string descripcion;
	bool desbloqueado;
};

void Insertar(Personaje (&tvector)[MAX], int &ocup);
void Buscar(Personaje (&tvector)[MAX], int ocup);
void Eliminar(Personaje (&tvector)[MAX], int &ocup);
void menu(int &op, Personaje (&tvector)[MAX], int &ocup);
void Imprimir(const Personaje &p);

int main() {
	int op = 0;
	int ocup = 0;
	Personaje tvector[MAX];
	menu(op, tvector, ocup);
	return 0;
}

void menu(int &op, Personaje (&tvector)[MAX], int &ocup) {
	do {
		cout << "1. Insertar" << endl;
		cout << "2. Buscar" << endl;
		cout << "3. Eliminar" << endl;
		cout << "4. Salir" << endl;
		cout << "Opcion: ";
		cin >> op; 
		cin.ignore();
		
		switch (op) {
		case 1: Insertar(tvector, ocup); break;
		case 2: Buscar(tvector, ocup); break;
		case 3: Eliminar(tvector, ocup); break;
		case 4: cout << "Fin del programa." << endl; break;
		default: cout << "Opcion incorrecta." << endl;
		}
		cout << endl;
	} while (op != 4);
}

void Insertar(Personaje (&tvector)[MAX], int &ocup) {
	if (ocup >= MAX) { cout << "No se pueden agregar mas personajes." << endl; return; }
	
	Personaje p;
	cout << "Nombre: "; getline(cin, p.nombre);
	cout << "Elemento: "; getline(cin, p.elemento);
	cout << "Clase: "; getline(cin, p.clase);
	cout << "Vida maxima: "; cin >> p.vidaMaxima;
	cout << "Danio: "; cin >> p.danio; cin.ignore();
	cout << "Descripcion: "; getline(cin, p.descripcion);
	cout << "Desbloqueado (1=si,0=no): "; cin >> p.desbloqueado; cin.ignore();
	
	int i = ocup;
	while (i > 0 && p.nombre < tvector[i-1].nombre) { tvector[i] = tvector[i-1]; i--; }
	tvector[i] = p;
	ocup++;
	
	cout << "Personaje agregado correctamente." << endl;
}

void Buscar(Personaje (&tvector)[MAX], int ocup) {
	if (ocup == 0) { cout << "No hay personajes registrados." << endl; return; }
	
	string nombre;
	cout << "Nombre del personaje a buscar: "; getline(cin, nombre);
	
	for (int i = 0; i < ocup; i++)
		if (tvector[i].nombre == nombre) { Imprimir(tvector[i]); return; }
		
		cout << "Personaje no encontrado." << endl;
}

void Eliminar(Personaje (&tvector)[MAX], int &ocup) {
	if (ocup == 0) { cout << "No hay personajes para eliminar." << endl; return; }
	
	string nombre;
	cout << "Nombre del personaje a eliminar: "; getline(cin, nombre);
	
	int i = 0;
	while (i < ocup && tvector[i].nombre != nombre) i++;
	if (i == ocup) { cout << "Personaje no encontrado." << endl; return; }
	
	for (int j = i; j < ocup-1; j++) tvector[j] = tvector[j+1];
	ocup--;
	
	cout << "Personaje eliminado." << endl;
}

void Imprimir(const Personaje &p) {
	cout << "Nombre: " << p.nombre << endl;
	cout << "Elemento: " << p.elemento << endl;
	cout << "Clase: " << p.clase << endl;
	cout << "Vida maxima: " << p.vidaMaxima << endl;
	cout << "Danio: " << p.danio << endl;
	cout << "Descripcion: " << p.descripcion << endl;
	cout << "Desbloqueado: " << (p.desbloqueado ? "Si" : "No") << endl;
}
