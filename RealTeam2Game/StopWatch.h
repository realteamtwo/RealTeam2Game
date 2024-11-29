#ifndef STOPWATCH_H
#define STOPWATCH_H

// Define Varibles
#include <iostream>
using namespace std;

class StopWatch
{
	// Define Time Varibles
	int secs = 0; // Seconds
	int mins = 0; // Minutes
	int hours = 0; // Hours
	std::time_t startTime;

	// Code Start Time
public:
	StopWatch()
	{
		startTime = std::time(nullptr);
	}

	void printDiffTime()
	{
		std::time_t captureTime = std::time(nullptr);

		// Calculating Time
		int timeStamp = std::difftime(captureTime, startTime);

		// Modulus 60 Caps of Seconds Itervals
		secs = timeStamp % 60; // EX: "50158s" is a random number for example [result from difftime] -> 50158 % 60 = 58s
		hours = timeStamp / 3600; // 50158 / 3600 [aka 1hr in seconds] = 13h
		mins = (timeStamp - (hours * 3600) - secs) / 60; //(50158 - (13h * ((60 * 60)) - 58s)/60 = 55m

		// Printing Out Total Time
		// Output Layout - ( Hours : Minutes : Seconds )

		cout << "Hrs: " << hours << " Mins: " << mins << " Secs: " << secs << "\n" << endl;;
	}


};
#endif