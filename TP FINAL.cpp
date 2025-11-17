#include <iostream>
using namespace std;

typedef char tvector[51];

void ingresarDatos(tvector &frase, int &clave);
void encriptar(tvector &frase, int clave, tvector &resultado);
void desencriptar(tvector &frase, int clave, tvector &resultado);
int validarFrase(tvector &frase);
int validarClave(int clave);

int main() {
	tvector frase, encriptada, desencriptada;
	int clave = 0;
	int opcion;
	int paso1 = 0, paso2 = 0;
	
	do {
		cout << "***** Encriptador *****" << endl;
		cout << "1- Ingresar frase y clave de encriptacion" << endl;
		cout << "2- Encriptar frase" << endl;
		cout << "3- Desencriptar frase" << endl;
		cout << "4- Salir" << endl;
		cout << "***************" << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;
		cin.ignore();
		
		switch (opcion) {
		case 1:
			ingresarDatos(frase, clave);
			if (validarFrase(frase) == 1 && validarClave(clave) == 1)
				paso1 = 1;
			else {
				cout << "ENTRADA DE DATOS INCORRECTA" << endl;
				paso1 = 0;
			}
			break;
			
		case 2:
			if (paso1 == 1) {
				encriptar(frase, clave, encriptada);
				cout << "Cadena encriptada: " << encriptada << endl;
				paso2 = 1;
			} else
				cout << "Debe ingresar frase y clave primero." << endl;
			break;
			
		case 3:
			if (paso2 == 1) {
				desencriptar(encriptada, clave, desencriptada);
				cout << "Cadena desencriptada: " << desencriptada << endl;
			} else
				cout << "Debe encriptar antes de desencriptar." << endl;
			break;
			
		case 4:
			cout << "FIN DE PROGRAMA" << endl;
			break;
			
		default:
			cout << "OPCION INCORRECTA, intente de nuevo" << endl;
		}
		
	} while (opcion != 4);
	
	return 0;
}

void ingresarDatos(tvector &frase, int &clave) {
	cout << "Ingrese frase (max 50 caracteres): ";
	cin.getline(frase, 51);
	cout << "Ingrese clave de encriptacion (entero >= 100): ";
	cin >> clave;
}

int validarFrase(tvector &frase) {
	int i = 0;
	while (frase[i] != '\0') {
		if (!((frase[i] >= 'A' && frase[i] <= 'Z') ||
			(frase[i] >= 'a' && frase[i] <= 'z') ||
			frase[i] == ' '))
			return 0;
		i++;
	}
	return 1;
}

int validarClave(int clave) {
	if (clave >= 100)
		return 1;
	else
		return 0;
}

void encriptar(tvector &frase, int clave, tvector &resultado) {
	int i = 0;
	int tempClave = clave;
	int digitos[10];
	int cant = 0;
	
	while (tempClave > 0) {
		digitos[cant] = tempClave % 10;
		tempClave /= 10;
		cant++;
	}
	
	int j = cant - 1;
	while (frase[i] != '\0') {
		resultado[i] = frase[i] + digitos[j];
		j--;
		if (j < 0)
			j = cant - 1;
		i++;
	}
	resultado[i] = '\0';
}

void desencriptar(tvector &frase, int clave, tvector &resultado) {
	int i = 0;
	int tempClave = clave;
	int digitos[10];
	int cant = 0;
	
	while (tempClave > 0) {
		digitos[cant] = tempClave % 10;
		tempClave /= 10;
		cant++;
	}
	
	int j = cant - 1;
	while (frase[i] != '\0') {
		resultado[i] = frase[i] - digitos[j];
		j--;
		if (j < 0)
			j = cant - 1;
		i++;
	}
	resultado[i] = '\0';
}

