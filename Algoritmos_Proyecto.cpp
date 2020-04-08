#include "Algoritmos_Proyecto.hpp"

Estudiante::Estudiante(){
  num_estudiante = 0;
  c_mat = 0;
  c_ing = 0;
  c_esp = 0;
  c_cien = 0;
  c_soc = 0;
  promedio = 0;
}

void Estudiante::calcular_promedio(){
  promedio = (c_mat+c_ing+c_esp+c_cien+c_soc)/5;
}

int Estudiante::get_id(){
  return num_estudiante;
}

int Estudiante::get_mat_score(){
  return c_mat;
}

int Estudiante::get_ing_score(){
  return c_ing;
}

int Estudiante::get_esp_score(){
  return c_esp;
}

int Estudiante::get_cien_score(){
  return c_cien;
}

int Estudiante::get_soc_score(){
  return c_soc;
}

float Estudiante::get_average(){
  return calcular_promedio()
}

void Estudiante::output(std::ostream& out){
  if(outs == cout){
    outs<< "Nombre del estudiante: "<< nombre<<std::endl;
    outs<< "Numero de identificacion: "<< num_estudiante<<std::endl;
    outs<< "Calificacion en matematicas: "<< c_mat<<std::endl;
    outs<< "Calificacion en ingles: "<< c_ing<<std::endl;
    outs<< "Calificacion en espanol: "<< c_esp<<std::endl;
    outs<< "Calificacion en ciencieas naturales: "<< c_cien<<std::endl;
    outs<<"Calificacion en sociales: "<<c_soc<<std::endl;
  }
  else{
    outs<< nombre<<std::endl;
    outs<< num_estiante<<std::endl;
    outs<< c_mat<<std::endl;
    outs<< c_ing<<std::endl;
    outs<< c_esp<<std::endl;
    outs<< c_cien<<std::endl;
    outs<< c_soc<<std::endl;
  }
}
void Estudiante::input(std::istream& ins){
  if (ins == cin){
    if(ins.peek() == "\n")
      ins.ignore();
    std::cout<< "Ingrese el nombre del estudiante: ";
    getline(ins,nombre);
    std::cout<<" Ingrese el numero de identificacion: ";
    ins >> num_estudiante;
    std::cout << "Ingrese la calificacion en matematicas: ";
    ins >> c_mat;
    std::cout<< "Ingrese la calificacion en ingles: ";
    ins>>c_ing;
    std::cout<< "Ingrese calificacion en espanol: ";
    ins >> c_esp;
    std::cout<< "Ingrese calificacion en ciencieas naturales: ";
    ins >> c_cien;
    std::cout<<"Ingrese calificacion en sociales: ";
    ins >> c_soc;
  }
  else{
    if(ins.peek() == "\n")
      ins.ignore();
    getline(ins,nombre);
    ins >> num_estudiante;
    ins >> c_mat;
    ins>>c_ing;
    ins >> c_esp;
    ins >> c_cien;
    ins >> c_soc;
  }
}

std::ostream& operator <<(std::ostream& outs, Estudiante& temp){
  temp.output(outs);
  return outs;
}
std::istream& operator >>(std::istream& ins, Estudiante& temp){
  temp.input(ins);
  return ins;
}
