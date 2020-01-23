#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class student
{//Student.h
 public:
  student(char*, char*, int, float);
 //Student Constructor
  char* getFirstName();
  //Get first name
  char* getLastName();
  //Get last name
  int getID();
  //Get ID
  float getGPA();
  //Get GPA
 private:
  char* firstName;
  //First name
  char* lastName;
  //Last name
  int ID;
  //ID
  float GPA;
  //GPA
};
#endif
