#include<iostream>
#include<string>
#include<conio.h>
#include <algorithm>
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

int subjects_menu(std::string c){
  system(c.c_str());
  int choice;
  std::cout << "\n=====================================================================\n";
  std::cout << "                           SUBJECTS";
  std::cout << "\n=====================================================================\n\n";
  std::cout<<"\t1. ENGLISH"<<std::endl;
  std::cout<<"\t2. SPANISH"<<std::endl;
  std::cout<<"\t3. MATHEMATICS"<<std::endl;
  std::cout<<"\t4. SCIENCE"<<std::endl;
  std::cout<<"\t5. HISTORY"<<std::endl;
  std::cout<<"                   >> ";
  std::cin>>choice;
  if(choice!=1&& choice!=2&&choice!=3&&choice!=4&&choice!=5){
    std::cout<<"ANSWER NOT ATMITTED, PLEASE ENTER A NUMBER IN RANGE [1-5]"<<std::endl;
    system("pause");
    return subjects_menu(c);
  }
  return choice;

}


int start_up_menu(){
  int choice;
  std::cout << "\n=====================================================================\n";
  std::cout << "                           MAIN MENU";
  std::cout << "\n=====================================================================\n\n";
  std::cout<<"\t1. Display all students"<<std::endl;
  std::cout<<"\t2. Display course grade"<<std::endl;
  std::cout<<"\t3. Add student"<<std::endl;
  std::cout<<"\t4. Delete student"<<std::endl;
  std::cout<<"\t5. Delete the whole database"<<std::endl;
  std::cout<<"\t6. Enter student's grade"<<std::endl;
  std::cout<<"\t7. Display specific student information"<<std::endl;
  std::cout<<"\t8. Save database"<<std::endl;
  std::cout<<"\t9. EXIT "<<std::endl;
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
    system("color 0f");
    std::cout << "\n=====================================================================\n";
    std::cout << "                           LOGIN OF USER";
    std::cout << "\n=====================================================================\n\n";
    std::cout << "\t\t User: ";
    std::cin>>user;
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
      system("color 0a");
      std::cout << "\n\n=====================================================================\n";
      std::cout << "                         WELCOME TEACHER";
      std::cout << "\n=====================================================================\n";
      login = true;

    }else{
      system("color 0c");
      password.erase(0, password.length());
      std::cout << "\n=====================================================================\n";
      std::cout << "                  USER AND/OR PASSWORD INCORRECT";
      std::cout << "\n=====================================================================\n";
      count ++;

    }
    std::cin.get();
    std::cout<<"PRESS ENTER TO CONTINUE";
    while(getchar()!='\n'){}
    system(c.c_str());
  }
  system("color 0f");
  if(login == false){
    exit(0);
  }
}
int question_adding(Database_map &db, std::string &c, std::string name, std::string sub, double note){
  system(c.c_str());
  std::cout<<"FEEDBACK OF YOUR ACTION"<<std::endl;
  std::cout<<"===================================="<<std::endl;
  std::cout<<"\t STUDENT"<<"\t SUBJECT"<<"\t GRADE"<<std::endl;
  std::cout<<'\t'<<name<<'\t'<<'\t'<<sub<<'\t'<<'\t'<<note<<std::endl;
  std::cout<<"SURE TO CONTINUE? (Y/N)"<<std::endl;
  std::cout<<"             >>>";
  std::string answer;
  std::cin>>answer;
  std::cin.get();
  std::for_each(answer.begin(), answer.end(), [](char &c){
    c=::tolower(c);
  });
  if(answer=="yes"||answer=="y"|| answer=="1"){
    db.push_note(name, note, sub);
    std::cout<<std::endl;
    system("color 0a");
    std::cout<<"GRADE SAVED!"<<std::endl;
    system("pause");
    system("color 0f");
    return 0;
  }
  else if(answer=="no" || answer=="n"||answer== "0"){
    std::cout<<std::endl;
    system("color 0c");
    std::cout<<"GRADE NOT SAVED!"<<std::endl;
    system("pause");
    system("color 0f");
    return 0;
  }
  else{
    std::cout <<"ANSWER NOT ADMITTED. PLEASE ENTER Y OR N" << '\n';
    system("Pause");
    question_adding(db, c, name, sub, note);
    return 0;
  }}

int question_clearing(Database_map &db, std::string &c){
  system(c.c_str());
  std::string answer;
  std::cout<<"ARE YOU SURE YOU WANT CLEAR WHOLE DATABASE? (Y/N)";
  std::cout<<"\n \t >>> ";
  std::cin>>answer;
  std::cin.get();
  std::for_each(answer.begin(), answer.end(), [](char &c){
    c=::tolower(c);
  });

  if(answer=="y"||answer== "yes"||answer== "1"){
    db.clear();
    system("color 0a");
    std::cout<<"Database cleared!"<<std::endl;
    system("pause");
    system("color 0f");
    return 0;
  }
  else if(answer=="N" || answer=="n"||answer=="no"){
  system("color 0c");
  std::cout<<"Database not cleared!"<<std::endl;
  std::cout<<'\n';
  system("pause");
  system("color 0f");
  return 0;

}
else{
  std::cout <<"ANSWER NOT ADMITED. PLEASE ENTER Y OR N" << '\n';
  system("Pause");
  question_clearing(db, c);
  return 0;
}}

