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
  bool is_in(std::string name);
  int index(std::string name);
public:
  Database_map();
  ~Database_map();
  void insert_student(std::string name);
  void delete_student(std::string name);
  void display_all();
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


};
/*
class Database{
private:
  static const int INITIAL_CAPACITY = 10;
  void expand_capacity();
  Student *array;
  int size, capacity;

public:
  Database();
  ~Database();

  void operator =(const Database& a);
  void search_student(std::string name);
  void search_roll_num(int id);
  void add_student(const Student& st);
  void display_all();
//??  void edit_student(std::string name);
//??  void display_class();
//?? void sort_students();
  void delete_student(std::string name);
  void save_file(std::ostream& output);
  void load_file(std::istream& input);
};
*/

#endif
