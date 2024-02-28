#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Definicion de la estructura para un libro
struct Libro {
	string title;
	string author;
	string ISBN;
	int publicationYear;
	int pages; // Nuevo atributo
	string genre; // Nuevo atributo
	string publisher; // Nuevo atributo
};

// Definicion de la estructura para un usuario
struct Usuario {
	int userID;
	string name;
	string lastname;
	string email;
	int age; // Nuevo atributo
};

// Definicion de la estructura para un bibliotecario
struct Bibliotecario {
	int employeeID;
	string name;
	string lastname;
	string email;
	int experienceYears; // Nuevo atributo
};

// Funcion para generar un codigo de 5 digitos aleatorio
int generarCodigoAleatorio() {
	return rand() % 90000 + 10000; // Genera un numero aleatorio entre 10000 y 99999
}

// Funcion para generar datos aleatorios para libros
void generarDatosAleatorios(Libro* libros, int cantidad) {
	// Arrays de datos fijos para utilizar en la generacion aleatoria
	string titulos[] = {"El Laberinto de los Espiritus", "El Alquimista", "La Sombra del Viento", "Los Juegos del Hambre", "El enigma de Fermat"};
	string autores[] = {"Simon Singh", "Carlos Ruiz Zafon", "Suzanne Collins", "George Orwell", "Makoto Shinkai"};
	string generos[] = {"Fantasia", "Misterio", "Aventura", "Ciencia", "Comedia"}; // Nuevos datos fijos
	string editoriales[] = {"Algar", "Corimbo", "Alba", "Alianza", "Lumen"}; // Nuevos datos fijos
	
	// Semilla para generar numeros aleatorios basados en el tiempo actual
	srand(time(NULL));
	
	// Generacion de datos aleatorios para cada estructura
	for (int i = 0; i < cantidad; ++i) {
		// Generacion aleatoria de datos para libros
		libros[i].title = titulos[rand() % 5];
		libros[i].author = autores[rand() % 5];
		libros[i].ISBN = to_string(generarCodigoAleatorio()); // Utiliza la funcion generarCodigoAleatorio para generar un ISBN de 5 digitos
		libros[i].publicationYear = rand() % 54 + 1970; // Anos entre 1970 y 2023
		libros[i].pages = rand() % 400 + 100; // Paginas entre 100 y 499
		libros[i].genre = generos[rand() % 5]; // Genero aleatorio
		libros[i].publisher = editoriales[rand() % 5]; // Editorial aleatoria
	}
}

// Funcion para generar datos aleatorios para usuarios
void generarDatosAleatorios(Usuario* usuarios, int cantidad) {
	string nombres[] = {"Luis", "Lucia", "Fernando", "Mario", "Monica"};
	string apellidos[] = {"Garcia", "Lopez", "Jimenez", "Perez", "Vaca"};
	
	// Generacion de datos aleatorios para cada estructura
	for (int i = 0; i < cantidad; ++i) {
		// Generacion aleatoria de datos para usuarios
		usuarios[i].userID = generarCodigoAleatorio(); // Utiliza la funcion generarCodigoAleatorio para generar un ID de usuario de 5 digitos
		usuarios[i].name = nombres[rand() % 5];
		usuarios[i].lastname = apellidos[rand() % 5];
		usuarios[i].email = usuarios[i].name + usuarios[i].lastname + "@example.com";
		usuarios[i].age = rand() % 79 + 18; // Edad entre 18 y 96 anos
	}
}

// Funcion para generar datos aleatorios para bibliotecarios
void generarDatosAleatorios(Bibliotecario* bibliotecarios, int cantidad) {
	string nombres[] = {"Luis", "Lucia", "Fernando", "Mario", "Monica"};
	string apellidos[] = {"Garcia", "Lopez", "Jimenez", "Perez", "Vaca"};
	
	// Generacion de datos aleatorios para cada estructura
	for (int i = 0; i < cantidad; ++i) {
		// Generacion aleatoria de datos para bibliotecarios
		bibliotecarios[i].employeeID = generarCodigoAleatorio(); // Utiliza la funcion generarCodigoAleatorio para generar un ID de bibliotecario de 5 digitos
		bibliotecarios[i].name = nombres[rand() % 5];
		bibliotecarios[i].lastname = apellidos[rand() % 5];
		bibliotecarios[i].email = bibliotecarios[i].name + bibliotecarios[i].lastname + "@library.com";
		bibliotecarios[i].experienceYears = rand() % 30; // Anos de experiencia entre 0 y 29
	}
}

