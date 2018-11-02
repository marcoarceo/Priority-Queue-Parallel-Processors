#include "testDriver.h"

void testDriver::runProgram()
{
	minHeap program(25);
	fstream infile;
	job temp;
	string input = "";
	infile.open("inputV2.txt");
	
	 {
		while (infile >> input) {

		
			temp = parse(input);
			program.insertJob(temp.getjobDescription(), temp.getnProcs(), temp.getnTicks());
		}
		program.printwaitQueue();

		cout << endl;

		cout << endl;
		while (!program.Wait_isEmpty() || !program.Run_isEmpty()) {
	
			program.totalfreePool();
			program.load_RunQueue();
			program.printrunningQueue();
			program.DecrementTimer();
			program.releaseProcs();


			cout << endl;
		}
	}
	cout << "all Jobs done"<<endl<<endl;
}

void testDriver::runApp() {
	scheduler app(25);
	job temp;
	fstream infile;
	bool file_not_empty = 1;
	string input = ",0,0";
	infile.open("inputV2.txt");
	int count = 1;

	infile >> input;
	temp = parse(input);
	while (!app.tick(temp, file_not_empty) || file_not_empty) 
	{
		cout << "Total Counter: " << count << endl;
		count++;
		temp.setjobDescription("");
		if (infile >> input) 
		{
			temp = parse(input);
		}
		else 
		{
			file_not_empty = 0;
		}

	}
	cout << "Total Ticks were: " << count << endl << endl;
}