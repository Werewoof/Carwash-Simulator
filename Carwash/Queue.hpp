/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #1
 
    Description of the problem:
         This project implements the Queue class. It has a pointer to the 
         front and rear of a queue of nodes. It includes how many nodes are in 
         the queue. It also keeps track of the total wait time of all cars. 
         
         
 
Pseudo Code



Class: Queue

   Data: 
      front - pointer to front of queue.
      rear - pointer to rear of queue.
      count - number of nodes in queue.
      totalWaitTime - total allotted wait time of all cars.
   
   Mutator Functions:
            None.
      
   Accessor Functions:
           
      =>    getTotalWait - gets the total wait time for all cars.
               Input Parms: none
               Output Parms: total wait time
                  
   Functions:
      
      =>    enqueue - adds a node to the rear of queue.
               Input Parms: data to be passed into node
               Output Parms: none
                  
                  
      =>    dequeue - removes the node at the front of queue.
               Input Parms: none
               Output Parms: none
   
      =>    queueFront - returns the size of the car at the front.
               Input Parms: none
               Output Parms: size of car at queue front
                  
      =>    queueRear - returns the size of the car at the rear.
               Input Parms: none
               Output Parms: size of car at queue rear
   
      =>    queueEmpty - checks to see if queue is empty.
               Input Parms: none
               Output Parms: true or false
               
               if (empty)
                  return true
               else
                  return false
               endif
                  
      =>    queueFull - checks to see if queue is full.
               Input Parms: none
               Output Parms: true or false
               
               if (full)
                  return true
               else
                  return false
               endif
               
      =>    printQueue - prints the contents of nodes in the queue.
               Input Parms: none
               Output Parms: none
               
               print the contents of nodes in the queue
               
      =>    update - adds to the wait time of all cars in queue.
               Input Parms: none
               Output Parms: none
               
               add to the wait time of all cars in queue             
*/ 

#include <iostream>
#include "Node.hpp"

using namespace std;


class Queue
{
   //--------data------------
   Node *front;
   Node *rear;
   int cnt;
   int totalWaitTime;
public:
   Queue();
   void enqueue(customerData &dat);
   void dequeue();
   char queueFront();
   char queueRear();
   bool queueEmpty();
   bool queueFull();
   int getCarsWashed();
   int getTotalWait();
   void printQueue();
   void update();
};