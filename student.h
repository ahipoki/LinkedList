#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class student
{
 public:
  student(char*, char*, int, float);
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
 private:
  char* firstName;
  char* lastName;
  int ID;
  float GPA;
};
#endif
