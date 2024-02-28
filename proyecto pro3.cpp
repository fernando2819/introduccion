#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Definicion de la estructura para un libro
struct Libro {
	string titulo;
	string autor;
	string ISBN;
	int anioPublicacion;
	string genero;
	string editorial;
	int paginas;
};

// Definicion de la estructura para un usuario
struct Usuario {
	int idUsuario;
	string nombre;
	string apellido;
	string correo;
	int edad;
};

// Definicion de la estructura para un bibliotecario
struct Bibliotecario {
	int idEmpleado;
	string nombre;
	string apellido;
	string correo;
	int aniosExperiencia;
};

// Funcion para generar un codigo de 5 digitos aleatorio
int generarCodigoAleatorio() {
	return rand() % 90000 + 10000; // Genera un numero aleatorio entre 10000 y 99999
}

// Funcion para generar datos aleatorios para libros
void generarDatosAleatorios(Libro* libros, int cantidad) {
	string titulos[] = {"El Laberinto de los Espiritus", "El Alquimista", "La Sombra del Viento", "Los Juegos del Hambre", "El enigma de Fermat"};
	string autores[] = {"Simon Singh", "Carlos Ruiz Zafon", "Suzanne Collins", "George Orwell", "Makoto Shinkai"};
	string generos[] = {"Fantasia", "Misterio", "Aventura", "Ciencia", "Comedia"};
	string editoriales[] = {"Algar", "Corimbo", "Alba", "Alianza", "Lumen"};
	
	srand(time(NULL));
	
	for (int i = 0; i < cantidad; ++i) {
		libros[i].titulo = titulos[rand() % 5];
		libros[i].autor = autores[rand() % 5];
		libros[i].ISBN = to_string(generarCodigoAleatorio());
		libros[i].anioPublicacion = rand() % 54 + 1970;
		libros[i].genero = generos[rand() % 5];
		libros[i].editorial = editoriales[rand() % 5];
		libros[i].paginas = rand() % 400 + 100; // Paginas entre 100 y 499
	}
}

// Funcion para generar datos aleatorios para usuarios
void generarDatosAleatorios(Usuario* usuarios, int cantidad) {
	string nombres[] = {"Luis", "Lucia", "Fernando", "Mario", "Monica"};
	string apellidos[] = {"Garcia", "Lopez", "Jimenez", "Perez", "Vaca"};
	
	srand(time(NULL));
	
	for (int i = 0; i < cantidad; ++i) {
		usuarios[i].idUsuario = generarCodigoAleatorio();
		usuarios[i].nombre = nombres[rand() % 5];
		usuarios[i].apellido = apellidos[rand() % 5];
		usuarios[i].correo = usuarios[i].nombre + usuarios[i].apellido + "@example.com";
		usuarios[i].edad = rand() % 78 + 18; // Edad entre 18 y 95
	}
}

// Funcion para generar datos aleatorios para bibliotecarios
void generarDatosAleatorios(Bibliotecario* bibliotecarios, int cantidad) {
	string nombres[] = {"Luis", "Lucia", "Fernando", "Mario", "Monica"};
	string apellidos[] = {"Garcia", "Lopez", "Jimenez", "Perez", "Vaca"};
	
	srand(time(NULL));
	
	for (int i = 0; i < cantidad; ++i) {
		bibliotecarios[i].idEmpleado = generarCodigoAleatorio();
		bibliotecarios[i].nombre = nombres[rand() % 5];
		bibliotecarios[i].apellido = apellidos[rand() % 5];
		bibliotecarios[i].correo = bibliotecarios[i].nombre + bibliotecarios[i].apellido + "@library.com";
		bibliotecarios[i].aniosExperiencia = rand() % 30; // Años de experiencia entre 0 y 29
	}
}

// Funcion para buscar un libro por su titulo
void buscar(Libro* libros, int cantidad, string titulo) {
	vector<Libro> coincidencias;
	
	// Convertir el titulo de busqueda a minusculas
	transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
	
	for (int i = 0; i < cantidad; ++i) {
		// Convertir el titulo del libro actual a minusculas
		string tituloLibro = libros[i].titulo;
		transform(tituloLibro.begin(), tituloLibro.end(), tituloLibro.begin(), ::tolower);
		
		// Verificar si el titulo coincide con la busqueda
		if (tituloLibro.find(titulo) != string::npos) {
			coincidencias.push_back(libros[i]);
		}
	}
	
	if (!coincidencias.empty()) {
		cout << "Coincidencias encontradas:" << endl;
		for (const auto& libro : coincidencias) {
			cout << "Titulo: " << libro.titulo << ", Autor: " << libro.autor << ", ISBN: " << libro.ISBN << ", Ano de publicacion: " << libro.anioPublicacion << ", Genero: " << libro.genero << ", Editorial: " << libro.editorial << ", Paginas: " << libro.paginas << endl;
		}
	} else {
		cout << "No se encontraron coincidencias." << endl;
	}
}