// Funcion para buscar un libro por su titulo utilizando recursividad
void buscar(Libro* libros, int cantidad, string titulo, int index = 0) {
	if (index >= cantidad) {
		cout << "No se encontraron coincidencias." << endl;
		return;
	}
	
	// Convertir el titulo de busqueda y el titulo del libro actual a minusculas
	transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
	string tituloLibro = libros[index].title;
	transform(tituloLibro.begin(), tituloLibro.end(), tituloLibro.begin(), ::tolower);
	
	// Verificar si el titulo coincide con la busqueda
	if (tituloLibro.find(titulo) != string::npos) {
		cout << "Coincidencia encontrada:" << endl;
		cout << "Titulo: " << libros[index].title << ", Autor: " << libros[index].author << ", ISBN: " << libros[index].ISBN << ", Ano de publicacion: " << libros[index].publicationYear << ", Paginas: " << libros[index].pages << ", Genero: " << libros[index].genre << ", Editorial: " << libros[index].publisher << endl;
	}
	
	// Llamar recursivamente para buscar en el siguiente libro
	buscar(libros, cantidad, titulo, index + 1);
}

// Funcion para buscar un usuario por su nombre o apellido utilizando recursividad
void buscar(Usuario* usuarios, int cantidad, string nombreApellido, int index = 0) {
	if (index >= cantidad) {
		cout << "No se encontraron coincidencias." << endl;
		return;
	}
	
	// Convertir el nombre o apellido de busqueda, el nombre y el apellido del usuario actual a minusculas
	transform(nombreApellido.begin(), nombreApellido.end(), nombreApellido.begin(), ::tolower);
	string nombre = usuarios[index].name;
	string apellido = usuarios[index].lastname;
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
	transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);
	
	// Verificar si el nombre o apellido coincide con la busqueda
	if (nombre == nombreApellido || apellido == nombreApellido) {
		cout << "Coincidencia encontrada:" << endl;
		cout << "ID: " << usuarios[index].userID << ", Nombre: " << usuarios[index].name << ", Apellido: " << usuarios[index].lastname << ", Email: " << usuarios[index].email << ", Edad: " << usuarios[index].age << endl;
	}
	
	// Llamar recursivamente para buscar en el siguiente usuario
	buscar(usuarios, cantidad, nombreApellido, index + 1);
}

// Funcion para buscar un bibliotecario por su nombre o apellido utilizando recursividad
void buscar(Bibliotecario* bibliotecarios, int cantidad, string nombreApellido, int index = 0) {
	if (index >= cantidad) {
		cout << "No se encontraron coincidencias." << endl;
		return;
	}
	
	// Convertir el nombre o apellido de busqueda, el nombre y el apellido del bibliotecario actual a minusculas
	transform(nombreApellido.begin(), nombreApellido.end(), nombreApellido.begin(), ::tolower);
	string nombre = bibliotecarios[index].name;
	string apellido = bibliotecarios[index].lastname;
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
	transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);
	
	// Verificar si el nombre o apellido coincide con la busqueda
	if (nombre == nombreApellido || apellido == nombreApellido) {
		cout << "Coincidencia encontrada:" << endl;
		cout << "ID: " << bibliotecarios[index].employeeID << ", Nombre: " << bibliotecarios[index].name << ", Apellido: " << bibliotecarios[index].lastname << ", Email: " << bibliotecarios[index].email << ", Anos de experiencia: " << bibliotecarios[index].experienceYears << endl;
	}
	
	// Llamar recursivamente para buscar en el siguiente bibliotecario
	buscar(bibliotecarios, cantidad, nombreApellido, index + 1);
}

