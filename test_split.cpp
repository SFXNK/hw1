/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

void clean(Node*);

int main(int argc, char* argv[])
{
  Node* head=new Node(1,NULL);
  Node* p=head;
  for(int i=2;i<=10;i++){
    p->next=new Node(i,NULL);
    p=p->next;
  }
  Node* odds=NULL;
  Node* evens=NULL;
  split(head,odds,evens);
  clean(odds);
  clean(evens);
}

void clean(Node* in){
  if(in!=NULL){
    //std::cout<<in->value<<std::endl;
    clean(in->next);
    delete in;
  }
}