// Funcion para buscar un usuario por su nombre o apellido
void buscar(Usuario* usuarios, int cantidad, string nombreApellido) {
	vector<Usuario> coincidencias;
	
	// Convertir el nombre o apellido de busqueda a minusculas
	transform(nombreApellido.begin(), nombreApellido.end(), nombreApellido.begin(), ::tolower);
	
	for (int i = 0; i < cantidad; ++i) {
		// Convertir el nombre y apellido del usuario actual a minusculas
		string nombre = usuarios[i].nombre;
		string apellido = usuarios[i].apellido;
		transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
		transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);
		
		// Verificar si el nombre o apellido coincide con la busqueda
		if (nombre == nombreApellido || apellido == nombreApellido) {
			coincidencias.push_back(usuarios[i]);
		}
	}
	
	if (!coincidencias.empty()) {
		cout << "Coincidencias encontradas:" << endl;
		for (const auto& usuario : coincidencias) {
			cout << "ID: " << usuario.idUsuario << ", Nombre: " << usuario.nombre << ", Apellido: " << usuario.apellido << ", Email: " << usuario.correo << ", Edad: " << usuario.edad << endl;
		}
	} else {
		cout << "No se encontraron coincidencias." << endl;
	}
}

// Funcion para buscar un bibliotecario por su nombre o apellido
void buscar(Bibliotecario* bibliotecarios, int cantidad, string nombreApellido) {
	vector<Bibliotecario> coincidencias;
	
	// Convertir el nombre o apellido de busqueda a minusculas
	transform(nombreApellido.begin(), nombreApellido.end(), nombreApellido.begin(), ::tolower);
	
	for (int i = 0; i < cantidad; ++i) {
		// Convertir el nombre y apellido del bibliotecario actual a minusculas
		string nombre = bibliotecarios[i].nombre;
		string apellido = bibliotecarios[i].apellido;
		transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
		transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);
		
		// Verificar si el nombre o apellido coincide con la busqueda
		if (nombre == nombreApellido || apellido == nombreApellido) {
			coincidencias.push_back(bibliotecarios[i]);
		}
	}
	
	if (!coincidencias.empty()) {
		cout << "Coincidencias encontradas:" << endl;
		for (const auto& bibliotecario : coincidencias) {
			cout << "ID: " << bibliotecario.idEmpleado << ", Nombre: " << bibliotecario.nombre << ", Apellido: " << bibliotecario.apellido << ", Email: " << bibliotecario.correo << ", Años de experiencia: " << bibliotecario.aniosExperiencia << endl;
		}
	} else {
		cout << "No se encontraron coincidencias." << endl;
	}
}

// Funcion para mostrar el listado de libros
void mostrarListado(Libro* libros, int cantidad) {
	cout << "\nListado de libros:" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << "Titulo: " << libros[i].titulo << ", Autor: " << libros[i].autor << ", ISBN: " << libros[i].ISBN << ", Ano de publicacion: " << libros[i].anioPublicacion << ", Genero: " << libros[i].genero << ", Editorial: " << libros[i].editorial << ", Paginas: " << libros[i].paginas << endl;
	}
}

// Funcion para mostrar el listado de usuarios
void mostrarListado(Usuario* usuarios, int cantidad) {
	cout << "\nListado de usuarios:" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << "ID: " << usuarios[i].idUsuario << ", Nombre: " << usuarios[i].nombre << ", Apellido: " << usuarios[i].apellido << ", Email: " << usuarios[i].correo << ", Edad: " << usuarios[i].edad << endl;
	}
}

// Funcion para mostrar el listado de bibliotecarios
void mostrarListado(Bibliotecario* bibliotecarios, int cantidad) {
	cout << "\nListado de bibliotecarios:" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << "ID: " << bibliotecarios[i].idEmpleado << ", Nombre: " << bibliotecarios[i].nombre << ", Apellido: " << bibliotecarios[i].apellido << ", Email: " << bibliotecarios[i].correo << ", Años de experiencia: " << bibliotecarios[i].aniosExperiencia << endl;
	}
}

