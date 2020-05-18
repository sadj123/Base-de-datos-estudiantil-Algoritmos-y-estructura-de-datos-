#ifndef _DATABASE_HPP
#define _DATABASE_HPP
#include <string>
#include "Student.hpp"

struct Key_value{
  std::string name;
  Student value;
};


class Database_map{
private:
  const int INITIAL_CAPACITY= 10;
  Key_value* array;
  int capacity;
  int count;
  void expand_capacity();
  int index(std::string name);
public:
  bool is_in(std::string name);
  Database_map();
  ~Database_map();
  void save_data();
  void insert_student(std::string name);
  void delete_student(std::string name);
  void display_all();
  void display_course();
  void display_student(std:: string name);
  void disp_math(std::string name);
  void disp_eng(std::string name);
  void disp_sci(std::string name);
  void disp_spa(std::string name);
  void disp_his(std::string name);
  void clear();
  int size();
  void push_note(std::string name, double note, std::string subject);
  bool empty();
  double get_total_average(std::string name);


};

#endif
