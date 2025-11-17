#include <iostream>
using namespace std;

const int MAX = 100;

struct Paciente {
	int id;
	char nombre[30];
	char especie[30];
	int edad;
	bool activo;
};


typedef Paciente tvector[MAX];
void agregarPaciente(tvector &v, int &cant);
void ordenarPorNombre(tvector &v, int cant);
void darDeBaja(tvector &v, int cant, int idBuscado);
void mostrar(tvector &v, int cant);
int comparar(const char a[], const char b[]);

int main() {
	tvector pacientes;
	int cant = 0;
	int op, idBaja;
	
	do {
		cout << "\n--- MENU PACIENTES ---\n";
		cout << "1. Agregar paciente\n";
		cout << "2. Ordenar pacientes por nombre\n";
		cout << "3. Dar de baja paciente\n";
		cout << "4. Mostrar pacientes activos\n";
		cout << "0. Salir\n";
		cout << "Ingrese opcion: ";
		cin >> op;
		
		switch (op) {
		case 1:
			cout << "Ingrese ID, nombre, especie y edad del paciente:\n";
			agregarPaciente(pacientes, cant);
			break;
		case 2:
			ordenarPorNombre(pacientes, cant);
			cout << "Pacientes ordenados por nombre.\n";
			break;
		case 3:
			cout << "Ingrese ID del paciente a dar de baja: ";
			cin >> idBaja;
			darDeBaja(pacientes, cant, idBaja);
			cout << "Paciente dado de baja.\n";
			break;
		case 4:
			cout << "Pacientes activos:\n";
			mostrar(pacientes, cant);
			break;
		case 0:
			cout << "Saliendo...\n";
			break;
		default:
			cout << "Opcion invalida, intente de nuevo.\n";
		}
	} while (op != 0);
	
	return 0;
}
void agregarPaciente(tvector &v, int &cant) {
	if (cant >= MAX) return;
	
	cin >> v[cant].id;
	cin >> v[cant].nombre;
	cin >> v[cant].especie;
	cin >> v[cant].edad;
	
	v[cant].activo = true;
	cant++;
}

int comparar(const char a[], const char b[]) {
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0') {
		if (a[i] < b[i]) return -1;
		if (a[i] > b[i]) return 1;
		i++;
	}
	if (a[i] == '\0' && b[i] == '\0') return 0;
	if (a[i] == '\0') return -1;
	return 1;
}

void ordenarPorNombre(tvector &v, int cant) {
	for (int i = 0; i < cant - 1; i++) {
		for (int j = 0; j < cant - i - 1; j++) {
			if (comparar(v[j].nombre, v[j+1].nombre) > 0) {
				Paciente aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}

void darDeBaja(tvector &v, int cant, int idBuscado) {
	for (int i = 0; i < cant; i++) {
		if (v[i].id == idBuscado) {
			v[i].activo = false;
			return;
		}
	}
}

void mostrar(tvector &v, int cant) {
	for (int i = 0; i < cant; i++) {
		if (v[i].activo) {
			cout << v[i].id << " " << v[i].nombre << " " << v[i].especie << " " << v[i].edad << endl;
		}
	}
}
