#include <iostream>
#include <fstream>
#include "neuron.hpp"
#include "network.hpp"

using namespace std;

int main ()

{

Network network (neuron1, neuron2, 0.0, 0.1);
double tmin; 
double tmax; 
double i;




cout << "entrez le temps minimal"<< endl; 
cin>> tmin;
cout << "entrez le temps maximal" <<endl;
cin>> tmax;
cout << "entrez le courant extérieur" <<endl;
cin>> i;


//neuron1.setTimeSpikes(tmin);// // TEST PREMIERE PARIE //
//neuron1.updateNeuron(tmin, tmax, i);//

neuron1.setTimeSpikes(tmin);
neuron2.setTimeSpikes(tmin);

network.simulationloop2 (tmin, tmax, i) ;



return 0;
} 
