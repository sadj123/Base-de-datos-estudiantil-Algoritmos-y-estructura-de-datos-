#include <cstdlib>  // para usar la funcion system          es bastante util para la "Interfaz"   no es imprescindibles
#include <conio.h> // para hacer que la contraseña se vea como asteriscos
#include <vector> // para guardar datos
#include <fstream>   //para exportar e importar datos
#include <iostream>
#include <string>
using namespace std;

// a largo del proyecto agregamos la funcion cin.get(), lo que hace es que espera a que el usuario de enter para poder continuar la ejecucion.
// en la funcion system ponemos el comando clear, que funciona en linux y en mac, en la version de windows usamos el comando cls.

void proyecto(string c);       //funcion que presenta el proyecto
string pregunta();             //aqui sabemos tu sistema operativo para hacer mas optimo el codigo
void interfaz(string c);       //funcion para acceder al sistema de notas
void menu(string c);           //menu principal

//todas las funciones reciben un string c como parametro, este string representa "clear" o "cls" esto para poder limpiar la terminal y tener un programa agradable de usar, con codigo fuente de c++

int  main(){
  string c;
  c=pregunta();                        // aqui obtenemos el string c que pasaremos a todas las funciones
  system(c.c_str());
  proyecto(c);
  interfaz(c);
  menu(c);
  return 0;
}

void proyecto(string c){
  system(c.c_str());
  cout << "\n==========================================================================";
  cout << "\n\t ORGANIZADOR DE DATOS ESTDUIANTILES: \n";
  cout << "==========================================================================\n";
  cout << "\t\t PROJECT BY: \n";
  cout << "==========================================================================\n";
  cout << "\n\t  1-Santiago Alvarez\n\t  2-Santiago Diaz \n\t  3-Nicolas Velandia\n";
  cout << "\n==========================================================================";
  cin.get();
  cin.get();
}

string pregunta(){
  cout << "\n\n";
  cout << "==========================================================================\n";
  cout << "                 QUE SISTEMA OPERATIVO USAS ?";
  cout << "\n==========================================================================\n";
  cout << "\n       1.WINDOWS\n       2.LINUX O MAC\n     >>> ";
  int a;
  cin >> a;
  string c;
  if (a == 1){
    c="cls";
  }else if(a == 2){
    c="clear";
  }else{
    cout << "error\n";
    exit(0);
  }
  return c;
}

void interfaz(string c){
  bool id;
  int count;
  string usuario, password;
  char basura;
  id=false;
  count=0;
  vector <string> usuarios;    // vector que contiene los usuarios
  vector <string> passwords;  // vector que contiene las contraseñas

  //usuario PRINCIPAL
  usuarios.push_back("admin");
  passwords.push_back("admin");

  int cursor1;
  cursor1=1;

  while(cursor1 == 1  || cursor1 == 2  || cursor1 == 3  || cursor1 == 23 ){
    system(c.c_str());
    cout << "\n==========================================================================\n";
    cout << "                               MENU PRINCIPAL";
    cout << "\n==========================================================================\n";
    cout << "\n                 1.  Registrar Usuario    \n";
    cout << "\n                 2.  Ingresar    \n";
    cout << "\n                 3.  EXIT    \n";
    cout << "\n                          >>>>>   ";
    cin >> cursor1;


    if(cursor1 == 1){
      system(c.c_str());
      string usuario, password;
      cout << "\n==========================================================================\n";
      cout << "                        ... INTERFAZ DE USUARIO ... ";
      cout << "\n==========================================================================\n";

      cout << "\n\t\t Usuario: ";
      cin >> usuario;
      usuarios.push_back(string(usuario));  // ingresamos el usuario al vector.

      cout << "\t\t Password: ";
      // funcion para hacer que los caracteres se vean como asteriscos
      char caracter;
      caracter = getch();
      password = "";
      while(caracter != 13) { // el 13 representa el caracter enter
        if (caracter != 8){ // el caracter 8 representa el backspace, esto lo hago para poder borrar
          password.push_back(caracter);
          cout << "*";
        }else{ // aqui borramos los asteriscos que imprimimos (pdta; usamos una funcion que vimos en internet para borrar couts de la terminal)
            if(password.length() > 0){
              cout << "\b \b";             // el \b corre el cursor una posicion atras, luego la remplaza por un espacio yleugo corre hacia atras de nuevo
              password.pop_back();        // luego con pop_back elimina de la cadena el caracter que se desea borrar
            }
        }
        caracter = getch();
      }
      passwords.push_back(string(password)); // insertamos la password al vecyor

      cout << "\n==========================================================================\n";
      cout << "                        ... REGISTRO EXITOSO ... ";
      cout << "\n==========================================================================\n";
      cin.get();
      cin.get();

    }else if(cursor1 == 2){
      while(id==false && count < 3){
        system(c.c_str());
        cout << "\n==========================================================================\n";
        cout << "                        ... INTERFAZ DE USUARIO ... ";
        cout << "\n==========================================================================\n";
        if(count == 0){
          cout << "\n           Intento numero 1";
          count ++;
        }else if(count == 1 ){
          cout << "\n           Intento numero 2";
          count ++;
        }else{
          cout << "\n           Intento numero 3";
          count ++;
        }
        cout << "\n\t\t Usuario: ";
        cin >> usuario;
        cout << "\t\t Password: ";
        // funcion para hacer que los caracteres se vean como asteriscos
        char caracter;
        caracter = getch();
        password = "";
        while(caracter != 13) { // el 13 representa el caracter enter
          if (caracter != 8){ // el caracter 8 representa el backspace, este if nos permite borrar
            password.push_back(caracter);
            cout << "*";
          }else{ // aqui borramos los asteriscos que imprimimos (pdta; usamos una funcion que vimos en internet para borrar couts de la terminal)
              if(password.length() > 0){
                cout << "\b \b";             // el \b corre el cursor una posicion atras, luego la remplaza por un espacio y luego corre hacia atras de nuevo
                password.pop_back();        // luego con pop_back elimina de la cadena el caracter que se desea borrar
              }
          }
          caracter = getch();
        }
        // recorremos el vector y buscamos el usuario, si no coincide salimos del ciclo, si coincide comparamos la contraseña
        for(int i= 0; i< usuarios.size(); i++){
          if(passwords[i]==password && usuarios[i]==usuario){
            id = true;
            break;
          }
        }
        if (id == false){
          cout << "\n==========================================================================\n";
          cout << "\t\t... USUARIO Y/O CONTRASENIA INCORRECTOS ... ";
          cout << "\n==========================================================================\n";
          if (count < 3){
            system("pause");
          }
          while(basura != 13){
            basura = getch();         // evita que escribamos basura en la terminal
          }
        }
      }

      if (id == true){
        cout << "\n==========================================================================\n";
        cout << "\t\t... INGRESO CORRECTO ... ";
        cout << "\n==========================================================================\n";
        cin.get();
        cin.get();
        break;

      }else{
        system(c.c_str());
        cout << "\n==========================================================================\n";
        cout << "\t\t... DEMASIADOS INTENTOS FALLIDOS ... ";
        cout << "\n\t\t    ... CERRANDO EL PROGRAMA ... ";
        cout << "\n==========================================================================\n";
        cin.get();
        exit(0);
      }

    }else if(cursor1 == 3){
      cout << "\n==========================================================================\n";
      cout << "                  ... Gracias por usar el programa ... ";
      cout << "\n==========================================================================\n";
      cin.get();
      exit(0);

    }else{
      cout << "\n==========================================================================\n";
      cout << "                               ... ERROR ... ";
      cout << "\n==========================================================================\n";
      cin.get();
      cin.get();
      exit(0);
    }
  }
}

