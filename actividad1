#include <iostream>
using namespace std;

const int MAX = 100;

struct Alumno {
	int legajo;
	char nombre[30];
	int edad;
};

struct Materia {
	char nombreMateria[30];
	Alumno alumnos[MAX];
	int cantAlumnos;
};

void insertarAlumno(Materia &m);
void eliminarAlumno(Materia &m, int legajoBuscado);
void mostrar(Materia &m, int i = 0);

int main() {
	Materia mat;
	mat.cantAlumnos = 0;
	
	cout << "Ingrese nombre de la materia: ";
	cin.getline(mat.nombreMateria, 30);
	
	int op;
	int legajo;
	
	do {
		cout << "\n--- MENU ---\n";
		cout << "1 - Insertar alumno\n";
		cout << "2 - Eliminar alumno\n";
		cout << "3 - Mostrar alumnos\n";
		cout << "0 - Salir\n";
		cout << "Opcion: ";
		cin >> op;
		cin.ignore(); 
		
		switch (op) {
		case 1:
			insertarAlumno(mat);
			break;
		case 2:
			cout << "Ingrese legajo a eliminar: ";
			cin >> legajo;
			cin.ignore();
			eliminarAlumno(mat, legajo);
			break;
		case 3:
			cout << "\nAlumnos de la materia " << mat.nombreMateria << ":\n";
			cout << "Legajo\tNombre\t\tEdad\n";
			cout << "-----------------------------\n";
			mostrar(mat);
			break;
		case 0:
			cout << "Saliendo...\n";
			break;
		default:
			cout << "Opcion invalida.\n";
		}
		
	} while (op != 0);
	
	return 0;
}

void insertarAlumno(Materia &m) {
	if (m.cantAlumnos >= MAX) {
		cout << "No se pueden agregar mas alumnos.\n";
		return;
	}
	
	cout << "Ingrese legajo: ";
	cin >> m.alumnos[m.cantAlumnos].legajo;
	cin.ignore();
	
	cout << "Ingrese nombre: ";
	cin.getline(m.alumnos[m.cantAlumnos].nombre, 30);
	
	cout << "Ingrese edad: ";
	cin >> m.alumnos[m.cantAlumnos].edad;
	cin.ignore();
	
	m.cantAlumnos++;
}

void eliminarAlumno(Materia &m, int legajoBuscado) {
	for (int i = 0; i < m.cantAlumnos; i++) {
		if (m.alumnos[i].legajo == legajoBuscado) {
			for (int j = i; j < m.cantAlumnos - 1; j++) {
				m.alumnos[j] = m.alumnos[j + 1];
			}
			m.cantAlumnos--;
			cout << "Alumno eliminado.\n";
			return;
		}
	}
	cout << "Alumno no encontrado.\n";
}

void mostrar(Materia &m, int i) {
	if (i >= m.cantAlumnos) return;
	
	cout << m.alumnos[i].legajo << "\t"
		<< m.alumnos[i].nombre << "\t\t"
		<< m.alumnos[i].edad << endl;
	
	mostrar(m, i + 1);
}
