#include <iostream>
#include<string>
using namespace std;

//Estructura de estudiantes
struct estudiantes {
    int codigo = 0;
    string nombre;
    string apellido;
    string residencia;
    double promedio = 0;
    bool beca = 0;
    int edad = 0;
};


//Función para obtener qué opción desea el usuario administrador
char opciones() {
    char op;
    cout << endl << "<--------------------GESTION DE ESTUDIANTES-------------------->" << endl;
    cout << "a) Gestionar estudiantes" << endl;
    cout << "b) Reporte de estudiantes con el municipio al que pertenecen y si superan un promedio en concreto" << endl;
    cout << "c) Estudiantes con mayor promedio" << endl;
    cout << "d) Lista de estudiantes con promedio ascendente" << endl;
    cout << "e) Listado de estudiantes con beca" << endl;
    cout << "f) Regresar a modulos" << endl;
    cout << "Selecione una opcion: ";
    cin >> op;
    return(op);
};

//Funcion para mostrar estudiantes
void  mostrarEstudiantes(estudiantes* estudiantess, int n) {
    int contador = 0;
    cout << endl;

    //Recorre el arreglo de estudiantes para imprimir la información de cada uno
    for (int i = 0; i < n; i++) {
        contador++;
        estudiantes* p = &estudiantess[i];
        cout << contador << ". " << p->codigo << " - " << p->nombre << " - " << p->apellido << " - " << p->residencia << " - " << p->promedio << " - " << p->beca << " - " << p->edad << endl;
    }
};

//Funcion para actualizar información de estudiantes
void actualizarEstudiantes(int x /*codigo del estudiante*/, estudiantes* estudiantess, int n) {
    int op = 0;

    //Bucle hasta que el sistema saque al usuario
    while (op == 0) {

        //Con el parámetro "x" el sistema verifica a qué estudiante pertenece el código brindado
        for (int i = 0; i < n; i++) {
            estudiantes* p = &estudiantess[i];
            if (x == p->codigo) {
                char y;
                cout << "a) Codigo" << endl;
                cout << "b) Nombre" << endl;
                cout << "c) Apellido" << endl;
                cout << "d) Residencia" << endl;
                cout << "e) Promedio" << endl;
                cout << "f) Beca" << endl;
                cout << "g) Edad " << endl;
                cout << "Que informacion desea actualizar: ";
                cin >> y;

                //Dependiendo de la respuesta del usuario, se solicitará y guardará la nueva información
                switch (y)
                {
                case 'a':
                    cout << "Ingrese el nuevo codigo: ";
                    cin >> p->codigo;
                    break;
                case 'b':
                    cout << "Ingrese el nuevo nombre: ";
                    getline(cin, p->nombre);
                    break;
                case 'c':
                    cout << "Ingrese el nuevo apellido: ";
                    getline(cin, p->apellido);
                    break;
                case 'd':
                    cout << "Ingrese el nuevo residencia: ";
                    getline(cin, p->residencia);
                    break;
                case 'e':
                    cout << "Ingrese él nuevo promedio: ";
                    cin >> p->promedio;
                    break;
                case 'f':
                    cout << "Ingrese si tiene beca (1) o no (0): ";
                    cin >> p->beca;
                    break;
                case 'g':
                    cout << "Ingrese la nueva edad: ";
                    cin >> p->edad;
                    break;

                    //Son los mismos casos pero con mayúscula, pues el usuario puede confundirse y no solo poner minúsculas
                case 'A':
                    cout << "Ingrese el nuevo codigo: ";
                    cin >> p->codigo;
                    break;
                case 'B':
                    cout << "Ingrese el nuevo nombre: ";
                    cin >> p->nombre;
                    break;
                case 'C':
                    cout << "Ingrese el nuevo apellido: ";
                    cin >> p->apellido;
                    break;
                case 'D':
                    cout << "Ingrese el nuevo residencia: ";
                    cin >> p->residencia;
                    break;
                case 'E':
                    cout << "Ingrese él nuevo promedio: ";
                    cin >> p->promedio;
                    break;
                case 'F':
                    cout << "Ingrese si tiene beca (1) o no (0): ";
                    cin >> p->beca;
                    break;
                case 'G':
                    cout << "Ingrese la nueva edad: ";
                    cin >> p->edad;
                    break;
                }
                //Cuando se culmina sacamos automáticamente al sistema del bucle for, de tal forma que no se repita
                i = n;
                break;
            }
        }
        //Verificamos si el usuario desea cambiar alguna otra información del estudiante seleccionado
        int z;
        cout << endl << "1. Si" << endl << "2. No" << endl << "Desea cambiar otra informacion? ";
        cin >> z;

        //Si su respuesta es no, entonces lo sacamos del while y culmina la función. Si su respuesta es sí, se repite todo el proceso
        if (!(z == 1)) {
            break;
        }
    }
}

