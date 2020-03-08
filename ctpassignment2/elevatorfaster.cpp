#include <iostream>
#include<cstdlib>
#include "elevatorfaster.h"
#include <fstream>
using namespace std;

 

	
	void elevatorfaster:: randomNumberGen(int numberOfrequests[])
	
	//elevator random number generation and sorting algorithm to process requests at a faster pace
	//insertion sort is employed here
	// processRequests is called here and the elevator is abvle to process all the requests basing on its initial position.
	{
		ofstream ofile;
		ofile.open("outputfile.txt",ios::out | ios::app);
		if(!ofile)
    {
      cout<<"Error in creating file.."<<endl;
      return ;
    }
		cout<<"This is the fast one!"<<endl;                             
		ofile<<"This is the fast one!\n";
		//startLoc=1;
		//cout<<"enter starting location of the elevator :"<<endl;
		//cin>>nofElevator;
		cout<<"the order of requests received:\n"<<endl;
		ofile<<"the order of requests received:\n"<<endl;
		if(startLoc<=Totalfloors){
		for (int i = 0; i < numberofPersons; i++ ) 
		{
		 numberOfrequests[i] = rand() % Totalfloors + 1;
		// numberOfrequestsdest[i] = rand() % Totalfloors + 1;

		 
		 cout<< numberOfrequests[i]<<endl;
		 ofile<<numberOfrequests[i]<<endl;
		 //cout<< numberOfrequestsdest[i]<<endl;
		}
		ofile.close();
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
	void elevatorfaster::randomNumberGenSort(int numberOfrequests[])
	{
	//elevator random number generation and sorting algorithm to process requests at a faster pace
	//insertion sort is employed here
	//processRequestSort is called here
			ofstream ofile;
	ofile.open("outputfile.txt",ios::out | ios::app);
		if(!ofile)
    {
      cout<<"Error in creating file.."<<endl;
      return ;
    }
		cout<<"This is a bit slower one!"<<endl;
		ofile<<"This is a bit slower one!\n";
		cout<<"the order of requests received:"<<endl;
		ofile<<"the order of requests received:!\n";
		if(startLoc<=Totalfloors){
		for (int i = 0; i < numberofPersons; i++ ) 
		{
		 numberOfrequests[i] = rand() % Totalfloors + 1;
		 cout<< numberOfrequests[i]<<endl;
		  ofile<<numberOfrequests[i]<<endl;
		}
		ofile.close();
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
	processRequestSort(numberOfrequests, timeBtnfloor, startLoc);
		}
		else{
			
			cout<<"You have entered the wrong start location"; 
		}
	//void sortRequests(numberOfrequests);
	}
	
	void elevatorfaster::randomNumberGenSlow(int numberOfrequests[])
	//simple algorith to generate requests randomly and serve then on first come first serve basis
	//processRequestSlow is called here
	{
			ofstream ofile;
		ofile.open("outputfile.txt",ios::out | ios::app);
		if(!ofile)
    {
      cout<<"Error in creating file.."<<endl;
      return ;
    }
		cout<<"This is the slowest one!"<<endl;
		ofile<<"This is the slowest one!\n";
		if(startLoc<=Totalfloors){
		cout<<"the order of requests received:"<<endl;
		ofile<<"the order of requests received:\n";
		for (int i = 0; i < numberofPersons; i++ ) 
		{
		 numberOfrequests[i] = rand() % Totalfloors + 1;
		 cout<< numberOfrequests[i]<<endl;
		  ofile<<numberOfrequests[i]<<endl;  
		}
		
		ofile.close();
	processRequestSlow(numberOfrequests, timeBtnfloor, startLoc);
		}
		else{
			cout<<"You have entered the wrong start location"; 
		}
	}
    //***********************************************************************************************************************************
    //processing the requeats generated above happens here in three different methods for three different algorithms	
	void elevatorfaster::processRequests(int requests[],int timeBtnfloor, int startLoc)
	{
		ofstream ofile;
		ofile.open("outputfile.txt",ios::out | ios::app);
		if(!ofile)
    {
      cout<<"Error in creating file.."<<endl;
      return ;
    }
		 //int requests[numberofPersons];
		//timeBtnfloor= 2;
		 int timeBtnEachFloor;
		 int totaltimetaken=0;
		//startLoc =rand() % Totalfloors + 1;
		
		// Taking a mid value and comparing it with the elevator intial startlocation
		int mid=numberofPersons/2;
			if(startLoc<requests[mid])
			{
				
		for(int i=0;i<numberofPersons;i++)
		{
			
			cout<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			ofile<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			//cout<<"elevetor moved to"<<""<<requests[i]<<"position from "<<startLoc<<endl;
			timeBtnEachFloor=abs(timeBtnfloor*(requests[i]-startLoc));
			totaltimetaken=totaltimetaken+timeBtnEachFloor;
			cout<<"time taken by elevator : "<<timeBtnEachFloor<<endl;
			ofile<<"time taken by elevator : "<<timeBtnEachFloor<<endl;
			startLoc=requests[i];
			
	       
	    }
			}
			else
			{
				for(int i=(numberofPersons-1);i>0;i--)
				{
					cout<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
					ofile<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			       timeBtnEachFloor=abs(timeBtnfloor*(requests[i]-startLoc));
			        totaltimetaken=totaltimetaken+timeBtnEachFloor;
			       cout<<"time taken by elevator : "<<timeBtnEachFloor<<endl;
				   ofile<<"time taken by elevator : "<<timeBtnEachFloor<<endl;
			        startLoc=requests[i];
					
				}
			}
		cout<<"the total time taken to process all the requests is :"<<totaltimetaken<<endl;
		ofile<<"the total time taken to process all the requests is :"<<totaltimetaken<<endl;
		ofile.close();
	}
	void elevatorfaster:: processRequestSort(int requests[],int timeBtnfloor, int startLoc)
	{
		ofstream ofile;
		ofile.open("outputfile.txt",ios::out | ios::app);
		if(!ofile)
    {
      cout<<"Error in creating file.."<<endl;
      return ;
    }
		//int requests[numberofPersons];
		//timeBtnfloor= 2;
		 int timeBtnEachFloor;
		 int totaltimetaken=0;
		//startLoc =rand() % Totalfloors + 1;
		
		for(int i=0;i<numberofPersons;i++)
		{
				cout<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			ofile<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			timeBtnEachFloor=abs(timeBtnfloor*(requests[i]-startLoc));
			totaltimetaken=totaltimetaken+timeBtnEachFloor;
			cout<<"time taken by elevator : "<<timeBtnEachFloor<<endl;
			ofile<<"time taken by elevator : "<<timeBtnEachFloor<<endl;
			startLoc=requests[i];
			
	       
	    }
		cout<<"the total time taken to process all the requests is :"<<totaltimetaken<<endl;
		ofile<<"the total time taken to process all the requests is :"<<totaltimetaken<<endl;
		ofile.close();
	}
	void elevatorfaster::processRequestSlow(int requests[],int timeBtnfloor, int startLoc)
	{
		
		ofstream ofile;
		ofile.open("outputfile.txt",ios::out | ios::app);
		if(!ofile)
    {
      cout<<"Error in creating file.."<<endl;
      return ;
    }
	//int requests[numberofPersons];
		//timeBtnfloor= 2;
		 int timeBtnEachFloor;
		 int totaltimetaken=0;
		//startLoc =rand() % Totalfloors + 1;
		
		for(int i=0;i<numberofPersons;i++)
		{
			cout<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			ofile<<"elevetor moved  from "<<""<<startLoc<<" -----> "<<requests[i]<<endl;
			timeBtnEachFloor=abs(timeBtnfloor*(requests[i]-startLoc));
			totaltimetaken=totaltimetaken+timeBtnEachFloor;
			cout<<"time taken by elevator : "<<timeBtnEachFloor<<endl;
			ofile<<"time taken by elevator : "<<timeBtnEachFloor<<endl;
			startLoc=requests[i];
			
	       
	    }
		cout<<"the total time taken to process all the requests is :"<<totaltimetaken;
		ofile<<"the total time taken to process all the requests is :"<<totaltimetaken<<endl;
		ofile.close();
	}
	
	//*************************************************************************************************************
	//Printing the order in which the requests will be processed.
	void elevatorfaster:: printrequests(int arr[])
	{
		ofstream ofile;
		ofile.open("outputfile.txt",ios::out | ios::app);
		if(!ofile)
    {
      cout<<"Error in creating file.."<<endl;
      return ;
    }
		cout<<"The order in which they will be processed :"<<endl;
		ofile<<"The order in which they will be processed :"<<endl;
		for(int i=0;i<numberofPersons;i++)
		{
			cout<<arr[i]<<endl;
			ofile<<arr[i]<<endl;
		}
		ofile.close();
	}
	

     

	