int question_saving(Database_map &db, std::string &c){
  system(c.c_str());
  std::string answer;
  std::cout<<"ARE YOU SURE YOU WANT CLEAR WHOLE DATABASE? (Y/N)";
  std::cout<<"\n \t >>> ";
  std::cin>>answer;
  std::cin.get();
  std::for_each(answer.begin(), answer.end(), [](char &c){
    c=::tolower(c);
  });

  if(answer=="y"||answer== "yes"||answer== "1"){
    db.save_data();
    system("color 0a");
    std::cout<<"Database Saved!"<<std::endl;
    system("pause");
    system("color 0f");
    return 0;
  }
  else if(answer=="N" || answer=="n"||answer=="no"){
  system("color 0c");
  std::cout<<"Database not Saved!"<<std::endl;
  std::cout<<'\n';
  system("pause");
  system("color 0f");
  return 0;

}
else{
  std::cout <<"ANSWER NOT ADMITED. PLEASE ENTER Y OR N" << '\n';
  system("Pause");
  question_saving(db, c);
  return 0;
}}


int main(){
  std::string c;
  c = question();
  system(c.c_str());
  login(c);
//  ofstream archivo;
  Database_map db;
  int choice = 0;
  system(c.c_str());
  while(choice != 9){
    system(c.c_str());
    choice = start_up_menu();
    switch(choice){
      case 1:{
        system(c.c_str());
        std::cout<<"The following students are found in our database: "<<std::endl;
        db.display_all();
        std::cout<<"There are a total of "<<db.size()<<" students within our database"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"PRESS ENTER TO CONTINUE"<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
        std::cin.get();
        std::cin.get();
        break;
      }
      case 2:{
        system(c.c_str());
        std::cout<<"The following students are found in our database: "<<std::endl;
        db.display_course();
        std::cout<<"There are a total of "<<db.size()<<" students within our database"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"PRESS ENTER TO CONTINUE"<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
        db.save_data();
        std::cin.get();
        std::cin.get();
        break;
      }
      case 3:{
        system(c.c_str());
        std::string name;
        std::cout<<"Please enter the student's name: ";
        std::cin.get();
        getline(std::cin,name);
        std::for_each(name.begin(), name.end(), [](char &c){
          c=::tolower(c);
        });
        while(name[0]== ' '){
          name.erase(0, 1);
        }
        name[0]= toupper(name[0]);
        if(!db.is_in(name)){
        db.insert_student(name);
        system("color 0a");
        std::cout<<"The student has successfully been entered to the database!"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"PRESS ENTER TO CONTINUE"<<std::endl;
        std::cout<<std::endl;
        std::cin.get();
        system("color 0f");
        break;
      }
      else {
        std::cout<<'\n';
        system("color 0c");
        std::cout<<"THE STUDENT IS ALREADY REGISTERED!"<<'\n';
        system("pause");
        system("color 0f");
        break;
      }}
      case 4:{
        system(c.c_str());
        std::string name;
        std::cout<<"Please enter the  name which you want to delete: ";
        std::cin.get();
        getline(std::cin,name);
        while(name[0]== ' '){
          name.erase(0, 1);
        }
        name[0]= toupper(name[0]);
        db.delete_student(name);
        break;
      }
      case 5:{
        question_clearing(db, c);
        break;
      }
      case 6:{
        std::string name;
        system(c.c_str());
        std::cout<<"The following students are found in our database: "<<std::endl;
        db.display_all();
        std::cout<<"   enter student's name  >>";
        std::cin.get();
        getline(std::cin,name);
        std::for_each(name.begin(), name.end(), [](char &c){
          c=::tolower(c);
        });
        while(name[0]== ' '){
          name.erase(0, 1);
        }
        name[0]= toupper(name[0]);
        if(!db.is_in(name)){
          system("color 0c");
          std::cout<<"THIS STUDENT IS NOT IN THE DATABASE!"<<std::endl;
          system("pause");
          system("color 0f");
          break;
        }
        std::cout<<std::endl;
        system(c.c_str());
        std::string sub;
        switch (subjects_menu(c)){
          case 1:{
            sub= "eng";
            break;
        }
          case 2:{
            sub= "spa";
            break;
          }
          case 3:{
            sub="math";
            break;
          }
          case 4: {
            sub= "sci";
            break;
          }
          case 5:{
            sub= "his";
            break;
          }
      }
      system(c.c_str());
      double note;
      std::cout <<"ENTER NOTE: ";
      std::cin>>note;
      question_adding(db, c, name, sub, note);
      break;
}


      case 7:{
        system(c.c_str());
        if(db.empty()){
          system("color 0c");
          std::cout<<"ERROR 404: DATABASE HAS NO STUDENTS!"<<std::endl;
          std::cout<<"PRESS ENTER TO CONTINUE";
          std::cin.get();
          std::cin.get();
          system("color 0f");
          break;
        }
        else{
        std::string name;
        std::cout<<"Please enter the student's name: ";
        std::cin.get();
        getline(std::cin,name);
        std::for_each(name.begin(), name.end(), [](char &c){
          c=::tolower(c);
        });
        while(name[0]== ' '){
          name.erase(0, 1);
        }
        name[0]= toupper(name[0]);

        db.display_student(name);
        std::cout<<std::endl;
        std::cout<<"PRESS ENTER TO CONTINUE";
        std::cin.get();
        system("color 0f");
        break;
      }}
      case 8:{
        question_saving(db, c);
        break;
      }
      case 9:{
        system(c.c_str());
        std::cout<<"Thank you for using our database!"<<std::endl;
        std::cin.get();
        break;
      }
    }
  }
  return  0;
}
