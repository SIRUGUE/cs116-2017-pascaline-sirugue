#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.hpp"

class Neuron; 

class Network {
	
private: 

Neuron neuron1;
Neuron neuron2;
double clock; 
double H; 

public: 
Network (Neuron n1, Neuron n2, double t, double h);
void setTime(double t); 
void simulationloop1(double tmin, double tmax, double i);
void simulationloop2(double tmin, double tmax, double i);
~Network(); 

} ;

#endif
