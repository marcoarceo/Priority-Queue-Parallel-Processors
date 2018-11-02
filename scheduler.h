#pragma once
#include "minHeap.h"

class scheduler
{
	public:
		scheduler(int processor);
		~scheduler();

		//void tick(string jobDescription, int nProcs, int nTicks);
		bool tick(job temp, bool FNE);

private:
	minHeap program;
};
