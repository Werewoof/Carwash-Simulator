/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #1
 
    Description of the problem:
         This project implements the Bay class. It contains data to hold
         a timer, a time limit, the availability of the bay, and its size.
         The bay is unavailable until the time has finished counting down and
         the car inside has been washed.
 

 
 Pseudo code:
   

 
Class: Bay

   Data: 
      baySize - the size of the bay. If it's small, it can only wash small
               cars. If it's large, it can do either.
      timer - updated as long as there's a car being washed. It ticks until
              finished.
      timeLimit - How long a car takes to be washed. 12 for small, 
                  20 for large.
      status - determines whether the bay is ready for a car or if it already
               has one.
      
   Mutator Functions:
      =>    setStatus - set the status to available or unavailable. 
               Input Parms: char (A or U)
               Output Parms: None
           
      =>    setTimeLimit - set the time it will take to wash a car. 
               Input Parms: int
               Output Parms: None
           
      =>    setTimer - set the timer that counts down. 
               Input Parms: int
               Output Parms: None
               
               
   Accessor Functions:
      =>    displayBay - displays the bay as well as the remaining time.
               Input Parms: none
               Output Parms: remaining time
               
               remaining time = timeLimit - timer

                        
   Functions:
      =>    update: just ticks the timer until it hits the time limit.
               Input Parms: none
               Output Parms: none
               
                  add to timer
                  
                  
      =>    isAvail: is or is not the bay currently available?
               Input Parms: none
               Output Parms: true or false 
               
                  if (status = 'A')
                     return true
                  else
                     return false
                  endif
                  
      =>    isNowAvail: Different from above: is the bay NOW available?
               Input Parms: none
               Output Parms: true or false 
               
                  if (time is up)
                     return true
                  else
                     return false
                  endif
*/ 


#include <iostream>

using namespace std;

class Bay
{
   int timer;
   char status;
   char size;
   int timeLimit;
public:
   Bay();
   Bay(char si);
   void setTimer(int setTm);
   void setStatus(char setSts);
   void setTimeLimit(int setLm);
   bool isAvail();
   bool becameAvail();
   void displayBay();
   void update();
};