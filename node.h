//Dhruva Sogal node class
/*
This is the node class


 */

#ifndef NODE_H
#define NODE_H
#include<iostream>
#include"student.h"
using namespace std;
class node{
 public: 
  node(student*); //constructor, this takes in a student* then sets it equal to the private student*
  ~node(); //destructor,deletes student
  student* getStudent(); //returns the student that is linked to the node*
  void setNext(node*); //sets the next node
  node* getNext(); //returns the next node
  
 private:
  student* Student; //student*
  node* next; //nextNode
  





};


#endif
