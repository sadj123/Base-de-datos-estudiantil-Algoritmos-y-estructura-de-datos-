#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include "Database.hpp"
#include "Student.hpp"

#define NICK "admin"
#define PASS "admin"

std::string question(){
  int choise;
  std::string c;
  std::cout << "What is your operative system?\n\t1.Linux or mac.\n\t2.Windows\n\t   >> ";
  std::cin >> choise;
  if(choise == 1){
    c= "clear";
  }else if(choise == 2){
    c= "cls";
  }
  return c;
}


int start_up_menu(){
  int choice;
  std::cout << "\n=====================================================================\n";
  std::cout << "                           MAIN MENU";
  std::cout << "\n=====================================================================\n\n";
  std::cout<<"\t1. Display all students"<<std::endl;
  std::cout<<"\t2. Add student"<<std::endl;
  std::cout<<"\t3. Delete student"<<std::endl;
  std::cout<<"\t4. Delete the whole database"<<std::endl;
  std::cout<<"\t5. Enter student's grade"<<std::endl;
  std::cout<<"\t6. Display specific student information"<<std::endl;
  std::cout<<"\t7. EXIT "<<std::endl;
  std::cout<<"                   >> ";
  std::cin>>choice;
  return choice;
}


void login(std::string c){
  std::cin.get();
  std::string pass, nick;
  pass = "admin";
  nick = pass;
  std::string password, user;
  bool login = false;
  int count = 0;
  while(login == false && count < 3){
    std::cout << "\n=====================================================================\n";
    std::cout << "                           LOGIN OF USER";
    std::cout << "\n=====================================================================\n\n";
    std::cout << "\t\t User: ";
    getline(std::cin, user);
    std::cout << "\t\t Password: ";
    char caracter;
    caracter = getch();
    while (caracter != 13){
      if (caracter != 8){
        password.push_back(caracter);
        std::cout << "*";
      }else {
        if (password.length() > 0){
          std::cout << "\b \b";
          password = password.substr(0, password.length()-1);
        }
      }
      caracter = getch();
    }

    if(user == NICK && password == PASS){
      std::cout << "\n\n=====================================================================\n";
      std::cout << "                         WELCOME TEACHER";
      std::cout << "\n=====================================================================\n";
      login = true;
    }else{
      std::cout << "\n=====================================================================\n";
      std::cout << "                  USER AND/OR PASSWORD ARE INCORRECTS";
      std::cout << "\n=====================================================================\n";
      count ++;
    }
    std::cin.get();
    system(c.c_str());
  }
  if(login == false){
    exit(0);
  }
}


int main(){
  std::string c;
  c = question();
  system(c.c_str());
//  login(c);
  Database_map db;
  int choice = 0;
  system(c.c_str());
  while(choice != 7){
    system(c.c_str());
    choice = start_up_menu();
    switch(choice){
      case 1:{
        system(c.c_str());
        std::cout<<"The following students are found in our database: "<<std::endl;
        db.display_all();
        std::cout<<"There are a total of "<<db.size()<<" student's within our database"<<std::endl;
        std::cout<<std::endl;
        std::cin.get();
        break;
      }
      case 2:{
        system(c.c_str());
        std::string name;
        std::cout<<"Please enter the student's name: ";
        std::cin.get();
        getline(std::cin,name);
        db.insert_student(name);
        std::cout<<"The student has successfully been entered to the database!"<<std::endl;
        std::cout<<std::endl;
        std::cin.get();
        break;
      }
      case 3:{
        system(c.c_str());
        std::string name;
        std::cout<<"Please enter the  name which you want to delete: ";
        std::cin.get();
        getline(std::cin,name);
        db.delete_student(name);
        break;
      }
      case 4:{
        system(c.c_str());
        std::string answer;
        std::cout<<"Are you sure you wish to delete all the student's from the database? ";
        std::cin>>answer;
        if(answer == "yes")
          db.clear();
        else
          start_up_menu();
        std::cin.get();
        break;
      }
      case 5:{
        std::string name;
        system(c.c_str());
        std::cout<<"The following students are found in our database: "<<std::endl;
        db.display_all();
        std::cout<<"   enter student's name  >>";
        std::cin.get();
        getline(std::cin,name);
        std::cout<<std::endl;
        std::cin.get();
        break;
      }
      case 6:{
        system(c.c_str());
        std::string name;
        std::cout<<"Please enter the student's name: ";
        std::cin.get();
        getline(std::cin,name);
        db.display_student(name);
        std::cout<<std::endl;
        std::cin.get();
        break;
      }
      case 7:{
        system(c.c_str());
        std::cout<<"Thank you for using our database!"<<std::endl;
        std::cin.get();
        break;
      }
    }
  }
  return  0;
}
