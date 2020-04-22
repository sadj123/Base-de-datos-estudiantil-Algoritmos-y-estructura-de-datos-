#include "Student.hpp"

Student::Student(){
  roll_num = 0;
  mat_grade = 0;
  eng_grade = 0;
  spa_grade = 0;
  sci_grade = 0;
  soc_grade = 0;
  average = 0;
}

float Student::calculate_average(){
  average = (mat_grade + eng_grade + spa_grade + sci_grade + soc_grade)/5;
  return average;
}

std::string Student::get_name(){
  return name;
}
int Student::get_roll_num(){
  return roll_num;
}

int Student::get_mat_score(){
  return mat_grade;
}

int Student::get_eng_score(){
  return eng_grade;
}

int Student::get_spa_score(){
  return spa_grade;
}

int Student::get_sci_score(){
  return sci_grade;
}

int Student::get_soc_score(){
  return soc_grade;
}

float Student::get_average(){
  return calculate_average();
}


void Student::output_info(){// maybe it can be done without the override!!!
  std::cout<< "Nombre del estudiante: "<< name <<std::endl;
  std::cout<< "Numero de identificacion: "<< roll_num <<std::endl;
  std::cout<< "Calificacion en matematicas: "<< mat_grade <<std::endl;
  std::cout<< "Calificacion en ingles: "<< eng_grade <<std::endl;
  std::cout<< "Calificacion en espanol: "<< spa_grade <<std::endl;
  std::cout<< "Calificacion en ciencieas naturales: "<< sci_grade <<std::endl;
  std::cout<<"Calificacion en sociales: "<< soc_grade <<std::endl;
  }

  void Student::output_info_simple(){
    std::cout<< name <<std::endl;
    std::cout<< roll_num <<std::endl;
    std::cout<< mat_grade <<std::endl;
    std::cout<< eng_grade<<std::endl;
    std::cout<< spa_grade <<std::endl;
    std::cout<< sci_grade <<std::endl;
    std::cout<< soc_grade <<std::endl;
  }


void Student::input_info(){
  std::cout<< "Ingrese el nombre del estudiante:";
  std::cin.get();
  getline(std::cin,name); //Will get all the characters but nothing else
  std::cout<<"Ingrese el numero de identificacion: ";
  std::cin >> roll_num;
  std::cout << "Ingrese la calificacion en matematicas: ";
  std::cin >> mat_grade;
  std::cout<< "Ingrese la calificacion en ingles: ";
  std::cin >> eng_grade;
  std::cout<< "Ingrese calificacion en espanol: ";
  std::cin >> spa_grade;
  std::cout<< "Ingrese calificacion en ciencieas naturales: ";
  std::cin >> sci_grade;
  std::cout<<"Ingrese calificacion en sociales: ";
  std::cin >> soc_grade;
}

void Student::input_info_simple(){
  std::cin.get();
  getline(std::cin,name);
  std::cin>>name;
  std::cin >> roll_num;
  std::cin >> mat_grade;
  std::cin >> eng_grade;
  std::cin >> spa_grade;
  std::cin >> sci_grade;
  std::cin >> soc_grade;
  }

  std::ostream& operator <<(std::ostream& output, Student& temp){
    temp.output_info();
    return output;
  }
  std::istream& operator >>(std::istream& input, Student& temp){
    temp.input_info();
    return input;
  }
