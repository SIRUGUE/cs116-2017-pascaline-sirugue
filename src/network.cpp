#include <iostream>
#include "network.hpp"

using namespace std; 

//constructor//
Network :: Network (Neuron n1, Neuron n2, double t, double h=0.1) 
          :  neuron1 (n1), neuron2 (n2), clock(t), H(h) { } 
          
//setteur//
void Network :: setTime(double t) { 
	clock=t;
	} 
     
//simulation loop without delay //         
void Network :: simulationloop1(double tmin, double tmax, double i) {
	clock=tmin;
	while (clock<tmax){
	neuron1.updateNeuron(tmin, tmax, i);
    if (neuron1.IsSpiking()) { 
		neuron2.setMembranePotential(neuron2.getMembranePotential()+neuron1.getJ());
	} 
    neuron2.updateNeuron(tmin,tmax, i);
	if (neuron2.IsSpiking()) {
		neuron1.setMembranePotential(neuron1.getMembranePotential()+neuron2.getJ());
		 } 	
	cout << "time" << clock << "    neuron 1 " << neuron1.getMembranePotential() << endl;
	cout << "time" << clock << "    neuron 2 " << neuron2.getMembranePotential() << endl;
	clock = clock + neuron1.geth() ;
		  } 
 }

//simulation loop with delay// 
void Network :: simulationloop2(double tmin, double tmax, double i) {
	clock=tmin;
	
	while (clock<tmax){
	int n1 = static_cast<int> ((clock + neuron1.getDelay())/H) ;
	int m1 (n1%16) ;
	int n2 = static_cast<int> ((clock+neuron2.getDelay())/H);
	int m2 (n2%16) ;
	cout <<" m  " << m1 << endl ; 
	 
	
	
	neuron1.updateNeuron(tmin, tmax, i);
    if (neuron1.getMembranePotential()>20) { 
		neuron2.addJ(m1, neuron1.getJ());
	     } 
    neuron2.updateNeuron(tmin,tmax, 0.0);
	if (neuron2.getMembranePotential()>20) {
		neuron1.addJ(m2, neuron2.getJ());
		 } 	
	cout << "time" << clock << "    neuron 1 " << neuron1.getMembranePotential() << endl;
	cout << "time" << clock << "    neuron 2 " << neuron2.getMembranePotential() << endl;
	clock = clock + H ;
		  } 
 }
               
//Destructor//
Network :: ~Network()   {
	 } 
          
