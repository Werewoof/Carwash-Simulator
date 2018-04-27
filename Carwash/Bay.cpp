/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                                                          
   Project: #1
*/

#include <iostream>
#include "Bay.hpp"

using namespace std;

//Default constructor. Sets timer to 0, status to available, bay size to 
//small, and time limit to -1. Time limit gets changed when a car is 
//entered into the bay.
Bay::Bay()
{
   timer = 0;
   status = 'A';
   size = 'S';
   timeLimit = -1;
}

//Overloaded constructor. The same as the above, but it can be used to create
//a large bay instead of a small one.
Bay::Bay(char si)
{
   timer = 1;
   status = 'A';
   size = si;
   timeLimit = -1;
}


//Set the timer that counts until completion.
void Bay::setTimer(int setTm)
{
   timer = setTm;
}

//Set available or unavailable.
void Bay::setStatus(char setSts)
{
   status = setSts;
}

//Set amount of time till washing complete.
void Bay::setTimeLimit(int setLm)
{
   timeLimit = setLm;
}

//Checks to see if bay is available, regardless of when.
bool Bay::isAvail()
{
   if ((status == 'A') || (timer == timeLimit))
   {
      return true;
   }

   else
   {
      return false;
   }

}

//Checks to see if a bay literally just became available.
bool Bay::becameAvail()
{
   if (timeLimit == timer)
   {
      return true;
   }
   else
   {
      return false;
   }
}

//Retrieve the time remaining for a car to be washed thoroughly.
void Bay::displayBay()
{
   //the time remaining is the difference between the time remaining and
   //the time elapsed.
   int remaining = timeLimit - timer;

   //The timer will constantly be counting, until it is reset by a car being
   //entered into the bay. So, if there's no car in the bay for however long,
   //then this shows.
   if (remaining <= 0)
   {
      cout << "\n[ ]";
      status = 'A';
   }
   
   //If a car was JUST entered into a bay, this shows.
   else if (remaining == timeLimit)
   {
      cout << "\n[" << remaining << "] <---";
      status = 'U';
   }

   //Anywhere between done and not done, this shows.
   else
   {
      cout << "\n[" << remaining << "]";
      status = 'U';
   }
}

//You'd think timer would count down, but it counts up. :)
void Bay::update()
{
   timer++;
}