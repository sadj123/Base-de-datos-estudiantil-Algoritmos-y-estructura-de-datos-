#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Database.hpp"



Database_map::Database_map(){
  capacity= INITIAL_CAPACITY;
  array= new Key_value[capacity];
  count= 0;

}

Database_map::~Database_map(){
  delete[] array;
}
bool Database_map::is_in(std::string name){
  for(int i= 0; i<count; ++i){
    if(array[i].name== name)
      return true;
    }
    return false;
}

void Database_map::expand_capacity(){
  int old_capacity = capacity;
  Key_value *old_array= array;
  capacity *= 2;
  array = new Key_value[capacity];
  for(int i = 0; i < old_capacity; i++)
    array[i] = old_array[i];
  delete[] old_array;
}

int Database_map::index(std::string name){
  for(int i= 0; i<count; ++i){
    if(array[i].name== name)
      return i;
    }
    return 0;
}

int Database_map::size(){
  return count;
}

bool Database_map::empty(){
  return count==0;
}

void Database_map::insert_student(std::string name){
  if(!is_in(name)){
  if(count!= capacity){
  Key_value celd;
  celd.name= name;
  Student second_celd;
  celd.value= second_celd;
  array[count]= celd;
  count += 1;

}
else {
  expand_capacity();
  insert_student(name);
}

}
else
  throw std::runtime_error("THE STUDENT IS ALREADY IN THE DATABASE \n");

}

void Database_map::delete_student(std::string name){
  if(!is_in(name))
    throw std::runtime_error("ATTEMPTING TO REMOVE A STUDENT THAT DOESN´T EXISTS \n");
  else{
    int ind=index(name);
    if(ind == count-1)
      --count;
    else{
      Key_value temp= array[ind];
      array[ind]=array[count-1];
      array[count-1]= temp;
      delete_student(name);
    }
  }
}
void Database_map::display_all(){
  std::cout<<"NAME \n";
  for(int i= 0; i<count; ++i){
    std::cout<<'\t'<<i+1<<". "<<array[i].name<<'\n';
  }
}
void Database_map::display_student(std:: string name){
  int id= index(name);
  std::cout<<"STUDENT: "<<array[id].name<<std::endl;
  std::cout<<"NOTES"<<std::endl;
  std::cout<<'\t'<<"1. English average: "<<(array[id].value).average_eng()<<std::endl;
  std::cout<<'\t'<<"2. History average: "<<(array[id].value).average_his()<<std::endl;
  std::cout<<'\t'<<"3. Science average: "<<(array[id].value).average_sci()<<std::endl;
  std::cout<<'\t'<<"4. Spanish average: "<<(array[id].value).average_spa()<<std::endl;
  std::cout<<'\t'<<"5. Mathematics average: "<<(array[id].value).average_math()<<std::endl;
}
void Database_map::disp_math(std:: string name){
  int id= index(name);
  (array[id].value).display_math();
}
void Database_map::disp_spa(std:: string name){
  int id= index(name);
  (array[id].value).display_spa();
}
void Database_map::disp_sci(std:: string name){
  int id= index(name);
  (array[id].value).display_sci();
}
void Database_map::disp_eng(std:: string name){
  int id= index(name);
  (array[id].value).display_eng();
}
void Database_map::disp_his(std:: string name){
  int id= index(name);
  (array[id].value).display_his();
}
void Database_map::clear(){
    count =0;
  }
void Database_map::push_note(std::string name, double note, std::string subject){
  int id= index(name);
  array[id].value.insert_note(subject, note);

}

/*
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
*/
