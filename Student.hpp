#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include<iostream>
#include<fstream>
#include<string>

struct Subject{
  int count;
  std::string name_subject;
  double *notes;
};

class Student{
private:
  Subject eng;
  Subject spa;
  Subject math;
  Subject sci;
  Subject his;
public:
  Student();
  ~Student();
  double average_eng();
  double average_sci();
  double average_spa();
  double average_his();
  double average_math();
  double average_final();
  void display_eng();
  void display_math();
  void display_sci();
  void display_his();
  void display_spa();
  void insert_note(std::string name, double note);
};

#endif
