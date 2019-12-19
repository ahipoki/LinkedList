#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void add(Student*, Node**);
void print(Node*, Node*);

int main()
{
  Node* head;
  add(new Student("Gregory", "Feng", 1, 1.0), &head);
  print(head, head);
}

void add(Student* newStudent, Node** head)
{
  Node** current = head;
  if (*current == NULL)
  {
    *head = new Node(newStudent);
  }
  else
  {
    while ((*current)->getNext() != NULL)
    {
      Node* temp = (*current)->getNext();
      current = &temp;
    }
    (*current)->setNext(new Node(newStudent));
  }
}

void print(Node* next, Node* head)
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
