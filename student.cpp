#include <iostream>
#include <cstring>
#include "student.h"

student::student(char* newFirstName, char* newLastName, int newID, float newGPA)
{//Student Constructor
  firstName = new char[strlen(newFirstName)+1];
  //New first name
  strcpy(firstName, newFirstName);
  //Copy the first name
  lastName = new char[strlen(newLastName)+1];
  //New last name
  strcpy(lastName, newLastName);
  //Copy the last name
  ID = newID;
  //New ID
  GPA = newGPA;
  //New GPA
}

char* student::getFirstName()
{// Get first name
  return firstName;
  //Return first name
}

char* student::getLastName()
{//Get last name
  return lastName;
  //Return last name
}

int student::getID()
{//Get ID
  return ID;
  //Return ID
}

float student::getGPA()
{//Get GPA
  return GPA;
  //Return GPA
}
