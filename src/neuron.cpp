#include <iostream>
#include <cmath>
#include "neuron.hpp"

using namespace std; 

Neuron:: Neuron (double MP=0.0, int NS=0, double TS=0.0, double C=1) 
         : MembranePotential(MP), NbSpikes(NS), TimeSpikes(TS), c(C) { } 
         
double Neuron:: getMembranePotential() const {
	return MembranePotential; 
     }

int Neuron:: getNbSpikes() const {
	return NbSpikes; 
     }

double Neuron:: getTimeSpikes() const {
	return TimeSpikes; 
     }

void Neuron:: updateMembranePotential(double h, double Iext, double Taw){
	MembranePotential = exp(-h/Taw)*MembranePotential +Iext*(Taw/c)*(1-exp(-h/Taw));
    }

void Neuron:: setMembranePotential(double MB){
	MembranePotential = MB; 
    }
    
void Neuron:: setNbSpikes(int NS){
	NbSpikes = NS; 
    }
    
void Neuron:: setTimeSpikes (double TS){
	TimeSpikes = TS; 
    }

Neuron:: ~Neuron() {
    }
     

 
