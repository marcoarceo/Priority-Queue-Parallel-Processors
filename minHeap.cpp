#include "minHeap.h"

minHeap::minHeap()
{
	this->ID = 1;
	this->p = 0;
	this->freePool = p;
}

minHeap::minHeap(int processor)
{
	this->p = processor;
	this->ID = 1;
	this->freePool = p;
}

minHeap::~minHeap()
{

}

bool minHeap::insertJob(string jobDescription, int nProcs, int nTicks)
{
	bool flag = true;

	if ((0 < nProcs && nProcs <= p) && nTicks > 0 && jobDescription!="") //Checks the conditions necessary to insert into the wait queue
	{
		waitQueue.push(job(ID, jobDescription, nProcs, nTicks)); // Inserts the job into the priority queue
		updateID(); // Updates the ID for it to be unique
		flag = true; // Sets the flag to be true
	}
	else
	{
		cout << "The following job " << jobDescription << " produced an error and can not be inserted... " << endl << endl;
		flag = false; // Sets the flag to be false;
	}
	return flag; // Returns the flag
}

void minHeap::updateID()
{
	this->ID += 1; // Updates the ID by 1
}

job minHeap::findShortest()
{
	if (!waitQueue.empty()) // Checks to make sure that the waitQueue is not empty
	{
		return waitQueue.top(); // Returns the top of the queue
	}
	else
	{
		cout << "There was an error finding the shortest job... " << endl; // Produces error message
	}
}

bool minHeap::checkAvailability(int nProcs)
{
	bool flag = false; // Creates a flag

	if (freePool >= nProcs) // Checks that the free pool is bigger than or equal to the processors
	{
		flag = true; // Sets the flag to true
	}
	else
	{
		flag = false; // Not enough free pool, flag is false
	}
	return flag; // Returns the flag
}

void minHeap::deleteShortest()
{
	if (!waitQueue.empty()) // Checks to make sure that the waitQueue is not empty
	{
		waitQueue.pop(); // Removes the shortest job
	}
	else 
	{
		cout << "There was an error deleting the shortest job... " << endl; // Produces error message
	}
}

bool minHeap::runJob(int ID, string jobDescription, int nProcs, int nTicks)
{
	if (checkAvailability(nProcs) == true) // Makes sure that there are processors available
	{
		this->freePool -= nProcs; // Removes processors from the free pool
		runningJob.push_back(job(ID, jobDescription, nProcs, nTicks)); // Adds the job into the running job queue
		cout << "Processors available: " << freePool << endl; // Prints a message showing how many processors are left
		return 1;
	}
	else
	{
		// Displays an error message for lack of free processors
		cout << "There was not enough processors available in the freepool to run " << jobDescription << endl << endl;
		return 0;
	}
}

void minHeap::DecrementTimer()
{
	if (!runningJob.empty()) // Checks to make sure that the running job queue is not empty
	{
		vector<job>::iterator temp = runningJob.begin(); // Creates an iterator for the running queue
		do
		{
			temp->tickReduction(); // Removes 1 tick from the job
			cout <<temp->getjobDescription()<< " Time left: " << temp->getnTicks() << endl; // Prints the amount of ticks left
			temp++;
		} while (temp != runningJob.end()); // Condition for the loop
		cout << endl;
	}
	else 
	{
		cout << "The running job queue is empty... " << endl;
	}
}

void minHeap::releaseProcs()
{
	int counter = 0;
	vector<job>::iterator temp = runningJob.begin(); // Creates an iterator for the running queue'

	vector<int> place;
	int place_hold=0;
	
	int size = 0;
	bool remove = 0;
	do
	{
		if (temp->getnTicks() > 0) // Checks if the job has 0 ticks
		{
			temp++;
			counter++;
		}
		else // if it does, then we send the processors back to the freePool
		{
			freePool += temp->getnProcs();
			
			
			place.push_back(counter);
			
			//cout << endl << "Available processors: " << freePool << endl; // Display the new amount of processors available
			
			temp++;
			remove = 1;
		}
	} while (temp != runningJob.end()); // Condition for the loop

	if (remove) {
		for (int i = place.size() - 1; i > 0; i--) {
			cout << endl << "Removing job " << runningJob[place[i]].getjobDescription() << endl;
			runningJob.erase(runningJob.begin() + place[i]);
			
		}
		cout << "Removing job " << runningJob[place[0]].getjobDescription() << endl;
		runningJob.erase(runningJob.begin() + place[0]);
	}
	cout << "Available processors: " << freePool << endl;
}

void minHeap::printwaitQueue()
{
	priority_queue<job> temp = waitQueue; // Creates a temporary priority queue with the waitQueue contents
	cout << "Wait Queue:" << endl;
	while (!temp.empty()) // Checks that the temp is not empty
	{
		cout << "Job: " << temp.top().getjobDescription() << " " << "Processors: " << temp.top().getnProcs() << " " << "Ticks: " << temp.top().getnTicks() << endl;
		temp.pop(); // Removes the top job
	}
}

void minHeap::printrunningQueue()
{
	vector<job>::iterator temp = runningJob.begin(); // Creates a temporary vector with the running queue contents

	cout << "Running Queue:" << endl;
	do
	{
		cout << "Job: " << temp->getjobDescription() << " " << "Processors: " << temp->getnProcs() << " " << "Ticks: " << temp->getnTicks() << endl;
		temp++;
	} while (temp != runningJob.end()); // Condition for the loop
}

void minHeap::totalfreePool() // Displays the amount of processors in the free pool
{
	cout << "Total free pool: " << freePool << endl << endl;
}


bool minHeap::Wait_isEmpty() {

	return this->waitQueue.empty();
}

bool minHeap::Run_isEmpty() {
	return this->runningJob.empty();
}


bool minHeap::load_RunQueue() {

	while (!Wait_isEmpty() && runJobV2(waitQueue.top())) {
		waitQueue.pop();
	}
	return 1;
}

bool minHeap::runJobV2(job in) {
	if (checkAvailability(in.getnProcs()) == true) // Makes sure that there are processors available
	{
		this->freePool -= in.getnProcs(); // Removes processors from the free pool
		runningJob.push_back(in); // Adds the job into the running job queue
		cout << "Processors available: " << freePool << endl << endl; // Prints a message showing how many processors are left
		return 1;
	}
	else
	{
		// Displays an error message for lack of free processors
		cout << endl << "There was not enough processors available in the freepool for " << in.getjobDescription() << endl << endl;
		return 0;
	}
}

void minHeap::setprocessors(int proc) {
	this->p = proc;
	this->freePool = p;

}