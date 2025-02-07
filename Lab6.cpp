#include <iostream>
#include <locale.h>

using namespace std;

//Clase de animal//
class Animal {
protected:
	string nombre;
	int edad;

public:
	Animal(string n, int e) : nombre(n), edad(e) {}
	virtual void hacerSonido() {
		cout << nombre << " hace un sonido desconocido." << endl;
	}
};

//Clase de perro//
class Perro : public Animal {
public:
	Perro(string n, int e) : Animal(n, e) {}
	void hacerSonido() override {
		cout << nombre << " dice: Guau!" << endl;
	}
};

//Clase de automovil//
class Automovil {
private:
string marca;
int velocidad;

public:
	Automovil(string m, int v) : marca(m), velocidad(v) {}
	void acelerar() {
		velocidad += 10;
		cout << "El automóvil " << marca << " ahora va a " << velocidad << " km/h." << endl;
	}
};

//Clase de persona
class Persona {
private:
	string nombre;
	int edad;

public:
	Persona(string n, int e) : nombre(n), edad(e) {}
	void saludar() {
		cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años." << endl;
	}
};

int main() {

	setlocale(LC_ALL, "es_ES.UTF-8");

	Perro miPerro("Rex", 5);
	miPerro.hacerSonido();
	Automovil miCoche("Toyota", 60);
	miCoche.acelerar();
	Persona persona1("Carlos", 30);
	persona1.saludar();

	return 0;
}