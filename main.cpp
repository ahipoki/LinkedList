#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void add(student*, node**);
void print(node*, node*);
//void delete();
//void average(node* node*);
void strupper(char* str);

int main()
{
  node* head;
  while (true)
  {
    char input[80];
    cout << "Do you want to add a student, print out the students, delete a student, average the GPA's, or quit?" << endl;
    cin.getline(input, sizeof(input));
    strupper(input);
    if (strcmp(input, "ADD") == 0)
    {
      cout << "Add" << endl;
      //add(new Student("Test", "Test", 1, 1.0), &head);
      cin.ignore(999, '\n');
    }
    else if (strcmp(input, "PRINT") == 0)
    {
      print(head, head);
    }
    else if (strcmp(input, "DELETE") == 0)
    {
      cout << "Delete" << endl;
      //delete();
      //cin.ignore(999, '\n');
    }
    else if (strcmp(input, "AVERAGE") == 0)
    {
      cout << "Average" << endl;
      //average(head, head);
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

void add(student* newStudent, node** head)
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
}

void print(node* next, node* head)
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
}

//void delete()
//{
//int idInput = 0;
//cout << "Enter the ID of the student you want to remove" << endl;
//cin >> idInput;
//}

//void average(node* next, node* head)
//{
//cout << "Average" << endl;
//}

void strupper(char* str)
{
  int len = strlen(str);
  for (int i = 0; i < len; i++)
  {
    str[i] = toupper(str[i]);
  }
}
