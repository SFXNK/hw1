/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */

Node* findlast(Node*);

void split(Node*& in, Node*& odds, Node*& evens)
{
  if(in==NULL) return;
  if(in->value%2){
    if(odds==NULL)
      odds=in;
    else
      findlast(odds)->next=in;
  }
  else{
    if(evens==NULL)
      evens=in;
    else
      findlast(evens)->next=in;
  }
  Node* tmp=in->next;
  in->next=NULL;
  in=tmp;
  split(in,odds,evens);
  /* Add code here */
// WRITE YOUR CODE HERE
}

/* If you needed a helper function, write it here */
Node* findlast(Node* in){
  if(in->next!=NULL)
    return findlast(in->next);
  else
    return in;
}