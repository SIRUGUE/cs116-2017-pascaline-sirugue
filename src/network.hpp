#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.hpp"

class Neuron; 

class Network {
	
private: 

Neuron neuron1;
Neuron neuron2;
double time;  

public: 
Network (Neuron n1, Neuron n2, double t);
void setTime(double t); 
void connexionNeurons(double tmin, double tmax, double i);
~Network(); 

} ;

#endif
