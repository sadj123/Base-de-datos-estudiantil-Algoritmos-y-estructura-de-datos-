#include <iostream>
#include <fstream>
#include <string>
#include "Database.hpp"

Database::Database(){
  capacity = INITIAL_CAPACITY;
  array = new Student[capacity];
  size = 0;
}

Database::~Database(){
  delete[] array;
}

void Database::operator =(const Database& a){
  capacity = a.capacity;
  size = a.size;
  Student *temp;
  temp = new Student[capacity];
  for(int i = 0; i < capacity; i++){
    temp[i] = array[i];
  }
}

void Database::expand_capacity(){
  int old_capacity = capacity;
  Student *old_array= array;
  capacity *= 2;
  array = new Student[capacity];
  for(int i = 0; i < old_capacity; i++)
    array[i] = old_array[i];
  delete[] old_array;
}

void Database::search_student(std::string name){
  int num_student_found = 0;
  for(int i = 0; i < size; ++i){
    if(array[i].get_name() == name){
      std::cout<<"Estudiante encontrando!"<<std::endl;
      array[i].output_info();
      num_student_found ++;
    }
  }
  if(num_student_found == 0)
    std::cout<<"No se encontro ningun estudiante con ese nombre..."<<std::endl;
}

void Database::search_roll_num(int id){
  int num_student_found = 0;
  for(int i = 0; i < size; ++i){
    if(array[i].get_roll_num() == id){
      std::cout<<"Estudiante encontrando!"<<std::endl;
      array[i].output_info();
      num_student_found ++;
    }
  }
  if(num_student_found == 0)
    std::cout<<"No se encontro ningun estudiante con ese numero de identificacion..."<<std::endl;
}

void Database::add_student(const Student &st){
  if(size >= capacity)
    expand_capacity();
  array[size] = st;
  size++;
}

void Database::display_all(){
  for(int i = 0; i< size; i++)
    array[i].output_info();
}

void Database::delete_student(std::string name){
  for(int i = 0; i < size; i++){
    if(array[i].get_name() == name){
      array[i] = array[size-1];
      size--;
      std::cout<<"El estudiante a sido eliminado del la base de datos!"<<std::endl;
    }
    else{
      std::cout << "Lo sentimos, el estudiante no se encuentra en nuestra base de datos..." <<std::endl;
    }
  }
}
