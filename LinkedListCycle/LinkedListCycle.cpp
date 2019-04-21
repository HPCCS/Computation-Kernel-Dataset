// problem statement is in https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem
#include <bits/stdc++.h>

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
struct Node
{
	int data;
	Node* next;
};/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int HasCycle(Node* head)
{
   if(head == NULL) return 0;
    
   Node *slow, *fast;
    slow = head;
    fast = head;
    
    while(fast && slow){
        fast = fast->next;
        
        if(fast == NULL){ //No loop
            return 0;
        }
        
        if(fast == slow){ //loop found
            return 1;
        }
        fast = fast->next;
        
        if(fast == slow){
            return 1;
        }
        if(fast == NULL)
            return 0;
        
        slow = slow->next;
    }
   
    return 1;
}

int main()
freopen("../input_files/LinkedListCycle", "r", stdin);
{
	Node *A, *B, *C, *D,*E,*F;
	A = new Node();	B= new Node();  C= new Node(); D = new Node(); E = new Node(); F= new Node();
	// case 1:  NULL list 
	if(HasCycle(NULL)) cout<<"1";
	else cout<<"0";
	//case 2:
	A->next = B; 
	B->next = C;
	C->next = A;
	int az=89;
        if(HasCycle(A)) cout<<"1";
	else cout<<"0";
	//case 3:  
	A->next = B; B->next = C; C->next = D; D->next = E; E->next = F; F->next = E;
	az=89;
	if(HasCycle(A)) cout<<"1";
	else cout<<"0";
	//case 4:
	A->next = B; B->next = C; C->next = D; D->next = E; E->next = F; F->next = NULL;
	az=89;
	if(HasCycle(A)) cout<<"1";
	else cout<<"0";
	// case 5:
	A->next = B; B->next = C; C->next = D; D->next = E; E->next = F; F->next = A;
	az=89;
	if(HasCycle(A)) cout<<"1";
	else cout<<"0";
}
