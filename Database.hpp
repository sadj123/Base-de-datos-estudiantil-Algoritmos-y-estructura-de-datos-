#ifndef DATABASE_H
#define DATABASE_H
#include "Student.hpp"

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

#endif
