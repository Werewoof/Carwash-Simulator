/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #1
*/

#include <iostream>
#include "Node.hpp"


using namespace std;


//Default constructor. Sets all data to their default values.
//Sets pointer = NULL upon instantiation.
Node::Node()
{
   cusData.number = 0;
   cusData.carSize = 'S';
   cusData.arrivalTime = 0;
   cusData.timeWaited = 0;
   next = NULL;
}


//Overloaded constructor. Allows for the private data (except timeWaited)
//to be set.
//Sets pointer = NULL upon instantiation.
Node::Node(customerData cd)
{
   cusData.number = cd.number;
   cusData.carSize = cd.carSize;
   cusData.arrivalTime = cd.arrivalTime;
   cusData.timeWaited = 0;
   next = NULL;
}


//Sets an item's pointer to point to whatever other pointer gets passed in.
//This is not done manually in main!
void Node::setNext(Node *ptr)
{
   next = ptr;
}


//Used to retrieve whatever other pointer a pointer is looking at.
Node* Node::getNext()
{
   return next;
}


//Retrieves a customer's arrival number.
int Node::getNumber()
{
   return cusData.number;
}

//Retrieves a customer's car size.
char Node::getSize()
{
   return cusData.carSize;
}

//Retrieves a customer's arrival time.
int Node::getArrival()
{
   return cusData.arrivalTime;
}

//Retrieves a customer's time waited.
int Node::getTimeWaited()
{
   return cusData.timeWaited;
}

//Adds to a customer's frustration.
void Node::addWaitTime()
{
   cusData.timeWaited++;
}

