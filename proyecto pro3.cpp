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
    int pages; // Número de páginas
    string genre; // Género del libro
    string publisher; // Editorial
};

// Definicion de la estructura para un usuario
struct Usuario {
    int userID;
    string name;
    string lastname;
    string email;
    int age; // Edad del usuario
};

// Definicion de la estructura para un bibliotecario
struct Bibliotecario {
    int employeeID;
    string name;
    string lastname;
    string email;
    int experienceYears; // Años de experiencia del bibliotecario
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
    string generos[] = {"Fantasia", "Misterio", "Aventura", "Ciencia", "Comedia"};
    string editoriales[] = {"Algar", "Corimbo", "Alba", "Alianza", "Lumen"};
    
    // Semilla para generar numeros aleatorios basados en el tiempo actual
    srand(time(NULL));
    
    // Generacion de datos aleatorios para cada libro
    for (int i = 0; i < cantidad; ++i) {
        libros[i].title = titulos[rand() % 5];
        libros[i].author = autores[rand() % 5];
        libros[i].ISBN = to_string(generarCodigoAleatorio()); // Utiliza la funcion generarCodigoAleatorio para generar un ISBN de 5 digitos
        libros[i].publicationYear = rand() % 54 + 1970; // Anos entre 1970 y 2023
        libros[i].pages = rand() % 400 + 100; // Paginas entre 100 y 499
        libros[i].genre = generos[rand() % 5]; // Selecciona un genero aleatorio
        libros[i].publisher = editoriales[rand() % 5]; // Selecciona una editorial aleatoria
    }
}

// Funcion para generar datos aleatorios para usuarios
void generarDatosAleatorios(Usuario* usuarios, int cantidad) {
    string nombres[] = {"Luis", "Lucia", "Fernando", "Mario", "Monica"};
    string apellidos[] = {"Garcia", "Lopez", "Jimenez", "Perez", "Vaca"};
    
    srand(time(NULL));
    
    // Generacion de datos aleatorios para cada usuario
    for (int i = 0; i < cantidad; ++i) {
        usuarios[i].userID = generarCodigoAleatorio();
        usuarios[i].name = nombres[rand() % 5];
        usuarios[i].lastname = apellidos[rand() % 5];
        usuarios[i].email = usuarios[i].name + usuarios[i].lastname + "@example.com";
        usuarios[i].age = rand() % 79 + 18; // Edad entre 18 y 96 años
    }
}

// Funcion para generar datos aleatorios para bibliotecarios
void generarDatosAleatorios(Bibliotecario* bibliotecarios, int cantidad) {
    string nombres[] = {"Luis", "Lucia", "Fernando", "Mario", "Monica"};
    string apellidos[] = {"Garcia", "Lopez", "Jimenez", "Perez", "Vaca"};
    
    srand(time(NULL));
    
    // Generacion de datos aleatorios para cada bibliotecario
    for (int i = 0; i < cantidad; ++i) {
        bibliotecarios[i].employeeID = generarCodigoAleatorio();
        bibliotecarios[i].name = nombres[rand() % 5];
        bibliotecarios[i].lastname = apellidos[rand() % 5];
        bibliotecarios[i].email = bibliotecarios[i].name + bibliotecarios[i].lastname + "@library.com";
        bibliotecarios[i].experienceYears = rand() % 30; // Años de experiencia entre 0 y 29
    }
}

// Funcion para buscar un libro por su titulo
void buscar(Libro* libros, int cantidad, string titulo) {
    vector<Libro> coincidencias;
    
    // Convertir el titulo de busqueda a minusculas
    transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
    
    for (int i = 0; i < cantidad; ++i) {
        // Convertir el titulo del libro actual a minusculas
        string tituloLibro = libros[i].title;
        transform(tituloLibro.begin(), tituloLibro.end(), tituloLibro.begin(), ::tolower);
        
        // Verificar si el titulo coincide con la busqueda
        if (tituloLibro.find(titulo) != string::npos) {
            coincidencias.push_back(libros[i]);
        }
    }
    
    if (!coincidencias.empty()) {
        cout << "Coincidencias encontradas:" << endl;
        for (const auto& libro : coincidencias) {
            cout << "Titulo: " << libro.title << ", Autor: " << libro.author << ", ISBN: " << libro.ISBN << ", Ano de publicacion: " << libro.publicationYear << ", Paginas: " << libro.pages << ", Genero: " << libro.genre << ", Editorial: " << libro.publisher << endl;
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
        string nombre = usuarios[i].name;
        string apellido = usuarios[i].lastname;
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
            cout << "ID: " << usuario.userID << ", Nombre: " << usuario.name << ", Apellido: " << usuario.lastname << ", Email: " << usuario.email << ", Edad: " << usuario.age << endl;
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
        string nombre = bibliotecarios[i].name;
        string apellido = bibliotecarios[i].lastname;
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
            cout << "ID: " << bibliotecario.employeeID << ", Nombre: " << bibliotecario.name << ", Apellido: " << bibliotecario.lastname << ", Email: " << bibliotecario.email << ", Años de experiencia: " << bibliotecario.experienceYears << endl;
        }
    } else {
        cout << "No se encontraron coincidencias." << endl;
    }
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
        cout << "ID: " << bibliotecarios[i].employeeID << ", Nombre: " << bibliotecarios[i].name << ", Apellido: " << bibliotecarios[i].lastname << ", Email: " << bibliotecarios[i].email << ", Años de experiencia: " << bibliotecarios[i].experienceYears << endl;
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
        cout << "1) Llenado de datos" << endl;
        cout << "2) Listados" << endl;
        cout << "3) Busquedas" << endl;
        cout << "0) Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case '1':
                // Llenado de datos
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
                            buscar(libros, cantidad, titulo);
                            break;
                        }
                            
                        case 'b': {
                            string nombreApellido;
                            cout << "Ingrese el nombre o apellido del usuario a buscar: ";
                            cin >> nombreApellido;
                            buscar(usuarios, cantidad, nombreApellido);
                            break;
                        }
                            
                        case 'c': {
                            string nombreApellido;
                            cout << "Ingrese el nombre o apellido del bibliotecario a buscar: ";
                            cin >> nombreApellido;
                            buscar(bibliotecarios, cantidad, nombreApellido);
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
