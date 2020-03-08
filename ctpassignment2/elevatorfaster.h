#ifndef ELEVATOR_H
#define ELEVATOR_H
class elevatorfaster{
	public: 
	unsigned int Totalfloors, numberofPersons; 
	unsigned int timeBtnfloor; unsigned int startLoc; unsigned int nofElevator;
	
	public: 
	void randomNumberGen(int numberOfrequests[]);
	void randomNumberGenSort(int numberOfrequests[]);
	void randomNumberGenSlow(int numberOfrequests[]);
	void processRequests(int requests[],int timeBtnfloor, int startLoc);
	void processRequestSort(int requests[],int timeBtnfloor, int startLoc);
	void processRequestSlow(int requests[],int timeBtnfloor, int startLoc);
	void printrequests(int arr[]);
};
	
#endif