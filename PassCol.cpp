// Importar Librerias
#include <iostream>     // Libreria para entrada/salida
#include <string>       // Libreria para manejo de cadenas
#include <iomanip>      // Libreria para formateo de salida
using namespace std;    // Usar el espacio de nombres estandar (Evita usar std::)

// Crear Estructuras
struct Pasaporte {      // Estructura | Almacena los datos de un pasaporte
    // Atributos | Datos que se relacionan entre si (En este caso, la info de un pasaporte)
    string numero;      
    string nombreCompleto;
    string fechaNacimiento;
    string nacionalidad;
    string fechaEmision;
    string fechaVencimiento;
    bool estado; // true = estado, false = cancelado
};

// Declarar variables globales
Pasaporte* pasaportes;    // Reservar espacio de memoria para el arreglo dinamico
int capacidadMaxima, totalPasaportes = 0;   // Crear variables de tipo entero

// Crear Funciones
void mostrarMenu() {    // Funcion | Muestra el menu de acciones del sistema
    cout << "\n" << string(50, '=') << endl;
    cout << "    SISTEMA DE GESTION DE PASAPORTES" << endl;
    cout << string(50, '=') << endl;
    cout << "1. Registrar nuevo pasaporte" << endl;
    cout << "2. Mostrar todos los pasaportes" << endl;
    cout << "3. Cancelar pasaporte" << endl;
    cout << "4. Salir del sistema" << endl;
    cout << string(50, '=') << endl;
    cout << "| PREGUNTA | ¿Que deseas hacer? (1-5) => ";
}

void registrarPasaporte() {     // Función | Registra un nuevo pasaporte en el sistema
    if (totalPasaportes >= capacidadMaxima) {
        cout << "\nError: El sistema ha alcanzado su capacidad maxima (" 
        << capacidadMaxima << " pasaportes)" << endl;
        return;
    }

    Pasaporte nuevoPasaporte;

    cout << "\n" << string(50, '=') << endl;
    cout << "    REGISTRO DE NUEVO PASAPORTE" << endl;
    cout << string(50, '=') << endl;
    
    cout << "Numero de pasaporte (p.e 01234) => ";
    cin >> nuevoPasaporte.numero;
    
    // Verificar que el número no esté duplicado
    for (int i = 0; i < totalPasaportes; i++) {
        if (pasaportes[i].numero == nuevoPasaporte.numero && pasaportes[i].estado) {
            cout << "| ¡ERROR! | Ya existe un pasaporte activo con ese numero." << endl;
            return;
        }
    }
    
    cin.ignore(); // Limpiar buffer
    cout << "Nombre completo (p.e John Doe) => ";
    getline(cin, nuevoPasaporte.nombreCompleto);
    
    cout << "Fecha de nacimiento (DD/MM/AAAA) => ";
    getline(cin, nuevoPasaporte.fechaNacimiento);
    
    cout << "Nacionalidad (p.e Colombiano (a)) => ";
    getline(cin, nuevoPasaporte.nacionalidad);
    
    cout << "Fecha de emision del pasaporte (DD/MM/AAAA) => ";
    getline(cin, nuevoPasaporte.fechaEmision);
    
    cout << "Fecha de vencimiento del pasaporte (DD/MM/AAAA) => ";
    getline(cin, nuevoPasaporte.fechaVencimiento);
    
    nuevoPasaporte.estado = true;
    
    // Agregar al arreglo
    pasaportes[totalPasaportes] = nuevoPasaporte;
    totalPasaportes++;
    
    cout << "\n| ¡ALERTA! | Pasaporte registrado exitosamente!" << endl;
    cout << "| INFO | # Pasaportes registrados | " << totalPasaportes << endl;
}

void mostrarPasaportes() {  // Función | Muestra todos los pasaportes registrados en el sistema
    if (totalPasaportes == 0) {
        cout << "\n| ¡ALERTA! | No hay pasaportes registrados en el sistema." << endl;
        return;
    }

    cout << "\n" << string(50, '=') << endl;
    cout << "    LISTA DE PASAPORTES REGISTRADOS" << endl;
    cout << string(50, '=') << endl;
    cout << "| INFO | # Total de pasaportes: " << totalPasaportes << " pasaportes" << endl;
    cout << string(80, '-') << endl;
    
    for (int i = 0; i < totalPasaportes; i++) {
        cout << "Pasaporte #" << (i + 1) << endl;
        cout << "  Numero: " << pasaportes[i].numero << endl;
        cout << "  Nombre: " << pasaportes[i].nombreCompleto << endl;
        cout << "  Fecha de nacimiento: " << pasaportes[i].fechaNacimiento << endl;
        cout << "  Nacionalidad: " << pasaportes[i].nacionalidad << endl;
        cout << "  Fecha de emision: " << pasaportes[i].fechaEmision << endl;
        cout << "  Fecha de vencimiento: " << pasaportes[i].fechaVencimiento << endl;
        cout << "  Estado: " << (pasaportes[i].estado ? "ACTIVO" : "CANCELADO") << endl;
        cout << string(80, '-') << endl;
    }
}

