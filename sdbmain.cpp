#include<iostream>
#include<string>
#include<fstream>
#include "Database.hpp"
#include "Student.hpp"

int start_up_menu(){
  int choice;
  std::cout<<"1. Ver datos de los estudiantes"<<std::endl;
  std::cout<<"2. Buscar estudiante por nombre"<<std::endl;
  std::cout<<"3. Buscar estudiante por numero de identificacion"<<std::endl;
  std::cout<<"4. Agregar datos de un estudiante"<<std::endl;
  std::cout<<"5. Borrar estudiante"<<std::endl;
  std::cout<<"6. EXIT"<<std::endl;
  std::cin>>choice;
  return choice;
}

int main(){
  Database db;
  Student st;
  std::string file;
  std::string file_name;
  int choice = 0;
  while(choice != 6){
    choice = start_up_menu();
    switch(choice){
      case 1:{
        std::cout<<"Todos los estudiantes"<<std::endl;
        db.display_all();
        break;
      }
      case 2:{
        system("cls");
        std::string name;
        std::cout <<"Ingrese el nombre del estudiante: ";
        std::cin.get();
        getline(std::cin,name);
        db.search_student(name);
        break;
      }
      case 3:{
        system("cls");
        int id;
        std::cout <<"Ingrese el numero de identificacion del estudiante: ";
        std::cin>>id;
        db.search_roll_num(id);
        break;
      }
      case 4:{
        system("cls");
        std::cin >> st;
        db.add_student(st);
        break;
      }
      case 5:{
        system("cls");
        std::string name;
        std::cout<<"Por favor ingrese el nombre del estudiante que quiere borrar: ";
        std::cin.get();
        getline(std::cin,name);
        db.delete_student(name);
        break;
      }
      case 6:{
        break;
      }
    }
  }
}
