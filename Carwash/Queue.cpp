/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #1
*/

#include <iostream>
#include "Queue.hpp"


using namespace std;


//Default constructor. Sets count = 0 and front and rear = NULL.
Queue::Queue()
{
   front = NULL;
   rear = NULL;
   cnt = 0;
   totalWaitTime = 0;
}


//Gets user inputed data and stores it into a node. It places it at the rear,
//but if it's the only node in the queue, it's automatically the front.
void Queue::enqueue(customerData &dat)
{

   Node *ptr = new Node(dat);

   if (queueEmpty())
   {
      front = ptr;
   }
   else
   {
      rear->setNext(ptr);
   }

   rear = ptr;
   cnt++;
}


//Takes the front node off of the queue and resets the front to the node below it.
void Queue::dequeue()
{
   
   if (queueEmpty())
   {
      cout << "\n!!Queue underflow!!\n\n";
   }

   //If this queue isn't empty, deletion can continue.
   else
   {

      Node *temp = new Node;

      temp = front;
      front = front->getNext();

      //When we dequeue, we check to see how long this customer waited.
      //We then add that to the total time waited.
      int timeWaited = temp->getTimeWaited();
     
      //We access the queue's total wait time and add to it.
      totalWaitTime = (totalWaitTime + timeWaited);
      //cout<<endl<<totalWaitTime<<endl;
      delete (temp);
   }
   cnt--;
}


//Returns the car size from the front node in the queue.
char Queue::queueFront()
{
   return front->getSize();
}

//Returns the car size from the rear node in the queue.
char Queue::queueRear()
{
   return rear->getSize();
}

//Checks if there are any nodes at all in the queue.
bool Queue::queueEmpty()
{
   if (front == NULL)
   {
      return true;
   }
   else
   {
      return false;
   }
}

//Checks if there are the maximum amount of nodes in the queue.
bool Queue::queueFull()
{
   if (cnt >= 12)
   {
      return true;
   }
   else
   {
      return false;
   }
}

//Get the allotted wait time of all customers.
int Queue::getTotalWait()
{
   return totalWaitTime;
}


//Prints all cars in a nice way. :)
void Queue::printQueue()
{
   Node *curr = new Node;

   curr = front;

   if (!queueEmpty())
   {
      cout << " ===================QUEUE==================\n";
      cout << " position.) size | #number/arrival/[waited]\n\n";
      
      //Indexes the queue for visual purposes.
      int i = 1;
      
      //Iterate through all nodes.
      while (curr != NULL)
      {
         int gN = curr->getNumber();
         char gS = curr->getSize();
         int gA = curr->getArrival();
         int gW = curr->getTimeWaited();

         // position.) size | #number/arrival/[waited]
         cout << " " << i << ".) " << gS << " | #" << gN << "/"
            << gA;

         //Since no two customers arrive at the same time, we can trust that,
         //if a customer hasn't waited at all, they just got queued.
         //So, this shows.
         if (gW == 0)
         {
            cout << "/[" << gW << "] <--\n";
         }
         //Otherwise, show how long they've been suffering.
         else
         {
            cout << "/[" << gW << "]\n";
         }
         
         i++;
         curr = curr->getNext();
      }

      cout << " \n==========================================";
   }
}

//Add to time waited for all customers in queue, provided it's not empty.
void Queue::update()
{
   Node *curr = new Node;

   curr = front;

   if (!queueEmpty())
   {
      while (curr != NULL)
      {
         curr->addWaitTime();
         curr = curr->getNext();
      }
   }
}