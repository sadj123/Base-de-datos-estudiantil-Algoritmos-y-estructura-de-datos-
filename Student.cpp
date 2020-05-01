#include "Student.hpp"
Student::Student(){
  eng.notes= new double[1];
  eng.count= 0;
  spa.notes= new double[1];
  spa.count= 0;
  sci.notes= new double[1];
  sci.count= 0;
  his.notes= new double[1];
  his.count= 0;
  math.notes= new double[1];
  math.count= 0;

}

Student::~Student(){
  delete[] eng.notes;
  delete[] spa.notes;
  delete[] sci.notes;
  delete[] his.notes;
  delete[] math.notes;
}

double Student::average_eng(){
  double aver= 0;
  for(int i=0; i<eng.count; ++i)
    aver+=eng.notes[i];
  return aver/eng.count;
}
double Student::average_sci(){
  double aver= 0;
  for(int i=0; i<sci.count; ++i)
    aver+=sci.notes[i];
  return aver/sci.count;
}
double Student::average_his(){
  double aver= 0;
  for(int i=0; i<his.count; ++i)
    aver+=his.notes[i];
  return aver/his.count;
}
double Student::average_math(){
  double aver= 0;
  for(int i=0; i<math.count; ++i)
    aver+=math.notes[i];
  return aver/math.count;
}
double Student::average_spa(){
  double aver= 0;
  for(int i=0; i<spa.count; ++i)
    aver+=spa.notes[i];
  return aver/spa.count;
}
double Student::average_final(){
  return (average_spa()+ average_math()+average_his()+average_sci()+average_eng())/5;
}

void Student::display_eng(){
  std::cout<<"English grades are: ";
  for(int i=0; i<eng.count; ++i)
    std::cout << eng.notes[i]<<" ";
  std::cout<<'\n';
}
void Student::display_his(){
  std::cout<<"History grades are: ";
  for(int i=0; i<his.count; ++i)
    std::cout << his.notes[i]<<" ";
  std::cout<<'\n';
}
void Student::display_sci(){
  std::cout<<"Science grades are: ";
  for(int i=0; i<sci.count; ++i)
    std::cout << sci.notes[i]<<" ";
  std::cout<<'\n';
}
void Student::display_math(){
  std::cout<<"Math grades are: ";
  for(int i=0; i<math.count; ++i)
    std::cout << math.notes[i]<<" ";
  std::cout<<'\n';
}
void Student::display_spa(){
  std::cout<<"Spanish grades are: ";
  for(int i=0; i<spa.count; ++i)
    std::cout << spa.notes[i]<<" ";
  std::cout<<'\n';
}

void Student::insert_note(std::string name, double note){
  if(name== "eng"){
    double *old_array=eng.notes;
    eng.notes= new double[eng.count+1];
    for(int i=0; i<eng.count; ++i)
      eng.notes[i]=old_array[i];
    eng.notes[eng.count]=note;
    ++eng.count;
  }
  else if(name== "his"){
    double *old_array=his.notes;
    his.notes= new double[his.count+1];
    for(int i=0; i<his.count; ++i)
      his.notes[i]=old_array[i];
    his.notes[his.count]=note;
    ++his.count;
  }
  else if(name== "spa"){
    double *old_array=spa.notes;
    spa.notes= new double[spa.count+1];
    for(int i=0; i<spa.count; ++i)
      spa.notes[i]=old_array[i];
    spa.notes[spa.count]=note;
    ++spa.count;
  }
  else if(name== "sci"){
    double *old_array=sci.notes;
    sci.notes= new double[sci.count+1];
    for(int i=0; i<sci.count; ++i)
      sci.notes[i]=old_array[i];
    sci.notes[sci.count]=note;
    ++sci.count;
  }
  else if(name== "math"){
    double *old_array=math.notes;
    math.notes= new double[math.count+1];
    for(int i=0; i<math.count; ++i)
      math.notes[i]=old_array[i];
    math.notes[math.count]=note;
    ++math.count;
  }
  else
    throw std::runtime_error("SUBJECT IS NOT IN THE SYSTEM \n");
}













/*
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
*/
