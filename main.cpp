#include <iostream>
#include <cstring>
#include <math.h>
#include "node.h"
#include "student.h"

using namespace std;

void add(student*, node*&);
//Add prototype
void print(node*);
//Print prototype
void printStudent(student*);
//Print student prototype
void remove(int id, node*&);
//Remove node prototype
void average(int count, float total, node*);
//Average prototype
void strupper(char* str);
//Make input uppercase prototype
void commands(char[], node *&);
//Commands prototype

int main()
{
  cout.setf(ios::showpoint);
  //Makes cout print
  cout.setf(ios::fixed, ios::floatfield);
  //Makes cout print out a fixed number of decimals for floats
  cout.precision(2);
  //Make that number 2
  node* head = NULL;
  //The head
  while (true)
  {//While running
    char input[80];
    //Input
    cout << "Do you want to add a student, print out the students, delete a student, average the GPA's, or quit?" << endl;
    //Ask if they want to add, print, delete, average, or quit
    cin.getline(input, sizeof(input));
    //Get their input
    strupper(input);
    //Make it uppercase
    if (strcmp(input, "QUIT") == 0)
    {//If they want to quit
      return 0;
      //Quit
    }
    commands(input, head);
    //If it's anything else, go to the commands
  }
}

void commands(char input[], node* &head)
{//Commands
  if (strcmp(input, "ADD") == 0)
  {//If they want to add
    char first[80];
    //First name
    char last[80];
    //Last name
    int ID = 0;
    //ID
    float GPA = 0;
    //GPA
    cout << "What is the student's first name?" << endl;
    //Ask for the student's first name
    cin.getline(first, 80);
    //Take in their input
    cout << "What is the student's last name?" << endl;
    //Ask for the student's last name
    cin.getline(last, 80);
    //Take in their input
    cout << "What is the student's ID?" << endl;
    cin >> ID;
    cout << "What is the student's GPA?" << endl;
    cin >> GPA;
    add(new student(first, last, id, gpa), head);
    cin.ignore(999, '\n');
  }
  else if (strcmp(input, "PRINT") == 0)
  {
    print(head);
  }
  else if (strcmp(input, "DELETE") == 0)
  {
    int id = 0;
    cout << "What is the ID of the student you want to remove?" << endl;
    cin >> id;
    remove(id, head);
    cin.ignore(999, '\n');
  }
  else if (strcmp(input, "AVERAGE") == 0)
  {
    average(0, 0, head);
  }
  else
  {
    cout << "That's an invalid option" << endl;
  }
}

void add(student* newStudent, node* &head)
{
  //node** current = head;
  if (head == NULL)
  {
    head = new node(newStudent);
    return;
  }
  if (newStudent->getID() < head->getStudent()->getID())
  {
    node* temp = new node(newStudent);
    temp->setNext(head);
    head = temp;
    return;
  }
  if (head->getNext() != NULL)
  {
    if (newStudent->getID() < head->getNext()->getStudent()->getID())
    {
      node* temp = new node(newStudent);
      temp->setNext(head->getNext());
      head->setNext(temp);
      return;
    }
  }
  else
  {
    head->setNext(new node(newStudent));
    return;
  }
  node* next = head->getNext();
  add(newStudent, next);
}

void remove(int id, node* &head)
{
  if (head == NULL)
  {
    cout << "The list is empty" << endl;
    return;
  }
  if (head->getStudent()->getID() == id)
  {
    node* temp = head->getNext();
    delete head;
    head = temp;
    return;
  }
  if (head->getNext() != NULL)
  {
    if (head->getNext()->getStudent()->getID() == id)
    {
      node* temp = head->getNext();
      head->setNext(head->getNext()->getNext());
      delete temp;
      return;
    }
  }
  else
  {
    cout << "That ID wasn't found" << endl;
    return;
  }
  node* next = head->getNext();
  return remove(id, next);
}
               
void print(node* head)
{
  if (head != NULL)
  {
    printStudent(head->getStudent());
    print(head->getNext());
  }
}

void printStudent(student* student)
{
  cout << "Student: " << student->getFirstName() << " " << student->getLastName() << ", ID: " << student->getID() << ", GPA: " << endl;
}

void average(int count, float total, node* head)
{
  if (head != NULL)
  {
    average(++count, total+head->getStudent()->getGPA(), head->getNext());
  }
  else
  {
    cout << "Average GPA: " << total/count << endl;
    return;
  }
}

void strupper(char* str)
{
  int len = strlen(str);
  for (int i = 0; i < len; i++)
  {
    str[i] = toupper(str[i]);
  }
}
