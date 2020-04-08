#ifndef _ESTUDIANTE_HPP
#define _ESTUDIANTE_HPP

#include<iostream>
#include<fstream>
#include<string>

class Estudiante{
private:
  std::string nombre;
  int num_estudiante;
  int c_mat, c_ing, c_esp, c_cien, c_soc;
  float promedio;
  void calcular_promedio();

public:
  Estudiante();
  ~Estudiante(){};
  std::string get_name();
  int get_id();
  int get_mat_score();
  int get_ing_score();
  int get_esp_score();
  int get_cien_score();
  int get_soc_score();
  float get_average();
  void output(std::ostream& out);
  void input(std::istream& ins);
};

std::ostream& operator <<(std::ostream, Estudiante& temp);
std::istream& operator >>(std::istream, Estudiante& temp);

#endif
