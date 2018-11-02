#pragma once
#include "job.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

class minHeap
{

	public:
		minHeap();
		minHeap(int processor);
		~minHeap();

		bool insertJob(string jobDescription, int nProcs, int nTicks); // Inserts the job to waitQueue
		job findShortest(); // Finds the shortest job in the wait queue
		bool checkAvailability(int nProcs); // Checks if there are processors available
		void deleteShortest(); // Deletes the shortest job in the wait queue
		bool runJob(int ID, string jobDescription, int nProcs, int nTicks); // Removes processor from freePool and adds job to running queue
		void DecrementTimer(); // Decrements the ticks by 1
		void releaseProcs(); // Releases the processors back into the freePool
		void updateID(); // Updates the ID by 1
		void printwaitQueue(); // Prints the wait queue
		void printrunningQueue(); // Prints the running queue
		void totalfreePool(); // Prints the total processors in the freePool

		bool Wait_isEmpty();
		bool Run_isEmpty();
		bool load_RunQueue();
		bool runJobV2(job in);
		void setprocessors(int proc);

	private:
		priority_queue<job> waitQueue; // Priority Queue
		vector<job> runningJob; // Vector for the running queue
		int p; // processors
		int ID; // Unique ID
		int freePool; // Processors available
};