#include <iostream>
#include<cstdlib>
using namespace std;
 
/* The total number of floors.
• The size of the elevator(number of people).
• The time it takes to move between two floors. 
• The initial location of the elevator.*/
class elevatorfaster{
	public: 
	int Totalfloors, numberofPersons; 
	int timeBtnfloor; int startLoc;
	public: 
	void randomNumberGen(int numberOfrequests[])
	{
		cout<<"enter no of floors in the building"<<endl;
		cin>>Totalfloors;
		cout<<"enter no of persons going to use the lift"<<endl;
		cin>>numberofPersons;
		cout<<"Time taken between each floor :"<<endl;
		cin>>timeBtnfloor;
		//timeBtnfloor= 2;
		cout<<"enter starting location of the elevator :"<<endl;
		cin>>startLoc;
		//startLoc=1;
		cout<<"the order of requests received:"<<endl;
		if(startLoc<Totalfloors){
		for (int i = 0; i < numberofPersons; i++ ) 
		{
		 numberOfrequests[i] = rand() % Totalfloors + 1;
		 cout<< numberOfrequests[i]<<endl;
		}
		
		// sorting the requests
		int key, j; 
		for (int i = 1; i <numberofPersons; i++) 
       { 
       key = numberOfrequests[i]; 
       j = i-1; 
  
       
       while (j >= 0 && numberOfrequests[j] > key) 
       { 
           numberOfrequests[j+1] = numberOfrequests[j]; 
           j = j-1; 
       } 
       numberOfrequests[j+1] = key;
            
         } 
		 printrequests(numberOfrequests);
	processRequests(numberOfrequests, timeBtnfloor, startLoc);
		}
		else{
			
			cout<<"You have entered the wrong start location"; 
		}
	   //void sortRequests(numberOfrequests);
	}
	/*void sortRequests(int numberOfrequests[]){
		
		int i, key, j; 
   for (i = 1; i < numberofPersons; i++) 
   { 
       key = numberOfrequests[i]; 
       j = i-1; 
  
       
       while (j >= 0 && numberOfrequests[j] > key) 
       { 
           numberOfrequests[j+1] = numberOfrequests[j]; 
           j = j-1; 
       } 
       numberOfrequests[j+1] = key; 
   } 
		
	}*/
	
	
	void processRequests(int requests[],int timeBtnfloor, int startLoc)
	{
		//int requests[numberofPersons];
		//timeBtnfloor= 2;
		 int timeBtnEachFloor;
		 int totaltimetaken=0;
		//startLoc =rand() % Totalfloors + 1;
		int mid=numberofPersons/2;
			if(startLoc<requests[mid])
			{
				
		for(int i=0;i<numberofPersons;i++)
		{
			
			cout<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			//cout<<"elevetor moved to"<<""<<requests[i]<<"position from "<<startLoc<<endl;
			timeBtnEachFloor=abs(timeBtnfloor*(requests[i]-startLoc));
			totaltimetaken=totaltimetaken+timeBtnEachFloor;
			cout<<"time taken by elevator"<<timeBtnEachFloor<<endl;
			startLoc=requests[i];
			
	       
	    }
			}
			else
			{
				for(int i=(numberofPersons-1);i>0;i--)
				{
					cout<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			       timeBtnEachFloor=abs(timeBtnfloor*(requests[i]-startLoc));
			        totaltimetaken=totaltimetaken+timeBtnEachFloor;
			       cout<<"time taken by elevator"<<timeBtnEachFloor<<endl;
			        startLoc=requests[i];
					
				}
			}
		cout<<"the total time taken to process all the requests is :"<<totaltimetaken;
	}
	void printrequests(int arr[])
	{
		cout<<"The order in which they will be processed :"<<endl;
		for(int i=0;i<numberofPersons;i++)
		{
			cout<<arr[i]<<endl;
		}
	}
	
};
    
		
int main(){
	
	 elevatorfaster e1;
	 int numberofPersons=e1.numberofPersons;
	 //int Totalfloors= 20;
	 //int timeBtnfloor; int startLoc; 
	 int arrayrequests[numberofPersons];
	  e1.randomNumberGen(arrayrequests);
	
	
	return 0;
	}
	