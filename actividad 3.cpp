#include <iostream>
using namespace std;

const int MAX = 500;

struct Pelicula {
	string idPelicula;
	string titulo;
	bool disponible;
	float duracion;
	int anioEstreno;
};

typedef Pelicula tvector[MAX];

void agregarPelicula(tvector &v, int &ocup, Pelicula p) {
	if (ocup >= MAX - 1) return;
	ocup++;
	v[ocup] = p;
}

int buscarPorId(tvector &v, int n, const string &id) {
	if (n < 0) return -1;
	if (v[n].idPelicula == id) return n;
	return buscarPorId(v, n - 1, id);
}

int indiceMayorDuracion(tvector &v, int n) {
	if (n == 0) return 0;
	int maxAnterior = indiceMayorDuracion(v, n - 1);
	return (v[n].duracion > v[maxAnterior].duracion) ? n : maxAnterior;
}

void mostrarPeliculas(tvector &v, int n) {
	if (n < 0) return;
	mostrarPeliculas(v, n - 1);
	cout << "ID: " << v[n].idPelicula
		<< ", Titulo: " << v[n].titulo
		<< ", Duracion: " << v[n].duracion
		<< ", Anio: " << v[n].anioEstreno
		<< ", Disponible: " << (v[n].disponible ? "Si" : "No")
		<< endl;
}

int main() {
	tvector peliculas;
	int ocup = -1;
	int opcion;
	
	do {
		cout << "\n--- MENU PELICULAS ---\n";
		cout << "1. Agregar pelicula\n";
		cout << "2. Mostrar peliculas\n";
		cout << "3. Buscar pelicula por ID\n";
		cout << "4. Mostrar pelicula con mayor duracion\n";
		cout << "0. Salir\n";
		cout << "Ingrese opcion: ";
		cin >> opcion;
		cin.ignore();
		
		switch (opcion) {
		case 1: {
			Pelicula p;
			cout << "ID de la pelicula: ";
			getline(cin, p.idPelicula);
			cout << "Titulo: ";
			getline(cin, p.titulo);
			cout << "Duracion (minutos): ";
			cin >> p.duracion;
			cout << "Anio de estreno: ";
			cin >> p.anioEstreno;
			cin.ignore();
			p.disponible = true;
			agregarPelicula(peliculas, ocup, p);
			break;
		}
		case 2:
			mostrarPeliculas(peliculas, ocup);
			break;
		case 3: {
			string id;
			cout << "Ingrese ID a buscar: ";
			getline(cin, id);
			int idx = buscarPorId(peliculas, ocup, id);
			if (idx != -1)
				cout << "Pelicula encontrada: " << peliculas[idx].titulo << endl;
			else
				cout << "Pelicula no encontrada." << endl;
			break;
		}
		case 4:
			if (ocup >= 0) {
				int idxMayor = indiceMayorDuracion(peliculas, ocup);
				cout << "Pelicula con mayor duracion: " << peliculas[idxMayor].titulo
					<< " (" << peliculas[idxMayor].duracion << " min)" << endl;
			} else {
				cout << "No hay peliculas cargadas." << endl;
			}
			break;
		case 0:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}