//Función para añadir estudiantes
estudiantes* anadirEstudiantes(estudiantes* estudiantess, int n, int k) {
    int a = n + k; // n es el tamaño original del array y k los estudiantes a agregar
    int codigo, edad;
    string nombre, apellido, residencia;
    double promedio;
    bool beca;
    estudiantes* estudiantes2 = new estudiantes[a]; // Creamos un arreglo nuevo con la nueva cantidad de alumnos

    for (int i = 0; i < n; i++) {
        estudiantes2[i] = estudiantess[i]; //Copiamos los elementos del arreglo enviado, al nuevo
    }

    //Dependiendo de los que quiera agregar, entonces hacemos el bucle para colocar la infomación
    for (int i = k; i > 0; i--) {
        cout << endl << "Ingrese el codigo: ";
        cin >> codigo;
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el apellido: ";
        cin >> apellido;
        cout << "Ingrese la residencia: ";
        cin >> residencia;
        cout << "Ingrese el promedio: ";
        cin >> promedio;
        cout << "Ingrese la disponibilidad de beca (1 = si / 0 = no): ";
        cin >> beca;
        cout << "Ingrese la edad: ";
        cin >> edad;
        estudiantes2[a - i] = { codigo, nombre, apellido, residencia, promedio, beca, edad }; // colocamos la información en los espacios nuevos
    }

    mostrarEstudiantes(estudiantes2, a); // Mostrar todos los estudiantes, incluyendo los nuevos
    estudiantess = new estudiantes[a]; //actualizamos el espacio del array estudiantes original
    for (int i = 0; i < a; i++) {
        estudiantess[i] = estudiantes2[i];  //copiamos de nuevo la información 
    }

    return(estudiantess); // retornamos el arreglo estudiantes con los nuevos estudiantes
}

estudiantes* eliminarEstudiantes(estudiantes* estudiantess, int n, int k) {
    int j = 0; //Inicalizamos J para poder guardar el código del estudiante a eliminar
    mostrarEstudiantes(estudiantess, n); //mostramos el arreglo para que el usuario sepa los códigos

    for (int l = 0; l < k; l++) {
        cout << endl << "Ingrese el codigo del alumno que desea eliminar: "; //el bucle funciona de acuerdo a los alumnos que se quieren eliminar
        cin >> j;
        for (int i = 0; i < n; i++) { //recorremos el arreglo original para ver que alumno tiene el código ingresado
            if (estudiantess[i].codigo == j) {
                for (int j = i; j < n - 1; j++) {
                    estudiantess[j] = estudiantess[j + 1]; //una vez lo encuentre hacemos que el arreglo se mueva una posición, de tal forma que se borre el deseado
                }
                n--; //reducimos en tamaño del arreglo  para evitar espacios vacíos
                break;
            }
        }
        mostrarEstudiantes(estudiantess, n); //mostramos el nuevo arreglo 
    }
    return estudiantess; //mandamos el nuevo arreglo
}

//Función para filtrado de alumnos de acuerdo a las condiciones dadas
void opcionB(string municipio, int promedio, estudiantes* estudiantess, int n) {

    //Creamos un for para recorrer el arreglo de la estructura mediante un puntero e imprimimos los elementos que cumplan con promedio y municipio establecido
    int contador = 0;
    cout << endl << "<--------------------REPORTE-------------------->" << endl << endl;
    for (int i = 0; i < n; i++) {
        estudiantes* p = &estudiantess[i];
        if (p->residencia == municipio && p->promedio >= promedio) {
            contador++;
            cout << contador << ". " << p->nombre << " " << p->apellido << " - " << p->residencia << " - " << p->promedio << endl;
        }
    }
};

