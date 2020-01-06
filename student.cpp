#include <iostream>
#include <cstring>
#include "student.h"

student::student(char* newFirstName, char* newLastName, int newID, float newGPA)
{
  firstName = new char[strlen(newFirstName)+1];
  strcpy(firstName, newFirstName);
  lastName = new char[strlen(newLastName)+1];
  strcpy(lastName, newLastName);
  ID = newID;
  GPA = newGPA;
}

char* student::getFirstName()
{
  return firstName;
}

char* student::getLastName()
{
  return lastName;
}

int student::getID()
{
  return ID;
}

float student::getGPA()
{
  return GPA;
}