// Funcion de busqueda recursiva de libros
void buscarLibrosRecursivo(Libro* libros, int cantidad, string titulo, int index) {
	if (index >= cantidad) {
		cout << "No se encontraron coincidencias." << endl;
		return;
	}
	
	// Convertir el titulo de busqueda a minusculas
	transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
	
	// Convertir el titulo del libro actual a minusculas
	string tituloLibro = libros[index].titulo;
	transform(tituloLibro.begin(), tituloLibro.end(), tituloLibro.begin(), ::tolower);
	
	// Verificar si el titulo coincide con la busqueda
	if (tituloLibro.find(titulo) != string::npos) {
		cout << "Coincidencia encontrada:" << endl;
		cout << "Titulo: " << libros[index].titulo << ", Autor: " << libros[index].autor << ", ISBN: " << libros[index].ISBN << ", Ano de publicacion: " << libros[index].anioPublicacion << ", Genero: " << libros[index].genero << ", Editorial: " << libros[index].editorial << ", Paginas: " << libros[index].paginas << endl;
	}
	
	// Llamar recursivamente a la funcion con el siguiente indice
	buscarLibrosRecursivo(libros, cantidad, titulo, index + 1);
}

// Funcion de busqueda recursiva de usuarios
void buscarUsuariosRecursivo(Usuario* usuarios, int cantidad, string nombreApellido, int index) {
	if (index >= cantidad) {
		cout << "No se encontraron coincidencias." << endl;
		return;
	}
	
	// Convertir el nombre o apellido de busqueda a minusculas
	transform(nombreApellido.begin(), nombreApellido.end(), nombreApellido.begin(), ::tolower);
	
	// Convertir el nombre y apellido del usuario actual a minusculas
	string nombre = usuarios[index].nombre;
	string apellido = usuarios[index].apellido;
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
	transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);
	
	// Verificar si el nombre o apellido coincide con la busqueda
	if (nombre == nombreApellido || apellido == nombreApellido) {
		cout << "Coincidencia encontrada:" << endl;
		cout << "ID: " << usuarios[index].idUsuario << ", Nombre: " << usuarios[index].nombre << ", Apellido: " << usuarios[index].apellido << ", Email: " << usuarios[index].correo << ", Edad: " << usuarios[index].edad << endl;
	}
	
	// Llamar recursivamente a la funcion con el siguiente indice
	buscarUsuariosRecursivo(usuarios, cantidad, nombreApellido, index + 1);
}

// Funcion de busqueda recursiva de bibliotecarios
void buscarBibliotecariosRecursivo(Bibliotecario* bibliotecarios, int cantidad, string nombreApellido, int index) {
	if (index >= cantidad) {
		cout << "No se encontraron coincidencias." << endl;
		return;
	}
	
	// Convertir el nombre o apellido de busqueda a minusculas
	transform(nombreApellido.begin(), nombreApellido.end(), nombreApellido.begin(), ::tolower);
	
	// Convertir el nombre y apellido del bibliotecario actual a minusculas
	string nombre = bibliotecarios[index].nombre;
	string apellido = bibliotecarios[index].apellido;
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
	transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);
	
	// Verificar si el nombre o apellido coincide con la busqueda
	if (nombre == nombreApellido || apellido == nombreApellido) {
		cout << "Coincidencia encontrada:" << endl;
		cout << "ID: " << bibliotecarios[index].idEmpleado << ", Nombre: " << bibliotecarios[index].nombre << ", Apellido: " << bibliotecarios[index].apellido << ", Email: " << bibliotecarios[index].correo << ", Años de experiencia: " << bibliotecarios[index].aniosExperiencia << endl;
	}
	
	// Llamar recursivamente a la funcion con el siguiente indice
	buscarBibliotecariosRecursivo(bibliotecarios, cantidad, nombreApellido, index + 1);
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
		cout << "1) Llenado de datos aleatorios" << endl;
		cout << "2) Listados" << endl;
		cout << "3) Busquedas" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			// Llenado de datos aleatorios
			generarDatosAleatorios(libros, cantidad);
			generarDatosAleatorios(usuarios, cantidad);
			generarDatosAleatorios(bibliotecarios, cantidad);
			cout << "Datos generados aleatoriamente." << endl;
			break;
			
		case '2':
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
			
		case '3':
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
				
				switch (opcionBusquedas) {
				case 'a': {
					string titulo;
					cout << "Ingrese el titulo del libro a buscar: ";
					cin.ignore(); // Limpiar el buffer del teclado
					getline(cin, titulo);
					buscarLibrosRecursivo(libros, cantidad, titulo, 0);
					break;
				}
				
				case 'b': {
					string nombreApellido;
					cout << "Ingrese el nombre o apellido del usuario a buscar: ";
					cin >> nombreApellido;
					buscarUsuariosRecursivo(usuarios, cantidad, nombreApellido, 0);
					break;
				}
				
				case 'c': {
					string nombreApellido;
					cout << "Ingrese el nombre o apellido del bibliotecario a buscar: ";
					cin >> nombreApellido;
					buscarBibliotecariosRecursivo(bibliotecarios, cantidad, nombreApellido, 0);
					break;
				}
				
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