//Función para ver quiénes tienen el mayor promedio
estudiantes* ordenarAlumnos(estudiantes* estudiantess, int n) {

    // Ordenamos los estudiantes en cuanto a su promedio
    for (int j = n - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            estudiantes* p = &estudiantess[i];
            estudiantes* k = &estudiantess[i + 1];
            if (p->promedio < k->promedio) {
                // Intercambiamos los datos de los estudiantes para colocar detrás al de mayor promedio y delante al de menor
                estudiantes temp = *p;
                *p = *k;
                *k = temp;
            }
        }
    }

    // Creamos una nueva estructura estudiantes ordenada con los datos de estudiantes de mayor a menor promedio
    estudiantes* estudiantesOrdenados = new estudiantes[n];
    for (int i = 0; i < n; i++) {
        estudiantesOrdenados[i] = estudiantess[i];
    }

    // Devolvemos un puntero a la estructura estudiantes ordenada
    return estudiantesOrdenados;
}

//Funcion para imprimir los mejores promedios
void opcionC(int cantidadAlumnos, estudiantes* estudiantess, int n) {
    int contador = 0;
    estudiantes* p = ordenarAlumnos(estudiantess, n);

    //Dependiendo del parámetro dado, esa será la cantidad de estudiantes a mostrar
    for (int i = 0; i < cantidadAlumnos; i++) {
        estudiantes* p = &estudiantess[i];
        contador++;
        cout << contador << ". " << p->nombre << " " << p->apellido << " - " << p->residencia << " - " << p->promedio << endl;
    }
};

//Función para verificar si los alumnos tienen beca
void opcionE(estudiantes* estudiantess, int n) {

    //Creamos un for para recorrer el arreglo de la estructura mediante un puntero e imprimimos los elementos que cumplan con tener beca
    int contador = 0;
    cout << endl << "<--------------------REPORTE-------------------->" << endl << endl;
    for (int i = 0; i < n; i++) {
        estudiantes* p = &estudiantess[i];
        if (p->beca == 1) {
            contador++;
            cout << contador << ". " << p->nombre << " " << p->apellido << " - " << p->residencia << " - " << p->promedio << endl;
        }
    }
};

