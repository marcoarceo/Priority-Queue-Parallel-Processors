#include "scheduler.h"

scheduler::scheduler(int processor)
{
	program.setprocessors(processor);
}

scheduler::~scheduler()
{

}

//void scheduler::tick(string jobDescription, int nProcs, int nTicks)
bool scheduler::tick(job temp, bool FNE)
{
	if (FNE)
	{
		program.insertJob(temp.getjobDescription(), temp.getnProcs(), temp.getnTicks());
	}

	// If statements according to the image on page 10
	cout << "-------------------------------------------------------" << endl;
	if (!program.Wait_isEmpty())
	program.printwaitQueue();

	//cout << endl;

	if (!program.Wait_isEmpty() || !program.Run_isEmpty()) {
		program.totalfreePool();
		program.load_RunQueue();
	
		if (!program.Run_isEmpty()) {
			program.printrunningQueue();
			program.DecrementTimer();
			program.releaseProcs();
		}

		cout << "-------------------------------------------------------" << endl << endl;
		//cout << endl;

	}
	else {
		cout << "all Jobs done" << endl;
		return 1;
	}
	return 0;

}