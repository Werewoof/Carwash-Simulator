/*****************************************************************************
   Author: Jon Korte
   Student ID: B993A295                                                                                                        
   Project #1
     
   Pseudo Code    
      
      
   int main()   
      for (timeOfDay until 600) 
         car comes at appropriate arrival time
         
         if queue is full or timeOfDay is later than 570
            turn away
         else
            check car size
               if small
                  if position in queue is first
                     if bay 1 is available
                        service this small car
                     else if bay 2 is available
                        service this small car
                     else if bay 3 is available
                        service this small car
                     else if bay 4 is available
                        service this small car
                     else  
                        make small car wait at rear of queue
                  else
                     keep small car waiting in queue
               else
                  if position in queue is first
                     if bay 3 is available
                        service this large car
                     else if bay 4 is available
                        service this large car
                     else
                        make large car wait at rear of queue
                  else
                        keep large car waiting in queue
                  endif
               endif            
         endif
      endfor   
      
      display results and save to file
end main()
*/    



#include <iostream>
#include <string>
#include <fstream>
#include "Queue.hpp"
#include "Bay.hpp"

using namespace std;






/*This function takes one argument: the time passed since ANYTHING happened.

This includes,

1.) A car arriving
2.) A bay being available for a car at front of the queue
3.) A bay just... becoming available


This is kind of a "fluff" function, but it looks good. :)

the parameter n is passed an int counter from main. This counter keeps
counting UNTIL any of the above 3 happen, in which case, the counter
is reset to 0.
*/
void sinceThen(int n)
{
	if (n >= 2)
	{
		cout << "\n                  (" << n << " minutes pass, until)\n";
	}
}