void menu(string c){
  system(c.c_str());
  cout << "\n==========================================================================\n";
  cout << "                      ... Bienvenido profesor ... ";
  cout << "\n==========================================================================\n";
  cin.get();
  int cursor2;
  cursor2 = 1;
  while (cursor2 == 1 || cursor2 == 2 || cursor2 == 3 || cursor2 == 4 || cursor2 == 5 || cursor2 == 6){
    system(c.c_str());
    cout << "\n==========================================================================\n";
    cout << "                            MENU DE USUARIO";
    cout << "\n==========================================================================\n";
    cout << "\n                 1.  Ver lista de estudiantes   \n";
    cout << "\n                 2.  Ingresar o editar datos    \n";
    cout << "\n                 3.  ver calificaciones del curso    \n";
    cout << "\n                 4.  ingresar estudiante nuevo    \n";
    cout << "\n                 5.  EXIT    \n";
    cout << "\n                          >>>>>   ";
    cin >> cursor2;

    if (cursor2 == 5){
      cout << "\n==========================================================================\n";
      cout << "                  ... Gracias por usar el programa ... ";
      cout << "\n==========================================================================\n";
      system("pause");
      exit(0);
    }

    else if(cursor2 == 1){
      ifstream datos;
      string texto;
      datos.open("students.txt",ios::in); //solo lo quiero leer
      if(datos.fail()){
        cout << "\n=============================================================================\n";
        cout << "                      ... ERROR NO HAY DATOS GUARDADOS ...";
        cout << "\n=============================================================================\n";
        system("pause");
      }else{
        system(c.c_str());
        cout << "=================================================================================";
        cout << "\n                           LSITA DE ESTUDIANTES\n";
        cout << "=================================================================================\n\n";
        while(!datos.eof()){
          getline(datos,texto);
          cout << texto << endl;
        }
        system("pause");
      }
    }

    else if(cursor2 == 3){
      ifstream datos;
      string texto;
      datos.open("students_val.txt",ios::in); //solo lo quiero leer
      if(datos.fail()){
        cout << "\n=============================================================================\n";
        cout << "                      ... ERROR NO HAY DATOS GUARDADOS ...";
        cout << "\n=============================================================================\n";
        system("pause");
      }else {
        system(c.c_str());
        while(!datos.eof()){
          getline(datos,texto);
          cout << texto << endl;
        }
        system("pause");
      }
    }
    else if(cursor2 == 4){
      ofstream datos;
      string name;
      system(c.c_str());
      datos.open("students.txt", ios::app); // añadir estudiantes

      if(datos.fail()){
        cout << "\n=============================================================================\n";
        cout << "                      ... ERROR NO HAY DATOS GUARDADOS ...";
        cout << "\n=============================================================================\n";
        exit(0);
      }

      cout << "================================================================================\n";
      cout << "\n                 ingrese el nombre del estudinate: ";
      cout << "\n                                               >>>>>> ";
      cin.get();
      getline(cin,name);
      datos << "-" << name << endl;
      datos.close();
      cout << "\n=================================================================================\n";
      cout << "                      ESTUDIANTE REGISTRADO EN LA BASE DE DATOS";
      cout << "\n=================================================================================\n";
      system("pause");
    }

    else{
      cin.get();
      cout << "\n==========================================================================\n";
      cout << "                     ESTAMOS TRABAJANDO EN ELLO";
      cout << "\n==========================================================================\n";
      system("pause");
    }
  }
}
