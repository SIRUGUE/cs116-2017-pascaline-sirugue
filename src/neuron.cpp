#include <iostream>
#include <fstream>
#include <cmath>
#include "neuron.hpp"

using namespace std; 

//CONSTRUCTOR
Neuron:: Neuron (double MP=0.0, int NS=0, double TS=0.0, int TR=0, double j=0.1, double i=0.0, double d=1.5 ) 
         : MembranePotential(MP), NbSpikes(NS), TimeSpikes(TS), TimeRefractory(TR), J(j), Iext (i), delay (d), buffer (16, 0.0) { } 
 
// GETTERS        
double Neuron:: getMembranePotential() const {
	return MembranePotential; 
     }

int Neuron:: getNbSpikes() const {
	return NbSpikes; 
     }

double Neuron:: getTimeSpikes() const {
	return TimeSpikes; 
     }

int Neuron:: getTimeRefractory() const  {
	return TimeRefractory; 
	}
	
double Neuron:: getVreset() const {
	return Vreset; 
	}

double Neuron:: getVthr() const {
	return Vthr; 
	}
	
double Neuron:: getTau() const {
	return tau; 
	}

double Neuron:: geth() const {
	return h; 
	}

double Neuron :: getJ() const {
	return J;
	}

double Neuron :: getDelay() const {
	return delay;
    }
 
// SETTERS   
void Neuron:: setMembranePotential(double MB){
	MembranePotential = MB; 
    }
    
void Neuron:: setNbSpikes(int NS){
	NbSpikes = NS; 
    }
    
void Neuron:: setTimeSpikes (double TS){
	TimeSpikes = TS; 
    }
    
void Neuron:: setTimeRefractory (int TR){
	TimeRefractory = TR; 
    }
 
// UPDATE MEMBRANE POTENTIAL ACCORDING TO FORMULA 
void Neuron:: updateMembranePotential (){
	int n= static_cast<int> (TimeSpikes/h) ;
	int m (n%16) ;
	MembranePotential = exp(-h/tau)*MembranePotential +Iext*(tau/c)*(1-exp(-h/tau)) + buffer [m];
	buffer [m] =0.0 ;
	cout << " m lu " << m << endl;
    }

// WRITE ON THE FILE TIMES SPIKES AND MEMBRANE POTENTIAL
void Neuron :: write() {
	ofstream sortie;
	sortie.open("test.txt", ios::out | ios::app );
	sortie << "time spikes : "<<  TimeSpikes << "  membrane potential " << MembranePotential<< endl;
	sortie.close(); 
	}
	
// RETURN TRUE IF NEURON IS SPIKING 
bool Neuron :: IsSpiking() {
	if (MembranePotential > Vthr) {
		return true ;
	}
}

// UPDATE NEURON BETWEN TMIN AND TMAX
void Neuron :: updateNeuron (double tmin, double tmax, double i) {
Iext=i; 

	    if (TimeRefractory>0) {
	    TimeRefractory=TimeRefractory-1 ;
	    MembranePotential=Vreset;
	    }
	    
	     else       {
			 updateMembranePotential();
             if(MembranePotential>Vthr)  {
	          write ();
	          TimeRefractory = 20; 
	          NbSpikes=NbSpikes+1;
	          }
	      }
 
TimeSpikes +=h ;
      
}

//ADD J AT THE POSITION I OF THE BUFFER
void Neuron :: addJ(int i,double j) { 
	buffer[i] += j ;
	}

//DESTRUCTOR
Neuron:: ~Neuron() {
    }
     

 
