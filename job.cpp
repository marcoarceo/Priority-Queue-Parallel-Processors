#include "job.h"

job::job(int ID, string Description, int Procs, int Ticks)
{
	setjobID(ID);
	setjobDescription(Description);
	setnProcs(Procs);
	setnTicks(Ticks);
}

int job::getjobID() const
{
	return this->jobID;
}

string job::getjobDescription() const
{
	return this->jobDescription;
}

int job::getnProcs() const
{
	return this->nProcs;
}

int job::getnTicks() const
{
	return this->nTicks;
}

void job::setjobID(int ID)
{
	this->jobID = ID;
}

void job::setjobDescription(string Description)
{
	this->jobDescription = Description;
}

void job::setnProcs(int Procs)
{
	this->nProcs = Procs;
}

void job::setnTicks(int Ticks)
{
	this->nTicks = Ticks;
}

void job::tickReduction()
{
	this->nTicks--;
}

job::job() {
	this->jobID = 0;
	this->jobDescription = "";
	this->nProcs = 0;
	this->nTicks = 0;

}