#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void add(node*, node**);
//void add(student*, node**);
void print(node*, node**);
void printStudent(student* student);
void remove();
void average();
void strupper(char* str);

int main()
{
  node* head;
  while (true)
  {
    char input[80];
    //add(new Student("Test", "Test", 1, 1.0), &head);
    cout << "Do you want to add a student, print out the students, delete a student, average the GPA's, or quit?" << endl;
    cin.getline(input, sizeof(input));
    strupper(input);
    if (strcmp(input, "ADD") == 0)
    {
      add(head, &head);
      //add(student* Student, &head);
      //add(new Student("Test", "Test", 1, 1.0), &head);
    }
    else if (strcmp(input, "PRINT") == 0)
    {
      print(head, &head);
    }
    else if (strcmp(input, "DELETE") == 0)
    {
      remove();
    }
    else if (strcmp(input, "AVERAGE") == 0)
    {
      average();
    }
    else if (strcmp(input, "QUIT") == 0)
    {
      return false;
    }
    else
    {
      cout << "That's an invalid option." << endl;
    }
  }
  //add(new Student("Gregory", "Feng", 1, 1.0), &head);
  //print(head, head);
}

/*void add(student* newStudent, node** head)
{
  node** current = head;
  if (*current == NULL)
  {
    *head = new node(newStudent);
  }
  else
  {
    while ((*current)->getNext() != NULL)
    {
      node* temp = (*current)->getNext();
      current = &temp;
    }
    (*current)->setNext(new node(newStudent));
  }
  }*/

void add(node* next, node** head)
{
  char tempFirst[80];
  char tempLast[80];
  int tempID;
  float tempGPA;
  cout << "What is the first name?" << endl;
  cin.getline(tempFirst, 80);
  strupper(tempFirst);
  cout << "What is the last name?" << endl;
  cin.getline(tempLast, 80);
  strupper(tempLast);
  cout << "What is the ID?" << endl;
  cin >> tempID;
  cout << "What is the GPA?" << endl;
  cin >> tempGPA;
  if (next == head)
  {
    cout << "Add: " << endl;
  }
  if (next != NULL)
  {
    cout << "Test" << endl;
    print(next->getNext(), head);
  }
}

void print(node** head)
{
  node** next = head;
  if (*head == *next)
  {
    cout << "List: " << endl;
  }
  if (*next != NULL)
  {
    printStudent((*next)->getStudent());
    node** temp = (*next)->getNext();
    print(&temp);
  }
}

void printStudent(student* student)
{
  cout << "Student: " << student->getFirstName() << " " << student->getLastName() << ", ID: " << student->getID() << ", GPA: " << endl;
}

/*void print(node* next, node** head)
{
  if (next == head)
  {
    cout << "List:" << endl;
  }
  if (next != NULL)
  {
    cout << "Student: " << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << " ID: " << next->getStudent()->getID() << " GPA: " << next->getStudent()->getGPA() << endl;
    print(next->getNext(), head);
  }
  }*/

void remove()
{
  int idInput = 0;
  cout << "Enter the ID of the student you want to remove" << endl;
  cin >> idInput;
  cout << "You want to delete: " << idInput << endl;
}

void average()
{
  cout << "Average: " << endl;
}

void strupper(char* str)
{
  int len = strlen(str);
  for (int i = 0; i < len; i++)
  {
    str[i] = toupper(str[i]);
  }
}
