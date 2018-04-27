/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #1
 
    Description of the problem:
         This project implements the Node class. It contains private data to 
         hold a number, a car size, an arrival time, and a time waited. It
         also contains a node that points to another single node, linked 
         together via a queue. Several accessor functions are available
         to retrieve the private data, while a sole mutator function is
         used by a queue. Another function adds to the total time waited.
         
 
Pseudo Code

Struct: customerData

   Data:
      number - the customer's arrival number for the day. (4th, 27th, etc.)
      carSize - the size of the customer's car. S for small, L for large. 
      arrival - the time that the customer arrives at.
      waitTime - how long the customer has been waiting.
 
   Functions:
      None.

   

   
   
Class: Node

   Data: 
      d - an instance of the struct data.
      next - pointer to the next node in the queue.
   
   Mutator Functions:
      =>    setNext - set the pointer of a node to another node.
               Input Parms: pointer to a node
               Output Parms: None
      
   Accessor Functions:
      =>    getNext - return whatever node is being looked at by another node.
               Input Parms: None
               Output Parms: next
                  
      =>    getNumber - gets a customer's number from data.
                  Input Parms: None
                  Output Parms: customer number
                  
      =>    getSize - gets a customer's car size from data.
                  Input Parms: None
                  Output Parms: customer car size
                  
      =>    getArrival - gets a customer's arrival time from data.
                  Input Parms: None
                  Output Parms: customer arrival time
                  
      =>    getWaited - gets a customer's time waited data.
                  Input Parms: None
                  Output Parms: customer wait time           
                  
   Functions:
      =>    addWait - adds to a customer's wait time.
               Input Parms: none
               Output Parms: none
              
               add to time waited

*/  


#include <iostream>
using namespace std;


struct customerData
{
   int number;
   char carSize;
   int arrivalTime;
   int timeWaited;
};

class Node
{
   //--------data------------
   customerData cusData;
   //---------link-----------
   Node *next;

public:
   Node();
   Node(customerData cd);
   void setNext(Node *ptr);
   Node *getNext();
   int getNumber();
   char getSize();
   int getArrival();
   int getTimeWaited();
   void addWaitTime();
};