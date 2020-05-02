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
  return (average_spa()+average_eng()+average_his()+average_sci()+average_math())/5;
}

void Student::display_eng(){
  std::cout<<"English grades are: ";
  for(int i=0; i<eng.count; ++i)
    std::cout << eng.notes[i]<<", ";
  std::cout<<'\n';
}
void Student::display_his(){
  std::cout<<"History grades are: ";
  for(int i=0; i<his.count; ++i)
    std::cout << his.notes[i]<<", ";
  std::cout<<'\n';
}
void Student::display_sci(){
  std::cout<<"Science grades are: ";
  for(int i=0; i<sci.count; ++i)
    std::cout << sci.notes[i]<<", ";
  std::cout<<'\n';
}
void Student::display_math(){
  std::cout<<"Math grades are: ";
  for(int i=0; i<math.count; ++i)
    std::cout << math.notes[i]<<", ";
  std::cout<<'\n';
}
void Student::display_spa(){
  std::cout<<"Spanish grades are: ";
  for(int i=0; i<spa.count; ++i)
    std::cout << spa.notes[i]<<", ";
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