// Funcion para mostrar el listado de libros
void mostrarListado(Libro* libros, int cantidad) {
	cout << "\nListado de libros:" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << "Titulo: " << libros[i].title << ", Autor: " << libros[i].author << ", ISBN: " << libros[i].ISBN << ", Ano de publicacion: " << libros[i].publicationYear << ", Paginas: " << libros[i].pages << ", Genero: " << libros[i].genre << ", Editorial: " << libros[i].publisher << endl;
	}
}

// Funcion para mostrar el listado de usuarios
void mostrarListado(Usuario* usuarios, int cantidad) {
	cout << "\nListado de usuarios:" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << "ID: " << usuarios[i].userID << ", Nombre: " << usuarios[i].name << ", Apellido: " << usuarios[i].lastname << ", Email: " << usuarios[i].email << ", Edad: " << usuarios[i].age << endl;
	}
}

// Funcion para mostrar el listado de bibliotecarios
void mostrarListado(Bibliotecario* bibliotecarios, int cantidad) {
	cout << "\nListado de bibliotecarios:" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << "ID: " << bibliotecarios[i].employeeID << ", Nombre: " << bibliotecarios[i].name << ", Apellido: " << bibliotecarios[i].lastname << ", Email: " << bibliotecarios[i].email << ", Anos de experiencia: " << bibliotecarios[i].experienceYears << endl;
	}
}

int main() {
	const int cantidad = 3;
	Libro libros[cantidad];
	Usuario usuarios[cantidad];
	Bibliotecario bibliotecarios[cantidad];
	
	// Generacion de datos aleatorios para libros, usuarios y bibliotecarios
	generarDatosAleatorios(libros, cantidad);
	generarDatosAleatorios(usuarios, cantidad);
	generarDatosAleatorios(bibliotecarios, cantidad);
	
	char opcion;
	do {
		cout << "\nMENU:" << endl;
		cout << "1) Listados" << endl;
		cout << "2) Busquedas" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			// Submenu de listados
			char opcionListados;
			do {
				cout << "\nSUBMENU LISTADOS:" << endl;
				cout << "a) Listado de Libros" << endl;
				cout << "b) Listado de Usuarios" << endl;
				cout << "c) Listado de Bibliotecarios" << endl;
				cout << "x) Salir" << endl;
				cout << "Ingrese una opcion: ";
				cin >> opcionListados;
				
				switch (opcionListados) {
				case 'a':
					mostrarListado(libros, cantidad);
					break;
					
				case 'b':
					mostrarListado(usuarios, cantidad);
					break;
					
				case 'c':
					mostrarListado(bibliotecarios, cantidad);
					break;
					
				case 'x':
					break;
					
				default:
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			} while (opcionListados != 'x');
			break;
			
		case '2':
			// Submenu de busquedas
			char opcionBusquedas;
			do {
				cout << "\nSUBMENU BUSQUEDAS:" << endl;
				cout << "a) Busqueda de Libro (Titulo)" << endl;
				cout << "b) Busqueda de Usuario (Nombre o Apellido)" << endl;
				cout << "c) Busqueda de Bibliotecario (Nombre o Apellido)" << endl;
				cout << "x) Salir" << endl;
				cout << "Ingrese una opcion: ";
				cin >> opcionBusquedas;
				
				string busqueda;
				switch (opcionBusquedas) {
				case 'a':
					cout << "Ingrese el titulo del libro a buscar: ";
					cin.ignore(); // Limpiar el buffer del teclado
					getline(cin, busqueda);
					buscar(libros, cantidad, busqueda);
					break;
					
				case 'b':
					cout << "Ingrese el nombre o apellido del usuario a buscar: ";
					cin >> busqueda;
					buscar(usuarios, cantidad, busqueda);
					break;
					
				case 'c':
					cout << "Ingrese el nombre o apellido del bibliotecario a buscar: ";
					cin >> busqueda;
					buscar(bibliotecarios, cantidad, busqueda);
					break;
					
				case 'x':
					break;
					
				default:
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			} while (opcionBusquedas != 'x');
			break;
			
		case '0':
			cout << "Saliendo del programa..." << endl;
			break;
			
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcion != '0');
	
	return 0;
}
