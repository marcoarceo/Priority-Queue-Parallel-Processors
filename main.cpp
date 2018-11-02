#include "testDriver.h"



job parse(string input) {
	int temp = 0, counter = 0;
	string temp1 = "", temp2 = "";
	job ret;

	temp1 = input;
	if (input[counter] == ',') {
		ret.setjobDescription("");
	}
	else {
		temp1 = "";
		while (input[counter] != ',') {
			temp1 = temp1 + input[counter];
			counter++;
		}
		ret.setjobDescription(temp1);
	}
	counter++;
	temp1 = "";
	while (input[counter] != ',') {
		temp1 = temp1 + input[counter];
		counter++;
	}
	counter++;
	ret.setnProcs(stoi(temp1));
	temp1 = "";
	for (counter = counter; counter < input.length(); counter++) {
		temp1 = temp1 + input[counter];
	}
	ret.setnTicks(stoi(temp1));

	return ret;

}


int main()
{
	testDriver app;
	//app.runProgram(); // Reads all the lines of code at once
	app.runApp(); // Reads one line of code per tick
	
	return 0;
}