int main()
{
	cout << "\n\n\n\nStarting Kleene's carwash simulation:\n";
	cout << "Attempting to load file: ";

	//Load that file and load it good.
	ifstream inFile;
	inFile.open("vehicles.txt");


	if (inFile.is_open())
	{
		cout << "**SUCCESS**\n\n";
	}
	else
	{
		cout << "!!FAIL!!";
	}


	//The amount of cars in the vehicles.txt file.
	int count;
	inFile >> count;





	//The data goes into just one instance of customerData.
	customerData d;

	//Make sure we get that first car, or the day will never "start". :)
	inFile >> d.number >> d.carSize >> d.arrivalTime;







	//This int gets passed into that above function, "sinceThen()".
	int inActivity = 0;

	//Total amount of cars turned away.
	int turnedAway = 0;

	//Iterates through an entire business day.
	int timeOfDay;

	//The amount of cars that get washed.
	int carsWashed = 0;

	Queue q;
	Bay b1;
	Bay b2;
	//And two large bays. :)
	Bay b3('L');
	Bay b4('L');




	/*Below, again, is another bit of fluff.

	So, if

	1.) A car arrives
	2.) A bay becomes available for a car at front of the queue
	3.) A bay just becomes available

	then a certain blob of text displays ONCE per minute of a business day.

	It would be a mess if all 3 of the above were true and so the
	text blob would display 3 times.

	This bool stops that from happening. Good fluffy bool.
	*/
	bool displayedTimeAlready;










	//And... begin!

	for (timeOfDay = 1; timeOfDay < 601; timeOfDay++)
	{
		//First thing, increment inactivity, even if something DOES happen at
		//this minute of the day. SinceThen() will ONLY show its text if two or
		//more minutes have passed since something happened.
		inActivity++;


		//Update all 4 bays. Remember, this merely increases the timer.
		//This has no significance if they're already available.
		b1.update();
		b2.update();
		b3.update();
		b4.update();


		//Update the queue. This adds wait time to all cars waiting in the 
		//queue, as long as the queue is not empty.
		q.update();



		//Let's assume our "fluffy bool" HAS been displayed, until otherwise. :)
		displayedTimeAlready = true;



		//Okay. Now, we begin a three stage process. Dun dun duuuuuuun.











		//-------------------------------STAGE ONE------------------------------
		//-------------------------CARS WAITING IN QUEUE------------------------










		//So, first we check if there ARE cars in the queue.

		//If so...
		if (!q.queueEmpty())
		{
			//...then we need to get the car size at the front of the queue.
			char s = q.queueFront();

			//If it's small...
			if (s == 'S')
			{
				//...and if ANY of these bays are available for it...
				if (b1.isAvail())
				{

					//...then we call our fluffy sinceThen() function and pass in
					//the amount of time since one of those 3 aforementioned things
					//happened!
					sinceThen(inActivity);


					//WHENEVER this below text is displayed, our fluffy bool
					//will be remain true, as it was initialized to be.
					cout << "-------------------------TIME = " << timeOfDay
						<< "-------------------------\n";

					cout << "\n**BAY 1 IS AVAILABLE FOR SMALL CAR**\n";

					//Get that car out of the queue and into that bay!
					q.dequeue();

					//Since the car is small, set to 12 minutes.
					b1.setTimeLimit(12);
					b1.setTimer(0);
					cout << endl;

					//This process is just repeated below for different bays. 
				}
				else if (b2.isAvail())
				{
					sinceThen(inActivity);
					cout << "-------------------------TIME = " << timeOfDay
						<< "-------------------------\n";
					cout << "\n**BAY 2 IS AVAILABLE FOR SMALL CAR**\n";
					q.dequeue();
					b2.setTimeLimit(12);
					b2.setTimer(0);
					cout << endl;
				}
				else if (b3.isAvail())
				{
					sinceThen(inActivity);
					cout << "-------------------------TIME = " << timeOfDay
						<< "-------------------------\n";
					cout << "\n**BAY 3 IS AVAILABLE FOR SMALL CAR**\n";
					q.dequeue();
					b3.setTimeLimit(12);
					b3.setTimer(0);
					cout << endl;
				}
				else if (b4.isAvail())
				{
					sinceThen(inActivity);
					cout << "-------------------------TIME = " << timeOfDay
						<< "-------------------------\n";
					cout << "\n**BAY 4 IS AVAILABLE FOR SMALL CAR**\n";
					q.dequeue();
					b4.setTimeLimit(12);
					b4.setTimer(0);
					cout << endl;
				}
				//Okay, well, if there ARE cars, but nothing was able to be 
				//dequeued, then I guess we haven't displayed our text blob.
				//Our fluffy bool gets to be false!
				else
				{
					displayedTimeAlready = false;
				}
			}
			else
			{
				if (b3.isAvail())
				{
					sinceThen(inActivity);
					cout << "-------------------------TIME = " << timeOfDay
						<< "-------------------------\n";
					cout << "\n**BAY 3 IS AVAILABLE FOR LARGE CAR**\n";
					q.dequeue();

					//Since we've got a big car, 20 minutes.
					b3.setTimeLimit(20);
					b3.setTimer(0);
					cout << endl;
				}
				else if (b4.isAvail())
				{
					sinceThen(inActivity);
					cout << "-------------------------TIME = " << timeOfDay
						<< "-------------------------\n";
					cout << "\n**BAY 4 IS AVAILABLE FOR LARGE CAR**\n";
					q.dequeue();
					b4.setTimeLimit(20);
					b4.setTimer(0);
					cout << endl;
				}

				//Likewise in the case of the small car, nothing can be done for
				//the large car at the front. 

				//Sorry, fluffy bool. :(
				else
				{
					displayedTimeAlready = false;
				}
			}
		}

		//Well, if the queue IS empty, we can't really display anything here,
		//so fluffy bool is false.
		else
		{
			displayedTimeAlready = false;
		}












		//-------------------------------STAGE TWO------------------------------
		//-----------------------------CARS ARRIVING----------------------------











		

			//Our instance of customerData, d, got the first car, and every time 
			//a new car arrives, it will get the next cars from the .txt file.
			//So, if indeed the time of day is equal to the arrival time in d,
			//then we know that a car has arrived!
			if (timeOfDay == d.arrivalTime)
			{

				//Since a car definitely arrived, that means something 
				//definitely happened. Display text!
				if (displayedTimeAlready == false)
				{
					sinceThen(inActivity);
					cout << "-------------------------TIME = " << timeOfDay
						<< "-------------------------\n";
					displayedTimeAlready = true;
				}


				//Now that we've displayed our text blob, check car size at j.
				if (d.carSize == 'S')
				{
					cout << "\n**A SMALL CAR HAS ARRIVED**";
				}
				else
				{
					cout << "\n**A LARGE CAR HAS ARRIVED**";
				}



				//Obviously, we can't queue a car onto a full queue.
				//We also can't accept customers 30 minutes before closing.
				//Either case, turn away, and add to the total amount turned away.
				if ((q.queueFull()) || (timeOfDay > 570))
				{
					turnedAway++;
					cout << "\n\n\n    !!THE CAR WAS TURNED AWAY!! ";
					if (timeOfDay > 570)
					{
						cout << "WE'RE CLOSED!!\n\n";
					}
					//Else, the queue is just full.
					else
					{
						cout << "\n\n";
					}
				}
				//However, if the queue ISN'T full...
				else
				{
					carsWashed++;
					//Then just like in stage one, check car size. Not at front,
					//but at j, because we're checking for arrivals.
					char s = d.carSize;


					//If it's small...
					if (s == 'S')
					{
						//...and if the queue is empty AND this bay is available)
						if ((b1.isAvail()) && (q.queueEmpty()))
						{
							//...then there's no point in queueing it! 
							//Send that puppy to bay 1, set the timer and time limit!
							cout << "\n\n**BAY 1 AVAILABLE**\n";
							//Small, so 12.
							b1.setTimeLimit(12);
							b1.setTimer(0);
							cout << endl;

							//The below are the same for the other bays.
						}
						else if ((b2.isAvail()) && (q.queueEmpty()))
						{
							cout << "\n\n**BAY 2 AVAILABLE**\n";
							b2.setTimeLimit(12);
							b2.setTimer(0);
							cout << endl;
						}
						else if ((b3.isAvail()) && (q.queueEmpty()))
						{
							cout << "\n\n**BAY 3 AVAILABLE**\n";
							b3.setTimeLimit(12);
							b3.setTimer(0);
							cout << endl;
						}
						else if ((b4.isAvail()) && (q.queueEmpty()))
						{
							cout << "\n\n**BAY 4 AVAILABLE**\n";
							b4.setTimeLimit(12);
							b4.setTimer(0);
							cout << endl;
						}

						//No bays available? Too bad. Queue the car.
						else
						{
							q.enqueue(d);
							cout << "\n\n!!All bays full, car queued!!\n\n";
						}

					}
					//If it's a LARGE car, then copy the routine for small cars.
					else
					{
						if ((b3.isAvail()) && (q.queueEmpty()))
						{
							cout << "\n\n**BAY 3 AVAILABLE**\n";

							//Large, so 20.
							b3.setTimeLimit(20);
							b3.setTimer(0);
							cout << endl;
						}
						else if ((b4.isAvail()) && (q.queueEmpty()))
						{
							cout << "\n\n**BAY 4 AVAILABLE**\n";
							b4.setTimeLimit(20);
							b4.setTimer(0);
							cout << endl;
						}
						else
						{
							q.enqueue(d);
							cout << "\n\n!!All bays full, car queued!!\n\n";
						}
					}
				}
				//Since we know we've processed a car, we get the next car. :)
				if (d.number <= count)
				{
					inFile >> d.number >> d.carSize >> d.arrivalTime;
				}
				else
				{
					inFile.close();
				}
			}













		//------------------------------STAGE THREE-----------------------------
		//--------------------FINAL TOUCHES AND PRINTING STUFF------------------











		/*Okay, so if at this point the text blob HASN'T displayed, it's because

		1.) A car did not arrive
		2.) No bays are available for the car at front of the queue

		There's ONE last thing to check:

		3.) A bay just finally becoming available

		We check that below!
		*/


		//None of this will display if the text blob has already been shown.
		if (displayedTimeAlready == false)
		{
			//So, if this bay JUST became available...
			if (b1.becameAvail())
			{
				sinceThen(inActivity);
				cout << "-------------------------TIME = " << timeOfDay
					<< "-------------------------\n";

				cout << "\n**BAY 1 FINISHED WASHING CAR**\n";

				displayedTimeAlready = true;

				//Same process for the rest of the bays.
			}

			if (b2.becameAvail())
			{
				sinceThen(inActivity);
				cout << "-------------------------TIME = " << timeOfDay
					<< "-------------------------\n";

				cout << "\n**BAY 2 FINISHED WASHING CAR**\n";

				displayedTimeAlready = true;
			}


			if (b3.becameAvail())
			{
				sinceThen(inActivity);
				cout << "-------------------------TIME = " << timeOfDay
					<< "-------------------------\n";

				cout << "\n**BAY 3 FINISHED WASHING CAR**\n";

				displayedTimeAlready = true;
			}

			if (b4.becameAvail())
			{
				sinceThen(inActivity);
				cout << "-------------------------TIME = " << timeOfDay
					<< "-------------------------\n";

				cout << "\n**BAY 4 FINISHED WASHING CAR**\n";

				displayedTimeAlready = true;
			}
		}



		//If our fluffy bool did not fail us, and something DID happen...
		if (displayedTimeAlready == true)
		{
			//then we reset inactivity to 0.
			inActivity = 0;

			//Finally, we actually display the queue, if it's not empty.
			if (!q.queueEmpty())
			{
				cout << endl;
				q.printQueue();
			}

			//And last of all, we display our bays.
			cout << endl;
			b1.displayBay();
			b2.displayBay();
			b3.displayBay();
			b4.displayBay();
			cout << "\n\n\n\n\n";
		}

		//And now, restart until the end of the for loop. :)
	}


	//...And the for loop has ended.

	//Results time!












	//******************************RESULTS*********************************















	//Remember, the queue keeps track of the total wait time for all cars in
	// the queue. So, average is initially equal to that.
	double average = q.getTotalWait();

	//In truth, the average is really the total time of cars queued divided
	//by the amount of cars queued.
	//cout << average << "totalwait";
	average = (average / carsWashed);
	//cout << average << "avgwait";
	//cout << carsWashed;

	//cout << carsWashed;
	cout << "\n\n\n           ................END OF DAY...............";
	cout << "\n\n           ***********SIMULATION COMPLETE***********\n\n\n";

	cout << "              "
		<< "Cars turned away | Average wait time\n\n"
		<< "                      " << turnedAway
		<< "                 "; printf("%4.3f", average);


	//Since all cars have been processed, we can close the .txt inFile.        
	inFile.close();

	//Write out to results.txt...
	ofstream outFile;
	outFile.open("results.txt");

	outFile << "Turned away: " << turnedAway
		<< "\nAverage wait time: " << average;
	outFile.close();

	cout << "\n\n\n\n           [Written to file. Please exit simulation.]\n";

	//And done. :)
}