#include <iostream>
#include <cstring>
#include <math.h>
#include "node.h"
#include "student.h"

using namespace std;

void add(student*, node*&);
void print(node*);
void printStudent(student*);
void remove(int id, node*&);
void average(int count, float total, node*);
void strupper(char* str);
void commands(char[], node *&);

int main()
{
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  node* head = NULL;
  while (true)
  {
    char input[80];
    //add(new Student("Test", "Test", 1, 1.0), &head);
    cout << "Do you want to add a student, print out the students, delete a student, average the GPA's, or quit?" << endl;
    cin.getline(input, sizeof(input));
    strupper(input);
    if (strcmp(input, "QUIT") == 0)
    {
      return 0;
    }
    commands(input, head);
  }
  //add(new Student("Gregory", "Feng", 1, 1.0), &head);
  //print(head, head);
}

void commands(char input[], node* &head)
{
  if (strcmp(input, "ADD") == 0)
  {
    char first[80];
    char last[80];
    int id = 0;
    float gpa = 0;
    cout << "What is the student's first name?" << endl;
    cin.getline(first, 80);
    cout << "What is the student's last name?" << endl;
    cin.getline(last, 80);
    cout << "What is the student's ID?" << endl;
    cin >> id;
    cout << "What is the student's GPA?" << endl;
    cin >> gpa;
    add(new Student(first, last, id, gpa), head);
    cin.ignore(999, '\n'
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
    deleteNode(id, head);
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
