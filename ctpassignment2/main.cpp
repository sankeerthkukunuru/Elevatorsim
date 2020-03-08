#include <iostream>
#include<cstdlib>
#include "elevatorfaster.h"	
#include <fstream>
using namespace std;

	/* The total number of floors.
• The size of the elevator(number of people).
• The time it takes to move between two floors. 
• The initial location of the elevator.*/

int main(){
	
	unsigned int Totalfloors, numberofPersons; 
	unsigned int timeBtnfloor; unsigned int startLoc; unsigned int nofElevator;
	ofstream ofile;
	ofile.open("outputfile.txt",ios::app);
    if(!ofile)
    {
      cout<<"Error in creating file.."<<endl;
      return 0;
    }
    cout<<"\nFile created successfully."<<endl;
	
	    cout<<"enter no of floors in the building"<<endl;
		cin>>Totalfloors;
		cout<<"enter max no of persons going to use a single lift"<<endl;
		cin>>numberofPersons;
		cout<<"Time taken between each floor :"<<endl;
		cin>>timeBtnfloor;
		//timeBtnfloor= 2;
		cout<<"enter starting location of the elevators :"<<endl;
		cin>>startLoc;
		cout<<"enter the number of available elevators :"<<endl;
		 cin>>nofElevator; 
		ofile<<"Totalfloors : "<<Totalfloors<<" "<<endl;
		ofile<<"numberofPersons : "<<numberofPersons<<" "<<endl;
		ofile<<"timeBtnfloor : "<<timeBtnfloor<<" "<<endl;
		ofile<<"startLoc : "<<startLoc<<" "<<endl;
		ofile<<"nofElevator : "<<nofElevator<<" "<<endl;
		//int randomalg[nofElevator];
		if(Totalfloors!=0 && numberofPersons!=0 && timeBtnfloor!=0){
		
       int arrayrequests[numberofPersons];
	   // creating objects and allocating space dynamically
      // elevatorfaster **e = new elevatorfaster*[nofElevator];
 //elevatorfaster e[nofElevator];
    /* for(int i = 0; i < nofElevator; i += 1) 
	 {
	
	// calling all the methods randomly for each elevator
          e[i] = new elevatorfaster();
		  e[i]->numberofPersons=numberofPersons;
		e[i]->Totalfloors=Totalfloors;
		e[i]->timeBtnfloor=timeBtnfloor;
		e[i]->startLoc =startLoc;
		int random =rand()%3+1;
		if(random==1){
			cout<< "elevator : "<<i+1<<" #####################################"<<endl;
			ofile<< "elevator : "<<i+1<<" #####################################"<<endl;
			 e[i]->randomNumberGen(arrayrequests);
		}
		if(random ==2){
			cout<< "elevator : "<<i+1<<" #####################################"<<endl;
			ofile<< "elevator : "<<i+1<<" #####################################"<<endl;
			 e[i]->randomNumberGenSlow(arrayrequests);
		}
	 if(random==3){
		 cout<< "elevator : "<<i+1<<" #####################################"<<endl;
		  ofile<< "elevator : "<<i+1<<" #####################################"<<endl;
		 e[i]->randomNumberGenSort(arrayrequests);
	 }
      }*/
	  for(int i = 0; i < nofElevator; i += 1) 
	 {
	
	// calling all the methods randomly for each elevator
         // e[i] = new elevatorfaster();
		  e[i].numberofPersons=numberofPersons;
		e[i].Totalfloors=Totalfloors;
		e[i].timeBtnfloor=timeBtnfloor;
		e[i].startLoc =startLoc;
		int random =rand()%3+1;
		if(random==1){
			cout<< "elevator : "<<i+1<<" #####################################"<<endl;
			ofile<< "elevator : "<<i+1<<" #####################################"<<endl;
			 e[i].randomNumberGen(arrayrequests);
  		}
		if(random ==2){
			cout<< "elevator : "<<i+1<<" #####################################"<<endl;
			ofile<< "elevator : "<<i+1<<" #####################################"<<endl;
			 e[i].randomNumberGenSlow(arrayrequests);
		}
	 if(random==3){
		 cout<< "elevator : "<<i+1<<" #####################################"<<endl;
		  ofile<< "elevator : "<<i+1<<" #####################################"<<endl;
		 e[i].randomNumberGenSort(arrayrequests);
	 }
      }
		}
		else{
			cout<<"Wrong parameters!"<<endl;
		}
	ofile.close();
	return 0;
	}