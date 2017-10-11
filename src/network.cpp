#include <iostream>
#include "network.hpp"

using namespace std; 

//constructor//
Network :: Network (Neuron n1, Neuron n2, double t) 
          :  neuron1 (n1), neuron2 (n2), time(t) { } 

void Network :: setTime(double t) { 
	time=t ;
	} 
          
void Network :: connexionNeurons (double tmin, double tmax, double i) {
	time=tmin;
	while (time<tmax){
	neuron1.updateNeuron(tmin, tmax, i);	  
	if (neuron1.IsSpiking()) { 
		neuron2.setMembranePotential(neuron2.getMembranePotential()+neuron1.getJ());
		} 
	neuron2.updateNeuron(tmin,tmax, i);
	if (neuron2.IsSpiking()) {
		neuron1.setMembranePotential(neuron1.getMembranePotential()+neuron2.getJ());
		 } 	
	time = time + neuron1.geth() ;
		  } 
 }
         
//Destructor//
Network :: ~Network()   {
	 } 
          