void cancelarPasaporte() {      // Función | Cancela un pasaporte registrado en el sistema
    if (totalPasaportes == 0) {
        cout << "\n| ¡ALERTA! | No hay pasaportes registrados en el sistema." << endl;
        return;
    }

    string numeroCancelar;
    cout << "\n" << string(50, '=') << endl;
    cout << "    CANCELAR PASAPORTE" << endl;
    cout << string(50, '=') << endl;
    cout << "| PREGUNTA | ¿Cual pasaporte desea cancelar? Ingrese el # (p.e 01234): ";
    cin >> numeroCancelar;

    

    for (int i = 0; i < totalPasaportes; i++) {
        if (pasaportes[i].numero == numeroCancelar && pasaportes[i].estado) {
            cout << "\n| ¡ALERTA! | Pasaporte encontrado |" << endl;
            cout << "Numero: " << pasaportes[i].numero << endl;
            cout << "Nombre: " << pasaportes[i].nombreCompleto << endl;
            
            char confirmacion;
            cout << "\n| PREGUNTA | ¿Esta seguro de cancelar este pasaporte? (s/n): ";
            cin >> confirmacion;
            
            if (confirmacion == 's' || confirmacion == 'S') {
                pasaportes[i].estado = false;
                cout << "| ¡ALERTA! | Pasaporte cancelado exitosamente." << endl;
            } else {
                cout << "| ¡ALERTA! | Operacion cancelada." << endl;
            }
            return;
        }
    }
    
    cout << "| ¡ALERTA! | No se encontro un pasaporte estado con el numero: " << numeroCancelar << endl;
}

int main() {    // Función principal | Punto de entrada del programa
    // Mensaje de Bienvenida
    cout << "\n| === SISTEMA DE GESTION DE PASAPORTES === |" << endl;
    cout << "| INFO | ¡Bienvenid@ a PassCol, el sistema de gestion de pasaportes mas grande de Colombia! \n| PREGUNTA | Para comenzar, ¿Cuantos pasaportes deseas manejar en el sistema? => ";
    cin >> capacidadMaxima;

    while (capacidadMaxima <= 0) {  // Bucle | Valida la capacidad ingresada
        cout << "| ERROR | La capacidad debe ser un # mayor a 0. Ingresa un valor valido => ";      
        cin >> capacidadMaxima; // Leer la capacidad maxima del sistema
    }
    
    pasaportes = new Pasaporte[capacidadMaxima];        // Crear arreglo dinámico
    
    cout << "| ¡Alerta! | Sistema inicializado exitosamente con capacidad para " << capacidadMaxima << " pasaportes." << endl;
    
    int opcion;     // Crear variable temporal para almacenar la opción del usuario
    
    do {        // Bucle | Muestra el menu, ejecuta la opción seleccionada y repite hasta que el usuario decida salir
        mostrarMenu();
        cin >> opcion;      // Leer la opcion del usuario
        
        switch (opcion) {       // Switch | Ejecuta una funcion segun la opcion seleccionada por el usuario
            case 1: registrarPasaporte(); break;
            case 2: mostrarPasaportes(); break;
            case 3: cancelarPasaporte(); break;
            case 4: cout << "\n| ¡ALERTA! | Gracias por usar PassCol su Gestor de confianza. ¡Vuelva Pronto!" << endl; break;
            default: cout << "\n| ¡ALERTA! | Opcion invalida. Por favor seleccione una opcion del 1 al 4." << endl;
        }
        
        if (opcion != 4) { cout << "\n| ¡ALERTA! | Presione Enter para continuar => "; cin.ignore(); cin.get(); }
        
    } while (opcion != 4);
    
    // Liberar memoria
    delete[] pasaportes;  // Liberar la memoria eliminando el arreglo cuando el sistema sea cerrado
    
    return 0;
}