int main() {
    //<------------MÓDULO ESTUDIANTES------------>
     //Información de estudiantes

    cout << "Hola";
    int tam0 = 20;
    estudiantes* estudiantess = new estudiantes[tam0];
    estudiantess[0] = { 1001, "Juan", "Gonzalez", "Guatemala", 95.5, true, 20 };
    estudiantess[1] = { 1002, "Maria", "Hernandez", "Villa Nueva", 87.2, false, 19 };
    estudiantess[2] = { 1003, "Pedro", "Lopez", "San Lucas", 91.8, true, 21 };
    estudiantess[3] = { 1004, "Ana", "Garcia", "Guatemala", 84.3, false, 20 };
    estudiantess[4] = { 1005, "Carlos", "Martinez", "Fraijanes", 88.9, true, 22 };
    estudiantess[5] = { 1006, "Sofia", "Gomez", "San Lucas", 82.1, false, 19 };
    estudiantess[6] = { 1007, "Ricardo", "Sanchez", "Villa Nueva", 93.7, true, 20 };
    estudiantess[7] = { 1008, "Diana", "Flores", "Guatemala", 85.6, false, 21 };
    estudiantess[8] = { 1009, "Gabriel", "Ramirez", "Fraijanes", 90.2, true, 19 };
    estudiantess[9] = { 1010, "Laura", "Gutierrez", "Mixco", 86.5, false, 20 };
    estudiantess[10] = { 1011, "Fernando", "Torres", "Mixco", 92.1, true, 21 };
    estudiantess[11] = { 1012, "Paola", "Reyes", "Fraijanes", 83.4, false, 19 };
    estudiantess[12] = { 1013, "Jorge", "Ramos", "San Lucas", 89.3, true, 22 };
    estudiantess[13] = { 1014, "Isabella", "Alvarez", "Guatemala", 94.2, false, 20 };
    estudiantess[14] = { 1015, "Manuel", "Mendoza", "Villa Nueva", 81.7, true, 21 };
    estudiantess[15] = { 1016, "Valeria", "Castillo", "Mixco", 87.9, false, 19 };
    estudiantess[16] = { 1017, "Eduardo", "Chavez", "San Lucas", 90.8, true, 22 };
    estudiantess[17] = { 1018, "Carolina", "Vargas", "Villa Nueva", 84.1, false, 20 };
    estudiantess[18] = { 1019, "Luis", "Gonzalez", "Fraijanes", 88.6, true, 21 };
    estudiantess[19] = { 1020, "Monica", "Gonzalez", "Mixco", 92.5, false, 19 };



    int opp1 = 0;
    int tam = 20;

    while (opp1 == 0) {
        //Llamamos la función opciones para saber que opción quiere y verificamos cual quiere con un if y así ejecutar dicha opción
        char opp = opciones();

        if (opp == 'a' || opp == 'A') {
            //Desplegamos un menú para que decida que opción desea
            char y;
            int opp2 = 0;
            cout << endl << "a) Actualizar estudiante" << endl;
            cout << "b) Agregar estudiante" << endl;
            cout << "c) Eliminar estudiante" << endl;
            cout << "Elija la opcion que desee: ";
            cin >> y;

            //Dependiendo de la opciónd desea, esta sera la función a solicitar
            if (y == 'a' || y == 'A') {
                int x;
                mostrarEstudiantes(estudiantess, tam);

                //Repetimos el ciclo hasta que elija un código válido
                while (opp2 == 0) {
                    //Solicitamos que indique el código del estudiante
                    cout << endl << "Coloque el codigo del estudiante que desea actualizar informacion: ";
                    cin >> x;

                    //Verificamos si ese código existe
                    for (int i = 0; i < tam; i++) {
                        estudiantes* p = &estudiantess[i];
                        if (x == p->codigo) {
                            //Actualizamos info
                            actualizarEstudiantes(x, estudiantess, tam);

                            //Mostramos
                            mostrarEstudiantes(estudiantess, tam);
                            cout << endl;

                            //Forzamos salida del for
                            i = tam;

                            //Forzamos salida del while y evitamos el la condición siguiente
                            opp2 = 1;
                        }
                    }

                    //En caso que no exista, se mostramos el mensaje no válido
                    if (opp2 == 0) {
                        cout << "Ingrese un codigo valido" << endl;
                    }
                }
            }
            else if (y == 'b' || y == 'B') {
                int nuevo_tam;
                int k;
                cout << "Ingrese la cantidad de alumnos que desea ingresar al sistema: ";
                cin >> k;
                nuevo_tam = k + tam;
                mostrarEstudiantes(estudiantess, tam);
                //Mandamos a llamar la función de añadir
                estudiantes* estudiantess2 = anadirEstudiantes(estudiantess, tam, nuevo_tam - tam);

                // Liberar memoria del arreglo original
                delete[] estudiantess;

                // Actualizar el tamaño del arreglo y apuntar a la nueva dirección de memoria
                tam = nuevo_tam;
                estudiantess = estudiantess2; //colocamos la info de estudiantes 2 en estudiantess

                // Mostrar el arreglo actualizado
                mostrarEstudiantes(estudiantess, tam);
            }

            else if (y == 'c' || y == 'C') {
                int q;
                cout << "Ingrese la cantidad de estudiantes que desea eliminar: ";
                cin >> q;
                eliminarEstudiantes(estudiantess, tam, q);
                tam = tam - q; //Actualizamos el tamaño del array

            }
            else {
                cout << "Elija una opción adecuada";
            }

        }
        else if (opp == 'b' || opp == 'B') {
            int promedio;
            string municipio;
            cout << endl << "Porfavor especifique los siguientes datos" << endl;
            cin.ignore();
            cout << "Municipio: ";
            getline(cin, municipio);
            cout << "Promedio mayor a: ";
            cin >> promedio;

            //Llamamos la función opciónA con el municipio y promedio deseado, además le enviamos el arreglo de estudiantess indicando el tamaño del arreglo
            opcionB(municipio, promedio, estudiantess, tam);

        }
        else if (opp == 'c' || opp == 'C') {
            int cantidadAlumnos;
            cout << endl << "Indique la cantidad de alumnos que la listaa debe contener: ";
            cin >> cantidadAlumnos;

            //mandamos a llamar la funcion para ejecutar el reporte con las especificaciones del usario
            opcionC(cantidadAlumnos, ordenarAlumnos(estudiantess, tam), tam);

        }
        else if (opp == 'd' || opp == 'D') {
            int contador = 0;
            ordenarAlumnos(estudiantess, tam);
            for (int i = 0; i < tam; i++) {
                estudiantes* p = &estudiantess[i];
                contador++;
                cout << contador << ". " << p->codigo << " - " << p->apellido << " - " << p->nombre << " - " << p->promedio << endl;
            }

        }
        else if (opp == 'e' || opp == 'E') {
            opcionE(estudiantess, tam);

        }
        else if (opp == 'f' || opp == 'F') {
            break;
            //Regresar a modulos
        }
        else {
            cout << "Porfavor ingrese una opcion disponile" << endl << endl;
        }
    }

    //MÓDULO MAESTROS
    //MÓDULO ADMINISTRADOR
    //EJECUCIÓN DEL PROGRAMA





}
