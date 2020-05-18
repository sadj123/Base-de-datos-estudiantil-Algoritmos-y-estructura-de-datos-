#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "Database.hpp"

void Database_map::save_data(){
  std::ofstream archive;
  archive.open("Boletin.txt");
  if(!empty()){
    archive<<"COURSE GRADES \n";
    for(int i= 0; i<count; ++i){
      archive<<'\t'<<i+1<<". "<<array[i].name<<'\n';
      archive<<'\t'<<'\t'<< "English = " << (array[i].value).average_eng() << '\n';
      archive<<'\t'<<'\t'<< "Mathematics = " << (array[i].value).average_math() << '\n';
      archive<<'\t'<<'\t'<< "Spanish = " << (array[i].value).average_spa() << '\n';
      archive<<'\t'<<'\t'<< "Science = " << (array[i].value).average_sci() << '\n';
      archive<<'\t'<<'\t'<< "History = " << (array[i].value).average_his() << '\n';
      archive<<'\t'<< "Total Average >>" << (array[i].value).average_final() << '\n';
      archive<<std::endl;
    }
  }
}

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
  std::cout<<"capacity expanded!"<<std::endl;
}

int Database_map::index(std::string name){
  for(int i= 0; i<count; ++i){
    if(array[i].name== name)
      return i;
    }
    return -1;
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
else{
system("color 0c");
   std::cout<<"THE STUDENT IS ALREADY IN THE DATABASE \n";
   system("pause");
   system("color 0f");

}}

void Database_map::delete_student(std::string name){
  if(!is_in(name)){
    system("color 0c");
    std::cout<< "ATTEMPTING TO REMOVE A STUDENT THAT DOESN'T EXISTS \n";
    system("pause");
    system("color 0f");
  }
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
  if(!empty()){
    std::cout<<"NAME \n";
    for(int i= 0; i<count; ++i){
      std::cout<<'\t'<<i+1<<". "<<array[i].name<<'\n';
    }
  }
  else{
    std::cout<<"There are no students within the database!"<<std::endl;
  }
}
void Database_map::display_course(){
  if(!empty()){
    std::cout<<"COURSE GRADES \n";
    for(int i= 0; i<count; ++i){
      std::cout<<'\t'<<i+1<<". "<<array[i].name<<'\n';
      std::cout<<'\t'<<'\t'<< "English = " << (array[i].value).average_eng() << '\n';
      std::cout<<'\t'<<'\t'<< "Mathematics = " << (array[i].value).average_math() << '\n';
      std::cout<<'\t'<<'\t'<< "Spanish = " << (array[i].value).average_spa() << '\n';
      std::cout<<'\t'<<'\t'<< "Science = " << (array[i].value).average_sci() << '\n';
      std::cout<<'\t'<<'\t'<< "History = " << (array[i].value).average_his() << '\n';
      std::cout<<'\t'<<'\t'<< '\t' << "Total Average >>" << (array[i].value).average_final() << '\n';
      std::cout<<std::endl;
    }
  }
  else{
    std::cout<<"There are no students within the database!"<<std::endl;
  }
}

void Database_map::display_student(std:: string name){
  int id= index(name);
  if(id == -1){
    system("color 0c");
    std::cout<<"This student is not in our database!"<<std::endl;
  }
  else{
    std::cout<<std::endl;
    std::cout<<"STUDENT: "<<array[id].name<<std::endl;
    std::cout<<"GRADES"<<std::endl;
    std::cout<<'\t'<<"1. English average: "<<(array[id].value).average_eng()<<std::endl;
    std::cout<<'\t'<<"2. History average: "<<(array[id].value).average_his()<<std::endl;
    std::cout<<'\t'<<"3. Science average: "<<(array[id].value).average_sci()<<std::endl;
    std::cout<<'\t'<<"4. Spanish average: "<<(array[id].value).average_spa()<<std::endl;
    std::cout<<'\t'<<"5. Mathematics average: "<<(array[id].value).average_math()<<std::endl;
    std::cout <<'\n'<<"TOTAL AVERAGE: "<<(array[id].value).average_final()<<std::endl;
  }
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

double Database_map::get_total_average(std::string name){
  int id = index(name);
  return array[id].value.average_final();
}
