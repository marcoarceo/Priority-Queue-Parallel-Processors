#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class job
{
	public:
		job(int ID, string Description, int Procs, int Ticks); // Constructs the job
		job();
		int getjobID() const; // returns the job ID
		string getjobDescription() const; // returns the job description
		int getnProcs() const; // returns the number of processors
		int getnTicks() const; // returns the number of ticks

		void setjobID(int ID); // sets the job ID
		void setjobDescription(string Description); // sets the job description
		void setnProcs(int Procs); // sets the number of processors
		void setnTicks(int Ticks); // sets the number of ticks

		void tickReduction(); // reduces the tick by 1

		bool operator< (const job &a) const { return (a.nTicks < nTicks); } // Used for inserting into the wait queue

	private:

		int jobID;
		string jobDescription;
		int nProcs;
		int nTicks;
};


job parse(string input);