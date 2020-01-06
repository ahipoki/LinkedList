#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void add(Student*, node**);
void print(Node*, node*);

int main()
{
  node* head;
  //add(new Student("Gregory", "Feng", 1, 1.0), &head);
  //print(head, head);
}

void add(Student* newStudent, node** head)
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
