#include <iostream>
using namespace std;

int main() {
	int num1, num2, num3;
	
	// Solicitar al usuario ingresar tres n�meros
	std::cout << "Ingrese el primer numero: ";
	std::cin >> num1;
	
	std::cout << "Ingrese el segundo numero: ";
	std::cin >> num2;
	
	std::cout << "Ingrese el tercer numero: ";
	std::cin >> num3;
	
	// Determinar el n�mero mayor
	int mayor = num1;
	
	if (num2 > mayor) {
		mayor = num2;
	}
	
	if (num3 > mayor) {
		mayor = num3;
	}
	
	// Mostrar el n�mero mayor
	std::cout << "El numero mayor es: " << mayor << std::endl;
	
	return 0;
}
